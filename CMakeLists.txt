cmake_minimum_required(VERSION 3.5)

project(PasswordCracking LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(PasswordCracking main.cpp
    FileReading.h
    FileReading.cpp
    BruteForcing.h
    BruteForcing.cpp
    Hashing.h
    Hashing.cpp
    passwords.txt
    dictionary.txt)

target_link_libraries(PasswordCracking Qt5::Widgets)

include(GNUInstallDirs)
install(TARGETS PasswordCracking
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
