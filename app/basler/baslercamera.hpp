#pragma once

#include <iostream>
#include "../utils/utils.cpp"
#include "../camera/camera.cpp"

class BaslerCamera : public Camera{
    public:
        error* Initialize();
};