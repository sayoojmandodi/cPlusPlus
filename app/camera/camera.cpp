#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "../utils/utils.cpp"

class Camera{
    public:
        virtual error* Initialize() = 0;
};

#endif