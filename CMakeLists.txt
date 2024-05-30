cmake_minimum_required(VERSION 3.10)
project(ClassicObserverExample)

set(CMAKE_CXX_STANDARD 11)

# Укажите все исходные файлы
set(SOURCES
    AdressObserver.cpp
    AdressObserver.h
    G25_Classic_Observer.cpp
    Main.cpp
    NameObserver.cpp
    NameObserver.h
    Observer.h
    Person.cpp
    Person.h
)

add_executable(ClassicObserverExample ${SOURCES})

# GoogleTest configuration
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Добавьте тесты для каждого примера
add_executable(runTests test.cpp)
target_link_libraries(runTests gtest gtest_main)
add_test(NAME runTests COMMAND runTests)
