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
)

add_definitions(-DLOG_LEVEL="${LOG_LEVEL}")
