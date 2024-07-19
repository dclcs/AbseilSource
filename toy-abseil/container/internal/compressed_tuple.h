//
// Created by cl d on 2024/7/19.
//

#ifndef ABSEILSOURCE_COMPRESSED_TUPLE_H
#define ABSEILSOURCE_COMPRESSED_TUPLE_H
#include <utility>
#include <initializer_list>
#include <tuple>
#include <utility>
#include <type_traits>
#include "../../utility/utility.h"
namespace toyabsl {
namespace container_internal {

template <typename... Ts>
class CompressedTuple;

namespace internal_compressed_tuple {

struct uses_inheritance {};

template <typename T>
constexpr bool ShouldUseBase() {
    return std::is_class<T>::value && std::is_empty<T>::value &&
           !std::is_final<T>::value &&
           !std::is_base_of<uses_inheritance, T>::value;
}

template <typename T, size_t I, bool  UseBase = ShouldUseBase<T>()>
struct Storage {
    T value;
    constexpr Storage() = default;

    template<typename V>
    explicit constexpr Storage(toyabsl::in_place_t, V&& v)
        : value(std::forward<V>(v)) {}
    constexpr const T& get() const& { return value; }
    constexpr T& get() & { return value; }
    constexpr const T&& get() const&& { return std::move(*this).value; }
    constexpr T&& get() && { return std::move(*this).value; };
};

template <typename T, size_t I>
struct Storage<T, I, true>: T {
    constexpr Storage() = default;

    template <typename V>
    explicit constexpr Storage(toyabsl::in_place_t, V&& v) : T(std::forward<V>(v)) {}

    constexpr const T& get() const& { return *this; }
    constexpr T& get() & { return *this; }
    constexpr const T&& get() const&& { return std::move(*this); }
    constexpr T&& get() && { return std::move(*this); }
};

template <typename D, typename I, bool ShouldAnyUseBase>
struct CompressedTupleImpl;

template <typename... Ts, size_t... I, bool ShouldAnyUseBase>
struct CompressedTupleImpl<
        CompressedTuple<Ts...>, std::index_sequence<I...>, ShouldAnyUseBase>
        : uses_inheritance,
          Storage<Ts, std::integral_constant<size_t, I>::value>...{
    constexpr CompressedTupleImpl() = default;
};

template <typename... Ts, size_t... I>
struct CompressedTupleImpl <
        CompressedTuple<Ts...>, std::index_sequence<I...>, false> {

};


template <typename... Ts>
constexpr bool ShouldAnyBase() {
    return true;
}
}


template <typename... Ts>
class CompressedTuple
        : private internal_compressed_tuple::CompressedTupleImpl<
                CompressedTuple<Ts...>, std::index_sequence_for<Ts...>,
                internal_compressed_tuple::ShouldAnyBase<Ts...>()>{

};

}
}
#endif //ABSEILSOURCE_COMPRESSED_TUPLE_H
