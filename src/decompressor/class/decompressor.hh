#pragma once
#include <iostream>
class Decompressor
{
public:
    Decompressor(const std::string file);
    ~Decompressor() = default;
    const std::string file_get();
    void run();
private:
    std::string file_;
};