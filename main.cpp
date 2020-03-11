#include <iostream>
#include "app/processor/processor.hpp"
#include "app/utils/utils.cpp"

int main(){
    Processor processor;
    error* error;
    
    std::cout << "initializing processor" << std::endl;
    error = processor.Initialize();
    if (error != nullptr){
        std::cerr << "initialization error" << std::endl;
        std::cerr << error->message << std::endl;
        delete error;
        return 0;
    }

    error = processor.Run();
    if (error != nullptr){
        std::cerr << "error encountered" << std::endl;
        std::cerr << error->message << std::endl;
        return 0;
    }


    error = processor.Close();
    if (error != nullptr){
        std::cerr << "error while closing" << std::endl;
        std::cerr << error->message << std::endl;
        return 0;
    }
    return 1;
}