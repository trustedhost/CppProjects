#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <cstddef>
#include <thread>
#include <future>
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

    template <class F, class... Args>
    std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(F&& f, Args&&... args);
};

template<class F, class... Args>
std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F&& f, Args&&... args)
{
    if (stop_all) {
        throw std::runtime_error("threadpool error");
    }

    using return_type = typename std::result_of<F(Args...)>::type;
    auto job = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::future<return_type> job_result_future = job->get_future();

    {
        std::lock_guard<std::mutex> lk(m_job_q_);
        jobs_.push([job](){(*job)();});
    }
    cv_job_q_.notify_one();
    return job_result_future;

}

#endif // THREADPOOL_H
