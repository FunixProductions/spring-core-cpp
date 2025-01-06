cmake_minimum_required(VERSION 3.15)

# Set the project name
project(FunixProductionsCore VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library
add_library(FunixProductionsCore STATIC
        src/dto/ApiDTO.cpp
        src/services/ApiService.cpp
)

# Add the include directories for the libraries
# jsonParsing : https://github.com/nlohmann/json
include_directories(libs)

# Specify the include directories for the library
target_include_directories(FunixProductionsCore PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Optionally enable testing
option(ENABLE_TESTS "Enable testing" ON)

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
