#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using std::vector;
using std::thread;

void worker(std::atomic<int>* counter) {
    for(int i = 0; i < 10000; i++) {
        // (*counter)++;
        counter->fetch_add(1, std::__1::memory_order_relaxed);
    }
}

int main()
{
    std::atomic<int> counter(0);
    vector<thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.push_back(thread(worker, &counter));
    }
    for (int i = 0; i < 4; i++) {
        threads[i].join();
    }

    std::cout << counter << std::endl;

    return 0;
}
