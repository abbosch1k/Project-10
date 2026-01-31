#include <iostream>
#include <queue>
#include <functional>

int main() {
    std::queue<std::function<void()>> jobs;

    jobs.push([]{ std::cout << "Job 1\n"; });
    jobs.push([]{ std::cout << "Job 2\n"; });

    while(!jobs.empty()) {
        jobs.front()();
        jobs.pop();
    }
}
