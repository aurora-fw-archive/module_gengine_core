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

find_package(CUDA)
find_package(Threads REQUIRED)

if (NOT CONFIGURED_ONCE)
	set(AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR ${AURORAFW_MODULE_GENGINE_CORE_DIR}/src)
endif()

file(GLOB_RECURSE AURORAFW_MODULE_GENGINE_CORE_SOURCE ${AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR}/*.cpp)

if(CUDA_FOUND)
	add_definitions(-DAURORAFW__CUDA_FOUND)
endif()

if(UNIX)
	option(AURORAFW_BUILD_OSMESA "Build window handler for OSMesa" OFF)
endif()

if(UNIX AND NOT APPLE)
	option(AURORAFW_BUILD_WAYLAND "Buld window handler for Wayland" OFF)
	option(AURORAFW_BUILD_MIR "Build window handler for Mir" OFF)
endif()

if(AURORAFW_BUILD_WAYLAND)
	find_package(ECM REQUIRED NO_MODULE)
	list(APPEND CMAKE_MODULE_PATH "${ECM_MODULE_PATH}")

	find_package(Wayland REQUIRED Client Cursor Egl)
	find_package(WaylandScanner REQUIRED)
	find_package(WaylandProtocols 1.12 REQUIRED)

	find_package(XKBCommon REQUIRED)
endif()

if(AURORAFW_BUILD_MIR)
	find_package(Mir REQUIRED)
	find_package(XKBCommon REQUIRED)
endif()

if(AURORAFW_BUILD_OSMESA)
	find_package(OSMesa REQUIRED)
endif()

include_directories(${AURORAFW_MODULE_GENGINE_CORE_DIR}/include ${FreeImage_INCLUDE_DIR})

set(AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR ${AURORAFW_MODULE_GENGINE_CORE_SOURCE_DIR}/GLFW)
file(GLOB AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/*.c)

file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_COCOA ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/Cocoa/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_WIN32 ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/Win32/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_X11 ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/X11/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_WAYLAND ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/Wayland/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_MIR ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/Mir/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_OSMESA ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/OSMesa/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_LINUX ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/Linux/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_NULL ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/NULL/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_POSIX ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/POSIX/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_WGL ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/WGL/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_XKB ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/XKB/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_EGL ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/EGL/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_GLX ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/GLX/*.c)
file(GLOB AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_NSGL ${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/NSGL/*.c)

if(APPLE)
	list(APPEND AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW ${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_COCOA}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_NSGL}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_EGL}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_OSMESA}
		"${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/POSIX/Thread.c")
elseif(WIN32)
	list(APPEND AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW "${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_WIN32}"
		"${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_EGL}"
		"${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_WGL}"
		"${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_OSMESA}")
elseif(UNIX)
	list(APPEND AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW ${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_X11}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_XKB}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_POSIX}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_GLX}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_EGL}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_OSMESA})

	if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
		list(APPEND AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW ${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_LINUX})
	else()
		list(APPEND AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW "${AURORAFW_MODULE_GENGINE_CORE_GLFW_DIR}/NULL/Joystick.c")
	endif()
elseif(AURORAFW_BUILD_WAYLAND)
	list(APPEND AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW ${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_WAYLAND}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_LINUX}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_POSIX}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_XKB}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_EGL}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_OSMESA})

	ecm_add_wayland_client_protocol(AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW
		PROTOCOL
		"${WAYLAND_PROTOCOLS_PKGDATADIR}/stable/xdg-shell/xdg-shell.xml"
		BASENAME xdg-shell)
	ecm_add_wayland_client_protocol(AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW
		PROTOCOL
		"${WAYLAND_PROTOCOLS_PKGDATADIR}/stable/viewporter/viewporter.xml"
		BASENAME viewporter)
	ecm_add_wayland_client_protocol(AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW
		PROTOCOL
		"${WAYLAND_PROTOCOLS_PKGDATADIR}/unstable/relative-pointer/relative-pointer-unstable-v1.xml"
		BASENAME relative-pointer-unstable-v1)
	ecm_add_wayland_client_protocol(AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW
		PROTOCOL
		"${WAYLAND_PROTOCOLS_PKGDATADIR}/unstable/pointer-constraints/pointer-constraints-unstable-v1.xml"
		BASENAME pointer-constraints-unstable-v1)
	ecm_add_wayland_client_protocol(AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW
		PROTOCOL
		"${WAYLAND_PROTOCOLS_PKGDATADIR}/unstable/idle-inhibit/idle-inhibit-unstable-v1.xml"
		BASENAME idle-inhibit-unstable-v1)
elseif(AURORAFW_BUILD_MIR)
	list(APPEND AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW ${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_MIR}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_LINUX}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_POSIX}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_OSMESA}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_EGL}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_XKB})
elseif(AURORAFW_BUILD_OSMESA)
	list(APPEND AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW ${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_OSMESA}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_NULL}
		${AURORORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW_POSIX})
endif()

add_library (aurorafw-gengine-core SHARED ${AURORAFW_MODULE_GENGINE_CORE_SOURCE} ${AURORAFW_MODULE_GENGINE_CORE_SOURCE_GLFW})
aurorafw_add_library_target(aurorafw-gengine-core SHARED)

if(AURORAFW_BUILD_WAYLAND)
	target_compile_definitions(aurorafw-gengine-core PUBLIC ${Wayland_INCLUDE_DIRS} ${XKBCOMMON_INCLUDE_DIRS})
	target_link_libraries(aurorafw-gengine-core ${Wayland_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

	include(CheckIncludeFiles)
	check_include_files(xkbcommon/xkbcommon-compose.h HAVE_XKBCOMMON_COMPOSE_H)

	target_compile_definitions(aurorafw-gengine-core PRIVATE AURORAFW__BUILD_WAYLAND)
elseif(AURORAFW_BUILD_MIR)
	target_include_directories(aurorafw-gengine-core PUBLIC ${MIR_INCLUDE_DIRS} ${XKBCOMMON_INCLUDE_DIRS})
	target_link_libraries(aurorafw-gengine-core ${MIR_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${XKBCOMMON_LIBRARY})

	target_compile_definitions(aurorafw-gengine-core PRIVATE AURORAFW__BUILD_MIR)
elseif(AURORAFW_BUILD_OSMESA)
	target_link_libraries(aurorafw-gengine-core ${CMAKE_THREAD_LIBS_INIT})
	target_compile_definitions(aurorafw-gengine-core PRIVATE AURORAFW__BUILD_OSMESA)
elseif(WIN32)
	target_compile_definitions(aurorafw-gengine-core PRIVATE AURORAFW__BUILD_WIN32)
	target_link_libraries(aurorafw-gengine-core gdi32)
elseif(APPLE)
	target_link_libraries(aurorafw-gengine-core "-framework Cocoa -framework IOKit -framework CoreFoundation -framework CoreVideo")
	target_compile_definitions(aurorafw-gengine-core PRIVATE AURORAFW__BUILD_COCOA)
elseif(UNIX)
	find_package(X11 REQUIRED)

	target_compile_definitions(aurorafw-gengine-core PRIVATE AURORAFW__BUILD_X11)

	# Check for XRandR (modern resolution switching and gamma control)
	if (NOT X11_Xrandr_FOUND)
		message(FATAL_ERROR "The RandR headers were not found")
	endif()

	# Check for Xinerama (legacy multi-monitor support)
	if (NOT X11_Xinerama_FOUND)
		message(FATAL_ERROR "The Xinerama headers were not found")
	endif()

	# Check for Xkb (X keyboard extension)
	if (NOT X11_Xkb_FOUND)
		message(FATAL_ERROR "The X keyboard extension headers were not found")
	endif()

	# Check for Xcursor (cursor creation from RGBA images)
	if (NOT X11_Xcursor_FOUND)
		message(FATAL_ERROR "The Xcursor headers were not found")
	endif()

	target_include_directories(aurorafw-gengine-core PUBLIC ${X11_X11_INCLUDE_PATH}
		${X11_Xrandr_INCLUDE_PATH} ${X11_Xinerama_INCLUDE_PATH} ${X11_Xkb_INCLUDE_PATH}
		${X11_Xcursor_INCLUDE_PATH})

	target_link_libraries(aurorafw-gengine-core ${X11_X11_LIB} ${CMAKE_THREAD_LIBS_INIT})
else()
	message(FATAL_ERROR "No supported platform was detected!")
endif()

if (UNIX AND NOT APPLE)
	find_library(RT_LIBRARY rt)
	mark_as_advanced(RT_LIBRARY)
	if (RT_LIBRARY)
		target_link_libraries(aurorafw-gengine-core ${RT_LIBRARY})
	endif()

	find_library(MATH_LIBRARY m)
	mark_as_advanced(MATH_LIBRARY)
	if (MATH_LIBRARY)
		target_link_libraries(aurorafw-gengine-core ${MATH_LIBRARY})
	endif()

	if (CMAKE_DL_LIBS)
		target_link_libraries(aurorafw-gengine-core ${CMAKE_DL_LIBS})
	endif()
endif()

target_link_libraries(aurorafw-gengine-core aurorafw-gengine-opengl aurorafw-gengine-vulkan aurorafw-io)

set_target_properties(aurorafw-gengine-core PROPERTIES OUTPUT_NAME aurorafw-gengine-core)
