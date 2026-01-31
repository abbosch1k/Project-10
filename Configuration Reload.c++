#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <thread>
#include <chrono>

namespace fs = std::filesystem;

int main() {
    const std::string cfg = "config.txt";
    auto last = fs::last_write_time(cfg);

    while (true) {
        auto now = fs::last_write_time(cfg);
        if (now != last) {
            std::ifstream f(cfg);
            std::string line;
            std::cout << "Config reloaded:\n";
            while (std::getline(f, line)) std::cout << line << "\n";
            last = now;
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
