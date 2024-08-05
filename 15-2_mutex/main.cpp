#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void func(int& count, std::mutex& m) {
    for(int i = 0; i < 10000; i++) {
        m.lock();
        count += 1;
        m.unlock();
    }
}

int main()
{
    int count = 0;
    std::mutex m;
    vector<thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.push_back(thread(func, std::ref(count), std::ref(m)));
    }

    for (int i = 0; i < 4; i++) {
        threads[i].join();
    }

    std::cout << count << std::endl;
    return 0;
}
