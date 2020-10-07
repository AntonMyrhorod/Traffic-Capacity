#pragma once

// Standard includes
#include <string>

// Third-party includes

// Non-local includes

// Local includes


class CTrafficApp
{
    public:
    CTrafficApp ();

    int parseCommandLine (int argc, char **argv);
    bool needShowUsage () const;
    static void showUsage ();

    private:
    bool m_showUsage = false;
    std::string m_configPath;
    std::string m_roadDataPath;
};
