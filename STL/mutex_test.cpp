#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

int sd = 0;

void re_mutex(int count){
    if(count < 0){
        return;
    }
    mtx.lock();
    std::cout << "mutex locked count: " << count << std::endl;
    re_mutex(count - 1);
    mtx.unlock();
}

int main(){

    re_mutex(10);

    return 0;
}