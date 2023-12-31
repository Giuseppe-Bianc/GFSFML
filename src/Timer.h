#pragma once
#include "headers.h"

class Timer {
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

    void stop() {
        end_time = std::chrono::high_resolution_clock::now();
        running = false;
    }

    double elapsedNanoseconds() const {
        auto end = running ? std::chrono::high_resolution_clock::now() : end_time;
        return C_D(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start_time).count());
    }

    double elapsedMicroseconds() const {
        return elapsedNanoseconds() / 1000.0;
    }

    double elapsedMilliseconds() const {
        return elapsedNanoseconds() / 1'000'000.0;
    }

    double elapsedSeconds() const {
        return elapsedNanoseconds() / 1'000'000'000.0;
    }

private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
    bool running = true;
};