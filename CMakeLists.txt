cmake_minimum_required(VERSION 3.10)
project(ClassicObserverExample)

set(CMAKE_CXX_STANDARD 17)

# Укажите все исходные файлы
set(SOURCE_FILES
    AddressObserver.cpp
    Main.cpp
    NameObserver.cpp
    Person.cpp
)

add_executable(ClassicObserverExample ${SOURCE_FILES})

# GoogleTest configuration
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Тестовые файлы
set(TEST_FILES
    tests.cpp
)

# Добавление тестового исполняемого файла
add_executable(RunTests ${TEST_FILES})

# Линковка Google Test и вашего кода для тестов
target_link_libraries(RunTests PRIVATE gtest gtest_main)
target_link_libraries(RunTests PRIVATE Person NameObserver AddressObserver)

# Включение тестов
enable_testing()
add_test(AllTests RunTests)
