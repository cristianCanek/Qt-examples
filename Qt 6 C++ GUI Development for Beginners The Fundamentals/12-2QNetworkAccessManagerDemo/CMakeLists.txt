cmake_minimum_required(VERSION 3.19)
project(12-2QNetworkAccessManagerDemo LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network)

qt_standard_project_setup()

qt_add_executable(12-2QNetworkAccessManagerDemo
    WIN32 MACOSX_BUNDLE
    main.cpp
    widget.cpp
    widget.h
    widget.ui
)

target_link_libraries(12-2QNetworkAccessManagerDemo
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::Network
)

include(GNUInstallDirs)

install(TARGETS 12-2QNetworkAccessManagerDemo
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 12-2QNetworkAccessManagerDemo
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
