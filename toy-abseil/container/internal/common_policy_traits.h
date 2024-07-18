//
// Created by cl d on 2024/7/18.
//

#ifndef ABSEILSOURCE_COMMON_POLICY_TRAITS_H
#define ABSEILSOURCE_COMMON_POLICY_TRAITS_H

namespace toyabsl {
namespace container_internal{
template<class Policy, class = void>
struct common_policy_traits {};
}
}

#endif //ABSEILSOURCE_COMMON_POLICY_TRAITS_H
