#pragma once

#include <iostream>
#include "../plc/plc.hpp"
#include "../database/database.hpp"
#include "../baumer/baumercamera.hpp"
#include "../basler/baslercamera.hpp"
#include "../utils/utils.cpp"

class Processor{
    private:
        PLC plc;
        Database database;
        BaumerCamera baumerCamera;
        BaslerCamera baslerCamera;

    public:
        Processor();
        ~Processor();
        error* Initialize();
        error* Run();
        error* Close();
};