cmake_minimum_required(VERSION 3.0.0)
project(cv_video_demo VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)

add_executable(opencv_demo main.cpp)

target_link_libraries(opencv_demo PRIVATE
${OpenCV_LIBS}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
