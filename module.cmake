message(STATUS "Loading gengine-core module...")

find_package(glfw3 3.2 REQUIRED)
find_package(CUDA)

if (NOT CONFIGURED_ONCE)
	set(MODULE_GENGINE_CORE_SOURCE_DIR ${MODULE_GENGINE_CORE_DIR}/src)
endif()

if(CUDA_FOUND)
    add_definitions(-DAURORA_NVIDIA_CUDA_FOUND)
endif()

include_directories(${MODULE_GENGINE_CORE_DIR}/include)

add_library (aurora-gengine-core SHARED ${MODULE_GENGINE_CORE_SOURCE_DIR}/Window.cpp
                                        ${MODULE_GENGINE_CORE_SOURCE_DIR}/Application.cpp
                                        ${MODULE_GENGINE_CORE_SOURCE_DIR}/Input.cpp)

target_link_libraries(aurora-gengine-core aurora-gengine-opengl
				      glfw)

set_target_properties(aurora-gengine-core PROPERTIES OUTPUT_NAME aurora-gengine-core)
