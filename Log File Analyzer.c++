#include <fstream>
#include <iostream>
#include <string>
int main(){
    std::ifstream f("log.txt");
    std::string line; int count=0;
    while(std::getline(f,line))
        if(line.find("ERROR")!=std::string::npos) count++;
    std::cout<<"Errors: "<<count;
}
