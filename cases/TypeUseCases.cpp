//
// Created by cl d on 2024/7/19.
//

#include <iostream>
#include <type_traits>

struct A {};

class B {
    static int b;
};

union U { class UC {};};


struct FinalA final {};
struct FinalB final {};

int main() {
    std::cout << std::is_class<A>::value << ": A\n";
    std::cout << std::is_class<B>::value << ": B\n";
    std::cout << std::is_class<U>::value << ": U\n";
    std::cout << "A: " << std::is_empty<A>::value << '\n'; // the result is ABI-dependent
    std::cout << "B: " << std::is_empty<B>::value << '\n'; // the result is ABI-dependent
    std::cout << "U: " << std::is_empty<U>::value << '\n'; // the result is ABI-dependent
    std::cout << "FinalA: " << std::is_final<FinalA>::value << '\n'; // the result is ABI-dependent
    std::cout << "A: " << std::is_final<A>::value << '\n'; // the result is ABI-dependent

    return 0;
}