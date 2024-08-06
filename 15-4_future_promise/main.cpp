#include <iostream>
#include <thread>
#include <string>
#include <future>

using std::string;

void worker(std::promise<string>* p) {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    p->set_value("hello");
}

int main() {
    std::promise<string> p;
    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    while (true) {
        std::future_status status = data.wait_for(std::chrono::seconds(1));
        if (status == std::future_status::timeout) {
            std::cerr << ">" ;
        }
        if (status == std::future_status::ready) {
            break;
        }
    }
    std::cout << data.get();
    t.join();

}
