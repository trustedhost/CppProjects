#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <cstddef>
#include <thread>
#include <vector>
#include <queue>

class ThreadPool
{
    size_t num_threads_;
    std::vector<std::thread> worker_threads_;
    std::queue<std::function<void()>> jobs_;// 모든 작업 쓰레드에서 접근이 가능한 큐.
    std::condition_variable cv_job_q_;
    std::mutex m_job_q_;
    std::atomic<bool> stop_all;
    void WorkerThread();

public:
    ThreadPool(size_t num_threads);
    ~ThreadPool();
    void EnqueueJob(std::function<void()> job);
};

#endif // THREADPOOL_H
