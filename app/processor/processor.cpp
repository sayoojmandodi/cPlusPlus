#include "processor.hpp"

Processor::Processor(){
    std::cout << "processor constructed" << std::endl;
}

Processor::~Processor(){
    std::cout << "processor destructed" << std::endl;
    if (this->err  != nullptr) delete this->err;
    if (this->cam1 != nullptr) delete this->cam1;
    if (this->cam2 != nullptr) delete this->cam2;
}

error* Processor::Initialize(){
    std::cout << "initializing processor" << std::endl;

    this->err = this->database.Connect();
    if (this->err != nullptr) return this->err;

    this->err = this->plc.Connect();
    if (this->err != nullptr) return this->err;

    this->cam1 = new BaumerCamera();
    this->err = cam1->Initialize();
    if (this->err != nullptr) return this->err;

    this->cam2 = new BaslerCamera();
    this->err = cam2->Initialize();
    if (this->err != nullptr) return this->err;

    std::cout << "processor initialized" << std::endl;
    return nullptr;
}


error* Processor::Run(){
    std::cout << "running processor" << std::endl;
    return nullptr;
}

error* Processor::Close(){
    std::cout << "closing processor" << std::endl;
    return nullptr;
}