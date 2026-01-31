#include <iostream>

enum State{IDLE,WORK,DONE};

int main(){
    State s=IDLE;
    s=WORK;
    s=DONE;
    std::cout<<"Finished\n";
}
