#pragma once

#include <chrono>
#include <iostream>

#define SZ(c) (int)(c).size()

static void timing(bool end) {
    const int MICROSECOND_LIMIT = 1000;
    const int MILLISECOND_LIMIT = 10000;

    static std::chrono::high_resolution_clock::time_point startPoint;

    if (end) {
        std::chrono::high_resolution_clock::time_point endPoint =
            std::chrono::high_resolution_clock::now();

        std::chrono::microseconds elapsedMicroseconds =
            std::chrono::duration_cast<std::chrono::microseconds>(endPoint -
                                                                  startPoint);
        std::chrono::milliseconds elapsedMilliseconds =
            std::chrono::duration_cast<std::chrono::milliseconds>(endPoint -
                                                                  startPoint);
        std::chrono::seconds elapsedSeconds =
            std::chrono::duration_cast<std::chrono::seconds>(endPoint -
                                                             startPoint);

        if (elapsedMicroseconds.count() <= MICROSECOND_LIMIT) {
            std::cerr << "MICRO = " << elapsedMicroseconds.count() << std::endl;
        } else if (elapsedMilliseconds.count() <= MILLISECOND_LIMIT) {
            std::cerr << "MILLI = " << elapsedMilliseconds.count() << std::endl;
        } else {
            std::cerr << "Seconds = " << elapsedSeconds.count() << std::endl;
        }
    } else {
        startPoint = std::chrono::high_resolution_clock::now();
    }
}

void print() {}

template <typename T> void print(const T &item) { std::cerr << item; }

template <typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    const std::string PRINT_DELIMITER = " ";

    std::cerr << head << PRINT_DELIMITER;
    print(tail...);
}

void println() { std::cerr << std::endl; }

template <typename T> void println(const T &item) {
    std::cerr << item << std::endl;
}

template <typename Head, typename... Tail>
void println(const Head &head, const Tail &... tail) {
    const std::string PRINT_DELIMITER = " ";

    std::cerr << head << PRINT_DELIMITER;
    println(tail...);
}

template <typename T> void print1D(const std::vector<T> &vec) {
    const std::string PRINT_DELIMITER = " ";
    
    bool first = true;
    for (auto &i : vec) {
        if (!first) {
            std::cerr << PRINT_DELIMITER;
        } else {
            first = false;
        }
        std::cerr << i;
    }
    std::cerr << std::endl;
}

template <typename T> void print2D(const std::vector<std::vector<T>> &vec2D) {
    for (auto &i : vec2D) {
        print1D(i);
    }
}
