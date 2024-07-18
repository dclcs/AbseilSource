//
// Created by cl d on 2024/7/18.
//

#include <iostream>

class Circle {
public:
//    explicit
    Circle(double r): R(r) {
        std::cout << "Circle0" << std::endl;
    }

//    explicit
    Circle(int x, int y = 0): X(x), Y(y) {
        std::cout << "Circle1" << std::endl;
    }

//    explicit
    Circle(const Circle& c): R(c.R), X(c.X), Y(c.Y) {
        std::cout << "Circle2" << std::endl;
    }
private:
    double R;
    int X;
    int Y;
};

int main() {
    Circle A = 1.23;
    Circle B = 123;
    Circle C = A;
}