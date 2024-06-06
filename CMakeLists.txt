cmake_minimum_required(VERSION 3.10)
project(ClassicObserverExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
    URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Добавление общей библиотеки ClassicObserverLib
add_library(ClassicObserverLib STATIC
    Person.cpp
    NameObserver.cpp
    AddressObserver.cpp
)

# Линковка общей библиотеки с основным исполняемым файлом
target_link_libraries(ClassicObserverExample PRIVATE ClassicObserverLib)

# Добавление исполняемого файла для тестов
add_executable(RunTests tests.cpp)

# Линковка общей библиотеки с тестовым исполняемым файлом
target_link_libraries(RunTests PRIVATE gtest gtest_main ClassicObserverLib)

# Отключение предупреждений для GoogleTest
target_compile_options(gtest PRIVATE -Wno-maybe-uninitialized)

# Включение тестов
enable_testing()
add_test(AllTests RunTests)

# Добавление исполняемого файла mt для Main.cpp и всех библиотек
add_executable(mt Main.cpp)
target_link_libraries(mt PRIVATE ClassicObserverLib)
