#include <iostream>
#include <chrono>

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout<<"Time: "<<
    std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
    <<" us\n";
}
