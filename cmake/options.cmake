# C++ compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Build tests
option(ENABLE_UNIT_TESTS "Enables the unit tests" OFF)

# Build example application
option(ENABLE_EXAMPLE_APP "Enables the example application build" OFF)

# Log level of example application
set(LOG_LEVEL "trace" CACHE STRING "Log level: trace, debug, info, warning, error, critical, off")
