add_subdirectory(trafficCapacityLib)

if(ENABLE_EXAMPLE_APP)
    add_subdirectory(app)
endif()

if(ENABLE_UNIT_TESTS)
    add_subdirectory(unitTests)
endif()
