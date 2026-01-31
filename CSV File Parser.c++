#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(){
    std::ifstream f("data.csv");
    std::string line;
    while(std::getline(f,line)){
        std::stringstream ss(line);
        std::string cell;
        while(std::getline(ss,cell,',')) std::cout<<cell<<" ";
        std::cout<<"\n";
    }
}
