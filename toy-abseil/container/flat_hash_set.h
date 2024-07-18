//
// Created by cl d on 2024/7/18.
//

#ifndef ABSEILSOURCE_FLAT_HASH_SET_H
#define ABSEILSOURCE_FLAT_HASH_SET_H
#include <memory>
#include "internal/raw_hash_set.h"

namespace toyabsl{

namespace container_internal {
template <class T>
struct FlatHashSetPolicy {
    using slot_type = T;
    using key_type = T;
    using init_type = T;
    using constant_interators = std::true_type;


};
}

template <class T, class Hash, class Eq, class Allocator = std::allocator<T>>
class flat_hash_set
        : public toyabsl::container_internal::raw_hash_set<
        toyabsl::container_internal::FlatHashSetPolicy<T>, Hash, Eq, Allocator> {
    using Base = typename flat_hash_set::raw_hash_set;

public:
    flat_hash_set() {}
    using Base::Base;

    using Base::begin;
    using Base::cbegin;

};
}

#endif //ABSEILSOURCE_FLAT_HASH_SET_H
