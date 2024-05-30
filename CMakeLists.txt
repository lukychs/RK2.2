cmake_minimum_required(VERSION 3.10)
project(ClassicObserverExample)

set(CMAKE_CXX_STANDARD 17)

# Установка опции компиляции -Wno-maybe-uninitialized для файла gtest-death-test.cc
set_source_files_properties(
    _deps/googletest-src/googletest/src/gtest-death-test.cc
    PROPERTIES COMPILE_FLAGS -Wno-maybe-uninitialized
)

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

# Добавление библиотеки Person
add_library(Person STATIC Person.cpp)

# Добавление библиотеки NameObserver
add_library(NameObserver STATIC NameObserver.cpp)

# Добавление библиотеки AddressObserver
add_library(AddressObserver STATIC AddressObserver.cpp)

# Добавление исполняемого файла для тестов
add_executable(RunTests tests.cpp)

# Линковка библиотек с тестовым исполняемым файлом
target_link_libraries(RunTests PRIVATE gtest gtest_main Person NameObserver AddressObserver)

# Включение тестов
enable_testing()
add_test(AllTests RunTests)
