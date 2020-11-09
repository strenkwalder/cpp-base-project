#include <iostream>
#include <memory>

#include "src/dummy.h"

int main(){

    //int *var = 0;
    int *var = new int(5);
    //auto var = std::make_unique<int>(5);

    std::cout << "Hello World!" << std::endl;

    return 0;
}
