cmake_minimum_required(VERSION 3.19)
project(5-1QWidget LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(5-1QWidget
    WIN32 MACOSX_BUNDLE
    main.cpp
    rockwidget.h rockwidget.cpp



)

target_link_libraries(5-1QWidget
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(5-1QWidget PRIVATE Qt6::Widgets)

include(GNUInstallDirs)

install(TARGETS 5-1QWidget
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 5-1QWidget
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
