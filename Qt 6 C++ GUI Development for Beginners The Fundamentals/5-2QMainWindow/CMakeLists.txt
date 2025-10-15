cmake_minimum_required(VERSION 3.19)
project(5-2QMainWindow LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(5-2QMainWindow
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.h mainwindow.cpp
)

target_link_libraries(5-2QMainWindow
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(5-2QMainWindow PRIVATE Qt6::Widgets)

include(GNUInstallDirs)

install(TARGETS 5-2QMainWindow
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 5-2QMainWindow
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
