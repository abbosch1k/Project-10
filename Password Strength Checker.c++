#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string p; cin>>p;
    bool u=0,l=0,d=0;
    for(char c:p){
        if(isupper(c))u=1;
        if(islower(c))l=1;
        if(isdigit(c))d=1;
    }
    cout<<(u&&l&&d?"Strong":"Weak");
}
