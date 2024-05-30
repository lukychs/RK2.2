cmake_minimum_required(VERSION 3.10)
project(ClassicObserverExample)

set(CMAKE_CXX_STANDARD 17)

# Укажите все исходные файлы
set(SOURCE_FILES
    AddressObserver.cpp
    AddressObserver.h
    G25_Classic_Observer.cpp
    Main.cpp
    NameObserver.cpp
    NameObserver.h
    Observer.h
    Person.cpp
    Person.h
    tests.cpp
)

add_executable(ClassicObserverExample ${SOURCE_FILES})

# GoogleTest configuration
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
FetchContent_MakeAvailable(googletest)
set(TEST_FILES
    tests.cpp
)

add_executable(RunTests ${TEST_FILES})
target_link_libraries(RunTests gtest gtest_main)
target_link_libraries(RunTests PRIVATE ClassicObserverExample)

# Включение тестов
enable_testing()
add_test(AllTests RunTests)
