#pragma once

#include <iostream>
#include "../utils/utils.cpp"
#include "../camera/camera.cpp"

class BaumerCamera : public Camera{
    public:
        error* Initialize();
};