#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id)
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return ready;});
    std::cout << "Thread " << id << std::endl;
}

void go()
{
    std::unique_lock<std::mutex> lock(mtx);
    ready = true;
    cv.notify_all();
}

int main()
{
    std::thread threads[10];
    for (int i = 0; i < 10; i++)
    {
        threads[i] = std::thread(print_id, i);
    }
    std::cout << "10 threads ready to race...." << std::endl;
    go();

    for (auto &th : threads)
    {
        th.join();
    }
}
