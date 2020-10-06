#pragma once

#include <string>

class TrafficApp
{
public:
    TrafficApp();

    int parseCommandLine(int argc, char** argv);
    bool needShowUsage();
    void showUsage();

private:
    bool m_showUsage = false;
    std::string m_configPath;
    std::string m_roadDataPath;
};
