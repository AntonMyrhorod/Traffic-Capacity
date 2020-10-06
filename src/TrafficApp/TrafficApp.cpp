#include "TrafficApp.hpp"

#include <iostream>
#include <vector>
#include <exception>

TrafficApp::TrafficApp()
{

}

int TrafficApp::parseCommandLine(int argc, char **argv)
{
    if (argc == 2 && std::string(argv[1]) == "-h")
    {
        m_showUsage = true;
        return 0;
    }

    if (argc != 5)
    {
        std::cout << "Invalid arguments" << std::endl;
        m_showUsage = true;
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);

        if (arg == "-d")
        {
            m_roadDataPath = argv[++i];
        }
        else if (arg == "-c")
        {
            m_configPath = argv[++i];
        }
        else
        {
            std::cout << "Invalid argument: " << arg << std::endl;
            m_showUsage = true;
            return 1;
        }
    }

    if (m_configPath.empty() || m_roadDataPath.empty())
    {
        std::cout << "Invalid arguments: config path and road data path are required" << std::endl;
        m_showUsage = true;
        return 1;
    }

    std::cout << "config: " << m_configPath <<
                  "\ndata: " << m_roadDataPath << std::endl;

    return 0;
}

bool TrafficApp::needShowUsage()
{
    return m_showUsage;
}

void TrafficApp::showUsage()
{
    std::cout << "Usage: traffic-capacity\t[-c] <config-path>\tPath to json config file\n"
              << "\t\t\t[-d] <road-data-path>\tPath to json road data file\n"
              << "\t\t\t[-h]\t\t\tShow usage"
              << std::endl;
}
