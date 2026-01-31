#include <iostream>
#include <filesystem>
#include <thread>
#include <chrono>

namespace fs = std::filesystem;

int main() {
    fs::file_time_type last;
    const std::string file = "watch.txt";

    if (fs::exists(file)) last = fs::last_write_time(file);

    while (true) {
        if (fs::exists(file)) {
            auto now = fs::last_write_time(file);
            if (now != last) {
                std::cout << "File changed\n";
                last = now;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
