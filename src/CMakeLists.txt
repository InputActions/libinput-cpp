find_package(PkgConfig REQUIRED)
pkg_search_module(LIBINPUT REQUIRED libinput)
pkg_search_module(LIBUDEV REQUIRED libudev)

add_library(libinput-cpp STATIC
    libinput-cpp/Device.cpp
    libinput-cpp/Event.cpp
    libinput-cpp/GestureEvent.cpp
    libinput-cpp/KeyboardEvent.cpp
    libinput-cpp/PathContext.cpp
    libinput-cpp/PointerEvent.cpp
    libinput-cpp/TouchEvent.cpp
    libinput-cpp/UdevDevice.cpp
)
target_link_libraries(libinput-cpp  PUBLIC
    Qt6::Core
    ${LIBINPUT_LIBRARIES}
    ${LIBUDEV_LIBRARIES}
)
target_compile_options(libinput-cpp PUBLIC -fPIC)

target_include_directories(libinput-cpp PRIVATE ${LIBEVDEV_INCLUDE_DIRS} ${LIBINPUT_INCLUDE_DIRS})
target_include_directories(libinput-cpp PUBLIC libinput-cpp)
