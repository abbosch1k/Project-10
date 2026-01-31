#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::string req = "GET /index HTTP/1.1";
    std::istringstream ss(req);
    std::string method,path,ver;
    ss>>method>>path>>ver;
    std::cout<<method<<" "<<path<<" "<<ver<<"\n";
}
