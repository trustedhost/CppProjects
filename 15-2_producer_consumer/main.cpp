#include <iostream>
#include <thread>
#include <vector>
#include <queue>

using std::vector;
using std::thread;

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m, int index){
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
        std::string content = "웹사이트" + std::to_string(i) + " from thread : " + std::to_string(index) + "\n";

        m->lock();
        downloaded_pages->push(content);
        m->unlock();
    }
}



void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_proceed) {
    while (*num_proceed < 25) {
        m->lock();
        if (downloaded_pages->empty()) {
            m->unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }

        std::string content = downloaded_pages->front();
        downloaded_pages->pop();

        (*num_proceed)++;
        m->unlock();
        std::cout << content;
        std::cout << "read by thread : " << std::this_thread::get_id() << std::endl;;
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}

int main()
{
    std::queue<std::string> downloaded_pages;
    std::mutex m;

    std::vector<std::thread> producers;
    for (int i = 0; i < 5; i++) {
        producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1));
    }

    int num_proceed = 0;
    std::vector<std::thread> consumers;
    for (int i = 0; i < 3; i++) {
        consumers.push_back(std::thread(consumer, &downloaded_pages, &m, &num_proceed));
    }

    for (int i = 0; i < 5; i++) {
        producers[i].join();
    }
    for (int i = 0; i < 3; i++) {
        consumers[i].join();
    }

    return 0;
}
