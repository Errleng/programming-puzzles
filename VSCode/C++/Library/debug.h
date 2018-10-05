#pragma once

#include <iostream>

void print() {}

template <typename T, typename... Types> void print(T var, Types... args) {
    std::cout << var << " ";
    print(args...);
}

void println() { std::cout << std::endl; }

template <typename T, typename... Types> void println(T var, Types... args) {
    std::cout << var << " ";
    println(args...);
}