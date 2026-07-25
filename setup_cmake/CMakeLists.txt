# Yêu cầu CMake 3.25 trở lên vì các phiên bản cũ hơn có thể chưa hỗ trợ flag C++26
cmake_minimum_required(VERSION 3.25)

# Tên project của bạn
project(MyProject LANGUAGES CXX)

# ==========================================
# 1. Yêu cầu C++26
# ==========================================
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Tắt các extension đặc thù của compiler (tuỳ chọn nhưng nên dùng để code chuẩn)
set(CMAKE_CXX_EXTENSIONS OFF) 

# ==========================================
# 2. Hỗ trợ Debug
# ==========================================
# Nếu khi chạy CMake không chỉ định build type, mặc định sẽ là Debug
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()


# ==========================================
# 3. Hỗ trợ compile nhiều file
# ==========================================
# Tự động quét và lấy tất cả các file .cpp trong thư mục hiện tại 
# và trong thư mục con src/ (nếu bạn có chia thư mục)
file(GLOB SOURCES 
    "*.cpp" 
    "utils/*.cpp"
)

# Tạo file thực thi (executable) từ danh sách các file vừa gom
add_executable(${PROJECT_NAME} ${SOURCES})
# Hỗ trợ chỉ định chọn đúng file
# add_executable(AI_Agent ${PROJECT_SOURCE_DIR}/src/main.cpp ${SOURCE_FILES})