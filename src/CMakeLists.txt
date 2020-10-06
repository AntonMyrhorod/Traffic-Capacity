add_executable(${TARGET})

add_subdirectory(TrafficApp)

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
