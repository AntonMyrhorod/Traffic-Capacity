#pragma once

// Standard includes
#include <string>

// Third-party includes

// Non-local includes

// Local includes


class CTrafficApp
{
    public:
    bool parseCommandLine (int argc, char **argv);
    void calculateTrafficCapacity ();

    private:
    void showUsage ();

    std::string m_configPath;
};
