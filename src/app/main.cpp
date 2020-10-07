// Standard includes

// Third-party includes
#include "spdlog/spdlog.h"

// Non-local includes

// Local includes
#include "CTrafficApp/CTrafficApp.hpp"


int main (int argc, char **argv)
{
    int result = 0;
    CTrafficApp app;

    try
    {
        spdlog::set_level (spdlog::level::from_str (LOG_LEVEL));

        result = app.parseCommandLine (argc, argv);

        if (app.needShowUsage ())
        {
            CTrafficApp::showUsage ();
            return result;
        }
    }
    catch (const std::exception &e)
    {
        spdlog::error ("Exception: {}", e.what ());
        result = 1;
    }

    return result;
}
