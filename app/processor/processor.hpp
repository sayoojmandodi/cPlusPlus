#pragma once

#include <iostream>
#include "../plc/plc.hpp"
#include "../database/database.hpp"
#include "../baumer/baumercamera.hpp"
#include "../basler/baslercamera.hpp"
#include "../utils/utils.cpp"
#include "../camera/camera.cpp"

class Processor{
    private:
        PLC plc;
        Database database;
        Camera* cam1;
        Camera* cam2;

    public:
        Processor();
        ~Processor();
        error* err;
        
    public:
        error* Initialize();
        error* Run();
        error* Close();
};