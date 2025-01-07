cmake_minimum_required(VERSION 3.15)

# Set the project name
project(FunixProductionsCore VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library
add_library(FunixProductionsCore SHARED
        src/dto/ApiDTO.cpp
        src/dto/PageDTO.cpp
        src/services/ApiService.cpp
)

target_include_directories(FunixProductionsCore PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Find and link CURL
find_package(CURL REQUIRED)
target_link_libraries(FunixProductionsCore CURL::libcurl)

# Find and link nlohmann-json (header-only library)
find_package(nlohmann_json REQUIRED)
target_link_libraries(FunixProductionsCore nlohmann_json::nlohmann_json)

# Export the library target to make it reusable
install(TARGETS FunixProductionsCore
        EXPORT FunixProductionsCoreTargets
        DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include)

# Export the library target to make it reusable
install(EXPORT FunixProductionsCoreTargets
        FILE FunixProductionsCoreTargets.cmake
        NAMESPACE FunixProductions::
        DESTINATION lib/cmake/FunixProductionsCore
)

# Export the include directory
install(EXPORT FunixProductionsCoreTargets
        FILE FunixProductionsCoreTargets.cmake
        NAMESPACE FunixProductions::
        DESTINATION lib/cmake/FunixProductionsCore
)

# Optionally enable testing
option(ENABLE_TESTS "Enable testing" ON)

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
