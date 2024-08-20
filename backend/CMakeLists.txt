cmake_minimum_required(VERSION 3.28)

project(mdl)

set(VERSION 0.0.1)

set(LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32)
elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    add_executable(${PROJECT_NAME} WIN32)
else()
    add_executable(${PROJECT_NAME})
endif()

message(${CMAKE_BUILD_TYPE})

target_sources(${PROJECT_NAME}
    PRIVATE
    "src/main.cpp"
 "src/utils/utils.h" "src/utils/utils.cpp" "src/config/config.cpp" "src/engine/lux.h" "src/engine/ytdlp.h" "src/engine/base.h")

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.11.0
)

FetchContent_MakeAvailable(spdlog)

include_directories("${CMAKE_SOURCE_DIR}/third_party/nlohmann")
include_directories("${PROJECT_SOURCE_DIR}/third_party/webui/include")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(WEBUI_LIB ${PROJECT_SOURCE_DIR}/third_party/webui/debug/webui-2.lib)
    set(WEBUI_DLL ${PROJECT_SOURCE_DIR}/third_party/webui/debug/webui-2.dll)
else()
    set(WEBUI_LIB ${PROJECT_SOURCE_DIR}/third_party/webui/webui-2.lib)
    set(WEBUI_DLL ${PROJECT_SOURCE_DIR}/third_party/webui/webui-2.dll)
endif()

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${WEBUI_LIB}
    spdlog::spdlog
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${WEBUI_DLL}
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

# 复制 src/assets/html 目录下的所有文件到编译输出目录的 resources 目录
file(GLOB_RECURSE HTML_FILES "${CMAKE_SOURCE_DIR}/src/assets/html/*")

foreach(file ${HTML_FILES})
    # 获取文件的相对路径，并生成目标路径
    file(RELATIVE_PATH rel_file ${CMAKE_SOURCE_DIR}/src/assets/html ${file})
    set(dest_file ${CMAKE_BINARY_DIR}/bin/resources/${rel_file})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${file}
        ${dest_file}
    )
endforeach()