set(TARGET trafficCapacity)

add_library(${TARGET} STATIC)

add_subdirectory(common)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

target_include_directories(
    ${TARGET}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/trcp
)

target_link_libraries(
    ${TARGET}
    PRIVATE
    spdlog
)
