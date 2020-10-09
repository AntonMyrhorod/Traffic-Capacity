// Standard includes

// Third-party includes
#include "spdlog/spdlog.h"

// Non-local includes

// Local includes
#include "CTrafficApp/CTrafficApp.hpp"

int main (int argc, char **argv)
{
    CTrafficApp app;

    try
    {
        spdlog::set_level (spdlog::level::debug);

        if (app.parseCommandLine (argc, argv) == false)
            return 1;

        app.calculateTrafficCapacity ();
    }
    catch (const std::exception &e)
    {
        spdlog::error ("Exception: {}", e.what ());
        return 1;
    }

    return 0;
}
