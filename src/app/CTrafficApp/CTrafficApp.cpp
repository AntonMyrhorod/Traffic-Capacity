// Standard includes
#include <iostream>

// Third-party includes
#include "spdlog/spdlog.h"

// Non-local includes

// Local includes
#include "CTrafficApp.hpp"


CTrafficApp::CTrafficApp ()
{
    spdlog::trace ("TrafficApp constructor");
}

int CTrafficApp::parseCommandLine (int argc, char **argv)
{
    const int validArgc = 5;

    if (argc == 2 && std::string (argv[1]) == "-h")
    {
        m_showUsage = true;
        return 0;
    }

    if (argc != validArgc)
    {
        spdlog::error ("Invalid arguments");
        m_showUsage = true;
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        const std::string arg (argv[i]);

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
            spdlog::error ("Invalid argument: {}", arg);
            m_showUsage = true;
            return 1;
        }
    }

    if (m_configPath.empty () || m_roadDataPath.empty ())
    {
        spdlog::error ("Invalid arguments: config path and road data path are required");
        m_showUsage = true;
        return 1;
    }

    spdlog::debug ("Config path: {}", m_configPath);
    spdlog::debug ("Road data path: {}", m_roadDataPath);

    return 0;
}

bool CTrafficApp::needShowUsage () const
{
    return m_showUsage;
}

void CTrafficApp::showUsage ()
{
    std::cout << "Usage: traffic-capacity\t[-c] <config-path>\tPath to json config file\n"
              << "\t\t\t[-d] <road-data-path>\tPath to json road data file\n"
              << "\t\t\t[-h]\t\t\tShow usage" << std::endl;
}
