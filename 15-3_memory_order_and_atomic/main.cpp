#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using std::vector;
using std::thread;
using std::mutex;

void worker(int* counter, mutex* m) {
    for(int i = 0; i < 10000; i++) {
        m->lock();
        (*counter)++;
        m->unlock();
    }
}

int main()
{
    int counter = 0;
    mutex m;
    vector<thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.push_back(thread(worker, &counter, &m));
    }
    for (int i = 0; i < 4; i++) {
        threads[i].join();
    }

    std::cout << counter << std::endl;


    return 0;
}
