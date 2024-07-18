//
// Created by cl d on 2024/7/18.
//

#include <iostream>

void swap(int x, int y) throw(int) {
    if (x > 10) {
        throw 3;
    } else {
        std::cout << "Can swap x , y" << std::endl;
    }
}


// expect
void swapWithNoexpect(int x, int y) noexcept(true) {
    throw 4;
}

int main() {
    std::cout << "NoexpectCases" << std::endl;
    try {
        swap(3, 5);
    } catch (int someResult) {
        std::cout << someResult << std::endl;
    }
    try {
        swapWithNoexpect(3, 5);
    } catch (int someResult) {
        std::cout << someResult << std::endl;
    }
}