#include <fstream>
#include <thread>

void copy(){
    std::ifstream a("a.txt",std::ios::binary);
    std::ofstream b("b.txt",std::ios::binary);
    b<<a.rdbuf();
}

int main(){
    std::thread t(copy);
    t.join();
}
