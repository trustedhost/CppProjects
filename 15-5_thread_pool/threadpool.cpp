#include "threadpool.h"

ThreadPool::ThreadPool(size_t num_threads) : num_threads_(num_threads), stop_all(false) {
    worker_threads_.reserve(num_threads);
    for (int i = 0; i < num_threads; ++i) {
        worker_threads_.emplace_back([this](){ this->WorkerThread();});
    }
}

ThreadPool::~ThreadPool()
{
    stop_all = true;
    cv_job_q_.notify_all();

    for (auto& t : worker_threads_) {
        t.join();
    }

}

void ThreadPool::WorkerThread()
{
    while (true) {
        std::unique_lock<std::mutex> lk(m_job_q_);
        cv_job_q_.wait(lk, [this](){ return !jobs_.empty() || stop_all; });

        if (stop_all && jobs_.empty()) {
            return ;
        }
        std::function<void()> job = std::move(jobs_.front());
        jobs_.pop();
        lk.unlock();

        job();
    }
}


