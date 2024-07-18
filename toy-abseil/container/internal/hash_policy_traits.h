//
// Created by cl d on 2024/7/18.
//

#ifndef ABSEILSOURCE_HASH_POLICY_TRAITS_H
#define ABSEILSOURCE_HASH_POLICY_TRAITS_H

#include "common_policy_traits.h"

namespace toyabsl {
namespace container_internal {
template <class Policy, class = void>
struct hash_policy_traits : common_policy_traits<Policy> {
    using key_type = typename Policy::key_type;
};
}
}



#endif //ABSEILSOURCE_HASH_POLICY_TRAITS_H
