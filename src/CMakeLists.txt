set(TARGET trcp)

add_library(${TARGET} STATIC)

include_directories(${CMAKE_SOURCE_DIR}/)

add_subdirectory(utils)

target_include_directories(
    ${TARGET}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
    ${TARGET}
    PRIVATE
    spdlog
    jsoncpp_lib
)
