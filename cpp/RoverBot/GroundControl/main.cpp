#include <chrono>
#include <thread>
#include <iostream>

#include "GroundControl.hpp"
#include "Types.hpp"


int main(int argc, char * argv[])
{
    std::string groundStationIP{"10.0.0.208"};
    int hertz = 10;        // outerloop frequency, hertz.

    for (size_t i = 0; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-g")
        {
            if (i + 1 < argc)
            {
                groundStationIP = argv[i + 1];
            }
        }
        else if (std::string(argv[i]) == "-hz")
        {
            if (i + 1 < argc)
            {
                hertz = atof(argv[i + 1]);
            }
        }
    }
    std::cout << " [Arg] run at: " << hertz << " hertz";
    std::cout << " [Arg] connect to GCS: " << groundStationIP;

    GroundControl gc(groundStationIP);
    // Main loop
    while (true)
    {
        gc.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/hertz)); // 10Hz
    }

    return 0;
}
