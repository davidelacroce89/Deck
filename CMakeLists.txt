cmake_minimum_required(VERSION 3.5)


string(TIMESTAMP YEAR "%Y")
string(TIMESTAMP MONTH "%m")
string(TIMESTAMP DAY "%d")
string(TIMESTAMP HOURS "%H")

set(VERSION_STRING "${YEAR}.${MONTH}.${DAY}.${HOURS}")
message(STATUS "Version: ${VERSION_STRING}")

project(Deck VERSION ${VERSION_STRING} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(CVERSION_STRING="${VERSION_STRING}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CATCH2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third/catch2)

add_subdirectory(${CATCH2_SOURCE_DIR})#where to find a CMakeList.txt

# Enable testing and add test executable
enable_testing()

# Define a list of source files
set(Deck_SOURCES
    src/deck.cpp
    test/test_deck.cpp
)

# Add the library with the list of sources
add_executable(Deck ${Deck_SOURCES})

# Link the test executable with Catch2
target_link_libraries(Deck PRIVATE Catch2::Catch2WithMain)


set_target_properties(Deck PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


# Method 3: Set build type specific flags
## Don't push the optimization too far https://clang.llvm.org/docs/CommandGuide/clang.html#cmdoption-O0
set(CMAKE_CXX_FLAGS_DEBUG "-g -O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")


include(CTest)
include(Catch)
catch_discover_tests(Deck)





