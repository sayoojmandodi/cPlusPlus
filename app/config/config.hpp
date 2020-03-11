#pragma once

#include <iostream>
#include <string>
#include "../utils/utils.hpp"

class Config{
    public:
        error* GetConfig(const std::string& filepath);
};