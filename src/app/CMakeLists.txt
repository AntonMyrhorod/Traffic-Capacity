set(TARGET trafficCapacityApp)

add_executable(${TARGET})

add_subdirectory(CTrafficApp)

target_sources(
    ${TARGET}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    ${TARGET}
    PRIVATE
    spdlog
    trafficCapacity
)

add_definitions(-DLOG_LEVEL="${TRCP_APP_LOG_LEVEL}")
