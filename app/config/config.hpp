#pragma once

#include <iostream>
#include <string>
#include "../utils/utils.cpp"

class Config{
    public:
        error* GetConfig(const std::string& filepath);
};