#include <iostream>
#include <cstdlib>

int main(){
    const char* path = std::getenv("PATH");
    if(path) std::cout<<path<<"\n";
}
