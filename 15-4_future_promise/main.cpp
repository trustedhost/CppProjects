#include <iostream>
#include <thread>
#include <string>
#include <future>

using std::string;

void worker(std::promise<string>* p) {
    p->set_value("some data");
}

int main() {
    std::promise<string> p;
    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    data.wait();
    std::cout << data.get() << std::endl;

    t.join();

}
