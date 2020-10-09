set(TARGET trafficCapacityApp)

add_executable(${TARGET})

add_subdirectory(CTrafficApp)

target_sources(
    ${TARGET}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(
    ${TARGET}
    PRIVATE
    spdlog
    trcp
)
