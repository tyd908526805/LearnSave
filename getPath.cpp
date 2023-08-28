#include <iostream>
#include <unistd.h>

void getPath() 
{
    char path[255];
    if (!getcwd(path, 255))
    {
        std::cout << "get path error" << std::endl;
    }
    else
    {
        std::cout << "get path success" << std::endl;
        std::cout << "path: " << path << std::endl;
    }
}

int main()
{
    getPath();
}
