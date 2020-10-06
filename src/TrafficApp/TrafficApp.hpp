#pragma once

// Standard includes
#include <string>

// Third-party includes

// Non-local includes

// Local includes


class TrafficApp
{
    public:
    TrafficApp ();

    int parseCommandLine (int argc, char **argv);
    bool needShowUsage () const;
    static void showUsage ();

    private:
    bool m_showUsage = false;
    std::string m_configPath;
    std::string m_roadDataPath;
};
