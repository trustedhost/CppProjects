#include <iostream>
#include <thread>
#include <future>

int some_task(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return n * 10;
}

int main() {
    std::packaged_task<int(int)> task(some_task);
    std::future<int> data = task.get_future();
    std::thread t(std::move(task), 5);

    std::cout << "비동기적으로 이놈은 처리" << std::endl;
    data.wait();
    std::cout << data.get() << std::endl;

    t.join();
}
