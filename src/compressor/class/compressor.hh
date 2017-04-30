#pragma once
#include <iostream>
class Compressor
{
public:
    Compressor(const std::string file);
    ~Compressor() = default;
    const std::string file_get();
    void run();
private:
    std::string file_;
};