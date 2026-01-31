#include <iostream>
#include <fstream>
#include <functional>

int main(){
    std::ifstream f("file.txt", std::ios::binary);
    std::string data((std::istreambuf_iterator<char>(f)),
                      std::istreambuf_iterator<char>());
    size_t hash = std::hash<std::string>{}(data);
    std::cout << "File hash: " << hash << "\n";
}
