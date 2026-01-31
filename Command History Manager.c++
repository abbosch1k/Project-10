#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> history;
    std::string cmd;
    while(true){
        std::getline(std::cin,cmd);
        if(cmd=="exit") break;
        history.push_back(cmd);
    }
    for(auto &c:history) std::cout<<c<<"\n";
}
