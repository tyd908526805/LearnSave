#include <fstream>

int main()
{
    std::ofstream outFile;
    outFile.open("test.csv");
    outFile << "test write success" << std::endl;
    outFile.close();
}
