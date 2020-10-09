// Standard includes
#include <iostream>

// Third-party includes
#include "spdlog/spdlog.h"

// Non-local includes
#include "trcp/trcp.hpp"

// Local includes
#include "CTrafficApp.hpp"


CTrafficApp::CTrafficApp ()
{
    spdlog::trace ("TrafficApp constructor");
}

bool CTrafficApp::parseCommandLine (int argc, char **argv)
{
    if (argc == 2 && std::string (argv[1]) == "-h")
    {
        showUsage ();
        return false;
    }

    if (argc == 3 && std::string (argv[1]) == "-c")
    {
        m_configPath = argv[2];
        spdlog::debug ("Config path: {}", m_configPath);
        return true;
    }

    spdlog::error ("Invalid arguments");
    showUsage ();
    return false;
}

void CTrafficApp::calculateTrafficCapacity ()
{
    trcp::reader::CReaderFromJson reader;
    trcp::data::SRoad road;

    reader.parse (m_configPath, road);
}

void CTrafficApp::showUsage ()
{
    std::cout << "Usage: traffic-capacity\t[-c] <config-path>\tPath to json road config file\n"
              << "\t\t\t[-h]\t\t\tShow usage" << std::endl;
}
