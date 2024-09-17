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


# Define a list of source files
set(Deck_SOURCES
    src/deck.cpp
)

# Add the library with the list of sources
add_executable(Deck ${Deck_SOURCES})


set_target_properties(Deck PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


# Method 3: Set build type specific flags
## Don't push the optimization too far https://clang.llvm.org/docs/CommandGuide/clang.html#cmdoption-O0
set(CMAKE_CXX_FLAGS_DEBUG "-g -O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")



