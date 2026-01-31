#include <iostream>
#include <thread>
#include <chrono>

int main(){
    for(int i=0;i<3;i++){
        std::cout<<"Job executed\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
