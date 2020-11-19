project(Note C CXX)
cmake_minimum_required(VERSION 3.3.2)

include(cmake/App.cmake)

set(SOURCES "src/Application.h"
            "src/Application.cpp"
            "src/main.cpp")

add_app("${SOURCES}")


if(${PLATFORM} EQUAL linux)
    install(TARGETS ${APP_NAME}
    COMPONENT stickynoteapp
    RUNTIME DESTINATION "/home/"
    LIBRARY DESTINATION "/home/"
    DESTINATION "/home/"
    )

    SET(CPACK_GENERATOR "DEB")
    SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK") #required
endif()

INCLUDE(CPack)

