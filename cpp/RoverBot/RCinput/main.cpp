#include "RCinput.hpp"
#include <chrono>
#include <thread>
#include <iostream>

int main(int argc, char * argv[])
{
    int hertz = 100;        // outerloop frequency, hertz.
    std::string configFilePath = "";
    Configurations config;

    for (size_t i = 0; i < argc; ++i)
    {
        if (std::string(argv[i]) == "-hz")
        {
            if (i + 1 < argc)
            {
                hertz = atof(argv[i + 1]);
            }
        }
        else if (std::string(argv[i]) == "-c")
        {
            if (i + 1 < argc)
            {
                configFilePath = std::string(argv[i + 1]);
            }
        }
    }

    std::cout << " [Arg] run at: " << hertz << " hertz" << std::endl;
    
    if (configFilePath != "")
    {
        if (not config.load(configFilePath))
        {
            std::cout << " [Arg] Failed to load the configurations." << std::endl;
            std::cout << " [Arg] Use the default configurations." << std::endl;
        }
        else
        {
            std::cout << " [Arg] Successfully loaded the configurations." << std::endl;
        }
    } else
    {
        std::cout << " [Arg] No configuration file was specified." << std::endl;
        std::cout << " [Arg] Use the default configurations." << std::endl;
    }
    std::cout << config << std::endl << std::endl;

    RCinput rc(config);
    // Main loop
    while (true)
    {
        rc.step();       
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/hertz));
    }

    return 0;
}
