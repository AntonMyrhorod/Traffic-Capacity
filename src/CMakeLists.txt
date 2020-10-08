add_subdirectory(trcpLib)

if(TRCP_BUILD_EXAMPLE_APP)
    add_subdirectory(app)
endif()

if(TRCP_BUILD_UNIT_TESTS)
    add_subdirectory(unitTests)
endif()
