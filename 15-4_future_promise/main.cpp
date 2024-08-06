#include <iostream>
#include <thread>
#include <string>
#include <condition_variable>
#include <mutex>

std::mutex m;
std::condition_variable cv;
bool done = false;
std::string info;

void worker() {
    {
        std::lock_guard<std::mutex> lk(m);
        info = "hello world";
        done = true;
    }
    cv.notify_all();
}

int main() {
    std::thread t(worker);

    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [](){ return done; });
    lk.unlock();

    std::cout << info << std::endl;

    t.join();
}
