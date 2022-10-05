cmake_minimum_required(VERSION 3.20)
project(GestoreNote)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)


set(SOURCE_FILES Note.h Note.cpp Collection.h Collection.cpp IObserver.h ISubject.h C_Observer.h C_Observer.cpp Menu.h Menu.cpp)
add_executable(GestoreNote main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(GestoreNote core)










