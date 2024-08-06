#include <iostream>
#include <future>
#include <string>

using std::string;

void runner(std::shared_future<string> start) {
    start.get();
    std::cout << "출발" << std::endl;
}

int main() {
    std::promise<string> p;
    std::shared_future<string> start = p.get_future();

    std::thread t(runner, start);
    std::thread t2(runner, start);
    std::thread t3(runner, start);
    std::thread t4(runner, start);

    std::cerr << "준비" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cerr << "땅" << std::endl;
    p.set_value("haha");

    t.join();
    t2.join();
    t3.join();
    t4.join();


    return 0;
}
