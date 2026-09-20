cmake_minimum_required(VERSION 3.15)
project(VulkanSandbox)

# use c++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glm CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_package(Vulkan REQUIRED)
find_package(VulkanHeaders CONFIG)


# exec
file(GLOB_RECURSE sandbox_sources CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(sandbox ${sandbox_sources})

target_include_directories(sandbox PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)


target_link_libraries(sandbox PRIVATE glm::glm)
target_link_libraries(sandbox PRIVATE SDL3::SDL3)
target_link_libraries(sandbox PRIVATE Vulkan::Vulkan)
target_link_libraries(sandbox PRIVATE Vulkan::Headers)



set_target_properties(sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
