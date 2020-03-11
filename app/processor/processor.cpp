#include "processor.hpp"

Processor::Processor(){
    std::cout << "processor constructed" << std::endl;
}

Processor::~Processor(){
    std::cout << "processor destructed" << std::endl;
}

error* Processor::Initialize(){
    std::cout << "initializing processor" << std::endl;
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