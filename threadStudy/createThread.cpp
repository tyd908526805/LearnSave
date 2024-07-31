#include <iostream>
#include <thread>
#include <system_error>

void print_message(const std::string &message)
{
    std::cout << message << std::endl;
}

int main()
{
//    try 
//    {
        std::thread t1(print_message, "hello from thread 1");
        std::thread t2(print_message, "hello from thread 2");

        t1.join();
        t2.join();
//    } 
//    catch (const std::system_error &e) 
//    {
//        std::cout << "creat thread failed:" << e.what() << std::endl;
//        return -1;
//    }

}
