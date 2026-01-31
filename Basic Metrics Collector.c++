#include <iostream>
#include <chrono>
#include <thread>

int main(){
    for(int i=0;i<5;i++){
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::cout<<"Metric collected at "<<std::ctime(&t);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
