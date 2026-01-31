#include <iostream>
#include <thread>
#include <vector>

void work(int id){
    for(int i=0;i<3;i++)
        std::cout<<"Worker "<<id<<" step "<<i<<"\n";
}

int main(){
    std::vector<std::thread> v;
    for(int i=0;i<4;i++) v.emplace_back(work,i);
    for(auto &t:v) t.join();
}
