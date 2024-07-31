#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_message(const std::string &message)
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << message << std::endl;
}

int main()
{
    std::thread t1(print_message, "hello from thread 1");
    std::thread t2(print_message, "hello from thread 2");

    t1.join();
    t2.join();
}
