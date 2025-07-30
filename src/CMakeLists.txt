add_library(neo7m_lib
    neo7m.cpp
    neo7m.h
    )

target_include_directories(neo7m_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(neo7m_lib
    pico_stdlib
    hardware_i2c
    )