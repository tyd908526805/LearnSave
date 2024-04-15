#include <iostream>
#include <fstream>
#include "snappy.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "需要文件名 例如: ./compress source.txt" << std::endl;
        return -1;
    }

    std::ifstream sourceFile(argv[1], std::ios::in);
    if (sourceFile.fail())
    {
        std::cout << "打开文件 " << argv[1] << " 失败" << std::endl;
        return -1;
    }

    std::ofstream targetFile("target.txt");
    if (!targetFile.is_open()) 
    { 
        std::cout << "打开文件 target.txt 失败" << std::endl;
        return -1;
    }

    while (!sourceFile.eof())
    {
        std::string sourceStr;
        std::string targetStr;
        std::getline(sourceFile, sourceStr);
        if (sourceStr.empty())
            continue;
        std::cout << "文件内容: " << sourceStr << std::endl;

        std::cout << "压缩开始" << std::endl;
        targetStr.resize(snappy::MaxCompressedLength(sourceStr.size()));
        size_t targetSize;
        snappy::RawCompress(sourceStr.data(), sourceStr.size(), &targetStr[0], &targetSize);
        targetStr.resize(targetSize);
        std::cout << "压缩完成" << std::endl;

        std::cout << "写入文件开始" << std::endl;
        targetFile << targetStr.data() << std::endl;
        std::cout << "写入文件完成" << std::endl;
    }

    targetFile.close();
    return 0;
}
