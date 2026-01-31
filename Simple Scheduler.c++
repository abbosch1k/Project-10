#include <iostream>
#include <chrono>
#include <thread>

int main() {
    while (true) {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::cout << "Task executed at " << std::ctime(&t);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}
