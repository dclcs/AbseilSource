

### using
类型别名  `using value_type = T_`
```c++
using init_type = typename PolicyTraits::init_type;
using key_type = typename PolicyTraits::key_type;
```

### noexpect
-  `noexpect(true)` 保证不会抛出异常
- `noexpect(false)` 可能抛出异常

### explicit
- explicit关键字用来修饰类的构造函数， 被修饰的构造函数的类，不能发生相应的隐式类型转换，只能以显示的方式进行类型转换。 
- explicit 关键字只能用于类内部的构造函数声明上。
- explicit 关键字作用于单个参数的构造函数。
```c++
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
```
上面有一个类Circle，有三个构造函数，有下面三种构造方式
```c++
Circle A = 1.23;
Circle B = 123;
Circle C = A;
```
- 第一种会涉及到隐式类型转换， 这里的tmp不会显示出来
  ```c++
    tmp = Circle(1.23);
    Circle A(tmp);
    tmp.~Circle();
  ```
- 第二种和上面一样，也会隐式转换，调用的是第二个构造函数
- 第三种是这个算隐式调用了拷贝构造函数 

这里如果所有的构造函数加上explicit就会报错

### std::is_class && std::is_empty
- std::is_class
  - 判断T是否是non-union的类型。
- std::is_empty
  - If T is an empty type (that is, a non-union class 
  type with no non-static data members other than bit-fields of size 0, 
  no virtual functions, no virtual base classes, and no non-empty base classes), 
  provides the member constant value equal to true. 
  For any other type, value is false.
  - If T is an incomplete non-union class type, the behavior is undefined.
  - If the program adds specializations for std::is_empty or std::is_empty_v, 
  the behavior is undefined.
- std::is_final
  - If T is a final class, provides the member constant value equal true.
    For any other type, value is false.
  - If T is an incomplete class type, the behavior is undefined.
  - If the program adds specializations for std::is_final 
  or std::is_final_v(since C++17), the behavior is undefined.

- std::is_base_of
  - If Derived is derived from Base or if both are the same non-union class (in both cases ignoring cv-qualification), provides the member constant value equal to true. Otherwise value is false.
  - If both Base and Derived are non-union class types, and they are not the same type (ignoring cv-qualification), Derived should be a complete type; otherwise the behavior is undefined. 
  - If the program adds specializations for std::is_base_of or std::is_base_of_v(since C++17), the behavior is undefined.





