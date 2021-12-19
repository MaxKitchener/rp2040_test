cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)

project(rp2040_test)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(rp2040_test
    src/main.cpp
    src/gpio.cpp
    src/i2c.cpp
    src/vt100.cpp
    src/vl6108.cpp
    src/table.cpp
)

# Add pico_stdlib library which aggregates commonly used features
target_include_directories(rp2040_test PRIVATE src/inc/)

target_link_libraries(rp2040_test pico_stdlib hardware_i2c)

# enable usb disable uart
pico_enable_stdio_usb(rp2040_test 1)
pico_enable_stdio_uart(rp2040_test 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(rp2040_test)
