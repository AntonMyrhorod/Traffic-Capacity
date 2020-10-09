// Standard includes
#include <iostream>

// Third-party includes
#include "spdlog/spdlog.h"

// Non-local includes
#include "trcp/trcp.hpp"

// Local includes
#include "CTrafficApp/CTrafficApp.hpp"

int main (int argc, char **argv)
{
    CTrafficApp app;

    try
    {
        spdlog::set_level (spdlog::level::debug);

        std::cout << trcp::version () << std::endl;

        if (!app.parseCommandLine (argc, argv))
        {
            return 1;
        }

        app.calculateTrafficCapacity ();
    }
    catch (const std::exception &e)
    {
        spdlog::error ("[main] Exception: {}", e.what ());
        return 1;
    }

    return 0;
}
