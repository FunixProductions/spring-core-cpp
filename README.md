# spring-core-cpp
C++ version of the spring core repo. Used to be able to call the spring boot apis in c++ projects

## Packages needed

### 1. Install nlohmann/json from the Package Manager

#### Debian
```bash
sudo apt update
sudo apt install nlohmann-json-dev
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
cmake --build . --config Release
cmake --install . --prefix /path/to/install
```

## Env variables

```dotenv
FUNIXPRODUCTIONS_API_TOKEN=your_token
```