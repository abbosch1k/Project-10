#include <iostream>
#include <fstream>

int main(){
    std::ifstream f("file.txt", std::ios::binary);
    char buf[16];
    while(f.read(buf,sizeof(buf)))
        std::cout.write(buf,sizeof(buf));
}
