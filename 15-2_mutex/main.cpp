#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void func(int& count, std::mutex& m1, std::mutex& m2) {
    for(int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock(m1);
        std::lock_guard<std::mutex> lock2(m2);
        count += 1;
    }
}

void func2(int& count, std::mutex& m1, std::mutex& m2) {
    for(int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock(m1);
        std::lock_guard<std::mutex> lock2(m2);
        count += 1;
    }
}


int main()
{
    int count = 0;
    std::mutex m1;
    std::mutex m2;
    vector<thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.push_back(thread(func, std::ref(count), std::ref(m1), std::ref(m2)));
    }

    vector<thread> threads2;
    for (int i = 0; i < 4; i++) {
        threads2.push_back(thread(func2, std::ref(count), std::ref(m1), std::ref(m2)));
    }

    for (int i = 0; i < 4; i++) {
        threads[i].join();
        threads2[i].join();
    }

    std::cout << count << std::endl;
    return 0;
}
