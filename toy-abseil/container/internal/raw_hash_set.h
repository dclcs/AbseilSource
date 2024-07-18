//
// Created by cl d on 2024/7/18.
//

#ifndef ABSEILSOURCE_RAW_HASH_SET_H
#define ABSEILSOURCE_RAW_HASH_SET_H

#include "hash_policy_traits.h"

namespace toyabsl {
namespace container_internal {

template <class Policy, class Hash, class Eq, class Alloc>
class raw_hash_set {
    using PolicyTraits = hash_policy_traits<Policy>;
    //TODO: KeyArgImpl
public:

private:
    constexpr static bool SoonEnabled() {
        return PolicyTraits::soo_enabled();
    }
};
}
}

#endif //ABSEILSOURCE_RAW_HASH_SET_H
