
/**
 * @file forward.cpp
 * @brief Tutorial code for std::forward.
 */

#include <iostream>
#include <utility>

template <typename T>
void print( T& val ) {
    std::cout << "print(T&)\n";
}

template <typename T>
void print( T&& val ) {
    std::cout << "print(T&&)\n";
}

template <typename T>
void temTest( T&& v ) {
    print(v);   // 总是调用 print( T& )
    print(std::forward<T>(v));    // 完美转发
    print(std::move(v));    // 总是调用 print(T&&)
}

int main() {
    std::cout << "======lvalue=========\n";
    int i = 0;
    temTest(i);
    std::cout << "======std::move=========\n";
    temTest(std::move(i));
    std::cout << "======prvalue=========\n";
    temTest(1);
    return 0;
}
