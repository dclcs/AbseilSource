

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
