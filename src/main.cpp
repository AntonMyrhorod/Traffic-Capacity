// Standard includes
#include <iostream>

// Third-party includes

// Non-local includes

// Generated includes

// Local includes
#include "TrafficApp/TrafficApp.hpp"

int main(int argc, char **argv)
{
    int result = 0;
    TrafficApp app;

    try
    {
        result = app.parseCommandLine(argc, argv);

        if (app.needShowUsage())
        {
            app.showUsage();
            return result;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        result = 1;
    }

    return result;
}
