cmake_minimum_required(VERSION 3.16)

project(BBank LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WIN32_EXECUTABLE FALSE)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(BBank
  main.cpp
  card.h card.cpp
  bank.h bank.cpp
  client.h client.cpp
  menu.h menu.cpp

)
target_link_libraries(BBank Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS BBank
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
