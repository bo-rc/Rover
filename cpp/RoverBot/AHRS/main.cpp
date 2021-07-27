#include "AHRS.hpp"
#include "MPU9250.h"
#include <chrono>
#include <thread>
#include <iostream>

int main(int argc, char *argv[])
{
    int hertz = 100;        // outerloop frequency, hertz.

    for (size_t i = 0; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-hz")
        {
            if (i + 1 < argc)
            {
                hertz = atof(argv[i + 1]);
            }
        }
    }
    std::cout << " [Arg] run at: " << hertz << " hertz";
    
    AHRS est;

    //-------------------- Setup gyroscope offset -----------------------------

    while(true)
    {
        est.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/hertz)); // 100Hz
    }   
}