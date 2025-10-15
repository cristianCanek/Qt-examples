cmake_minimum_required(VERSION 3.19)
project(5-13QList LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(5-13QList
    main.cpp
)

target_link_libraries(5-13QList
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS 5-13QList
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
