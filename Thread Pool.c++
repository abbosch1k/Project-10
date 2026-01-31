#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(int n) {
        for(int i=0;i<n;i++){
            workers.emplace_back([this]{
                while(true){
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(mtx);
                        cv.wait(lock,[&]{ return stop || !tasks.empty(); });
                        if(stop && tasks.empty()) return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    void enqueue(std::function<void()> f){
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(f);
        }
        cv.notify_one();
    }

    ~ThreadPool(){
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();
        for(auto &t:workers) t.join();
    }
};

int main(){
    ThreadPool pool(3);
    for(int i=0;i<6;i++)
        pool.enqueue([i]{ std::cout<<"Task "<<i<<"\n"; });
}
