# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
# A Powerful General Purpose Framework
# More information in: https://aurora-fw.github.io/
#
# Copyright (C) 2017 Aurora Framework, All rights reserved.
#
# This file is part of the Aurora Framework. This framework is free
# software; you can redistribute it and/or modify it under the terms of
# the GNU Lesser General Public License version 3 as published by the
# Free Software Foundation and appearing in the file LICENSE included in
# the packaging of this file. Please review the following information to
# ensure the GNU Lesser General Public License version 3 requirements
# will be met: https://www.gnu.org/licenses/lgpl-3.0.html.

message(STATUS "Loading gengine-core module...")

find_package(glfw3 3.2 REQUIRED)
find_package(CUDA)

if (NOT CONFIGURED_ONCE)
	set(AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR ${AURORAFW_MODULE_GENGINE_CORE_DIR}/src)
endif()

if(CUDA_FOUND)
	add_definitions(-DAURORA_NVIDIA_CUDA_FOUND)
endif()

include_directories(${AURORAFW_MODULE_GENGINE_CORE_DIR}/include)

add_library (aurorafw-gengine-core SHARED ${AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR}/Window.cpp
										${AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR}/Application.cpp
										${AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR}/Input.cpp
										${AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR}/AssetManager.cpp
										${AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR}/Color.cpp
								)

target_link_libraries(aurorafw-gengine-core aurorafw-gengine-opengl
					  glfw)

set_target_properties(aurorafw-gengine-core PROPERTIES OUTPUT_NAME aurorafw-gengine-core)
