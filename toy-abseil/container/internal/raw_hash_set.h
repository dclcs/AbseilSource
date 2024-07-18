//
// Created by cl d on 2024/7/18.
//

#ifndef ABSEILSOURCE_RAW_HASH_SET_H
#define ABSEILSOURCE_RAW_HASH_SET_H

#include "hash_policy_traits.h"
#include <initializer_list>
#include <cstddef>
#include <type_traits>

namespace toyabsl {
namespace container_internal {

template <class Policy, class Hash, class Eq, class Alloc>
class raw_hash_set {
    using PolicyTraits = hash_policy_traits<Policy>;
    //TODO: KeyArgImpl
public:
    using allocator_type = Alloc;
    using hasher = Hash;
    using key_equal = Eq;
private:
    constexpr static bool SoonEnabled() {
        return PolicyTraits::soo_enabled();
    }


    raw_hash_set() noexcept(
        std::is_nothrow_default_constructible<hasher>::value &&
        std::is_nothrow_default_constructible<key_equal>::value &&
        std::is_nothrow_default_constructible<allocator_type>::value) {}

    explicit raw_hash_set(
            size_t bukect_count, const hasher& hash,
            const key_equal& eq,
            const allocator_type& alloc)
    {

    }
};
}
}

#endif //ABSEILSOURCE_RAW_HASH_SET_H
