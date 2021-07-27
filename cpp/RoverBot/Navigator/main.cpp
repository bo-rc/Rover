#include "Navigator.hpp"
#include <chrono>
#include <thread>

#include <iostream>

int main(int argc, char * argv[])
{
    float tolerance = 0.15; // waypoint reached radius, m.
    int hertz = 100;        // outerloop frequency, hertz.

    for (size_t i = 0; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-t")
        {
            if (i + 1 < argc)
            {
                tolerance = atof(argv[i + 1]);
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
    std::cout << " [Arg] waypoint reach tolerance: " << tolerance << " m." << std::endl;

    std::vector<NavPose2d> route {};
    Navigator nav(route, tolerance);
    // Main loop
    while (true)
    {
        nav.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/hertz));
    }

    return 0;
}
