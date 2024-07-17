#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <climits>

constexpr bool isPrimeSlow(const int val) {
    if (val <= 1) {
        return false;
    }
    int halfVal = val / 2;
    for(int i = 2; i <= halfVal;++i) {
        if (val % i == 0) {
           return false;
        }
    }
    return true;
}

constexpr bool isPrimeFast(const int val) {
    if (val <= 1) {
        return false;
    }
    if (val % 2 == 0) {
        return val == 2;
    }
    if (val % 3 == 0) {
        return val == 3;
    }
    if (val % 5 == 0) {
        return val == 5;
    }
    if (val % 7 == 0) {
        return val == 7;
    }
    if (val % 11 == 0) {
        return val == 11;
    }
    for(int i = 13; i * i < val; i += 2) {
        if(val % i == 0) {
            return false;
        }
    }
    return true;
}

void isPrimeTest() {
    auto startTimeSlow = std::chrono::high_resolution_clock::now();
    for (int i = 0;i < INT_MAX; ++i) {
        /*if (isPrimeSlow(i)) {
            std::cout << i << ' ';
        }*/
    }
    auto endTimeSlow = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationSlow = endTimeSlow - startTimeSlow;
    std::cout << "isPrimeSlow process has done in : " << durationSlow.count() << '\n';
    auto startTimeFast = std::chrono::high_resolution_clock::now();

    std::cout << "\n**************************\n";
    for (int i = 0;i < INT_MAX; ++i) {
        /*if(isPrimeFast(i)) {
            std::cout << i << ' ';
        }*/
    }
    auto endTimeFast = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationFast = endTimeFast - startTimeFast;
    std::cout << "isPrimeFast process has done in : " << durationFast.count() << '\n';
}


int main() {
    isPrimeTest();
}