#include <iostream>
#include <thread>
#include <future>

int sum(const std::vector<int>& v, int start, int end) {
    int total = 0;
    for (int i = start; i < end; ++i) {
        total += v[i];
    }
    return total;
}

int parallel_sum(const std::vector<int>& v) {
    std::future<int> lower_half_future = std::async(std::launch::async, sum, cref(v), 0, v.size() / 2);
    int upper_half = sum(cref(v), v.size()/2, v.size());
    return lower_half_future.get() + upper_half;
}

int main() {
    std::vector<int> v;
    v.reserve(1000);

    for (int i = 0; i < 1000; ++i) {
        v.push_back(i + 1);
    }

    std::cout << "1부터 1000까지의 합 : " << parallel_sum(v) << std::endl;
}
