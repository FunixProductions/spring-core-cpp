# spring-core-cpp
C++ version of the spring core repo. Used to be able to call the spring boot apis in c++ projects

> Version **1.0.0**

## Packages needed

### 1. Install nlohmann/json from the Package Manager

#### Debian
```bash
sudo apt update
sudo apt install nlohmann-json3-dev
```

#### macOS
```bash
brew install nlohmann-json
```

### 2. Install libcurl from the Package Manager

#### Debian
```bash
sudo apt update
sudo apt install libcurl4-openssl-dev
```

#### macOS
```bash
brew install curl
```

## How to build

```bash
mkdir build && cd build
cmake ..
make install
```

## How to use

```cmake
cmake_minimum_required(VERSION 3.15)
project(NewProject VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the FunixProductionsCore package
find_package(FunixProductionsCore REQUIRED)

# Add the executable
add_executable(NewProject main.cpp)

# Link the FunixProductionsCore library
target_link_libraries(NewProject FunixProductions::FunixProductionsCore)
```

## Env variables

```dotenv
FUNIXPRODUCTIONS_API_TOKEN=your_token
```