#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>

class SafeQueue {
    std::queue<int> q;
    std::mutex m;
    std::condition_variable cv;
public:
    void push(int v){
        std::lock_guard<std::mutex> l(m);
        q.push(v);
        cv.notify_one();
    }
    int pop(){
        std::unique_lock<std::mutex> l(m);
        cv.wait(l,[&]{ return !q.empty(); });
        int v=q.front(); q.pop();
        return v;
    }
};

int main(){
    SafeQueue q;
    std::thread p([&]{ for(int i=0;i<5;i++) q.push(i); });
    std::thread c([&]{ for(int i=0;i<5;i++) std::cout<<q.pop()<<"\n"; });
    p.join(); c.join();
}
