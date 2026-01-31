#include <iostream>
#include <unordered_map>
#include <chrono>

int main(){
    std::unordered_map<std::string, std::chrono::steady_clock::time_point> cache;
    cache["token"] = std::chrono::steady_clock::now();

    auto now = std::chrono::steady_clock::now();
    if(now - cache["token"] < std::chrono::seconds(5))
        std::cout<<"Cache valid\n";
    else
        std::cout<<"Cache expired\n";
}
