#include <iostream>
#include <thread>
#include <mutex>

class Counter {
    int value = 0;
    std::mutex mtx;
public:
    void inc() {
        std::lock_guard<std::mutex> l(mtx);
        value++;
    }
    int get() {
        std::lock_guard<std::mutex> l(mtx);
        return value;
    }
};

int main() {
    Counter c;
    std::thread t1([&]{ for(int i=0;i<1000;i++) c.inc(); });
    std::thread t2([&]{ for(int i=0;i<1000;i++) c.inc(); });
    t1.join(); t2.join();
    std::cout << c.get() << "\n";
}
