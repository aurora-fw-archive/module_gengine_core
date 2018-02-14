/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#include <AuroraFW/GEngine/GL/Global.h>

#include <AuroraFW/GEngine/Window.h>
#include <AuroraFW/Core/DebugManager.h>
#include <AuroraFW/GEngine/API/Context.h>

namespace AuroraFW {
	namespace GEngine {
		WindowProperties::WindowProperties(const uint& width, const uint& height, const bool& fullscreen)
			: width(width), height(height), fullscreen(fullscreen)
		{}

		Window::Window(const char *name, const WindowProperties& wp)
			: _monitor(glfwGetPrimaryMonitor()), _name(name), _width(wp.width), _height(wp.height),
				_fullscreen(wp.fullscreen), _vsync(wp.vsync)
		{
			if (!glfwInit())
				exit(EXIT_FAILURE);

			const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

			glfwDefaultWindowHints();

			glfwWindowHint(GLFW_SAMPLES, wp.samples);
			glfwWindowHint(GLFW_DOUBLEBUFFER, wp.doubleBuffer);
			glfwWindowHint(GLFW_SRGB_CAPABLE, wp.sRGB);
			glfwWindowHint(GLFW_STEREO, wp.stereo);
			glfwWindowHint(GLFW_RESIZABLE, wp.resizable);
			glfwWindowHint(GLFW_VISIBLE, wp.visible);
			glfwWindowHint(GLFW_DECORATED, wp.decorated);
			glfwWindowHint(GLFW_FOCUSED, wp.focused);
			glfwWindowHint(GLFW_AUTO_ICONIFY, wp.autoIconify);
			glfwWindowHint(GLFW_REFRESH_RATE, wp.refreshRate);
			glfwWindowHint(GLFW_AUX_BUFFERS, wp.auxBuffers);
			glfwWindowHint(GLFW_FLOATING, wp.floating);
			glfwWindowHint(GLFW_MAXIMIZED, wp.maximized);

			API::Context::create(wp);

			glfwWindowHint(GLFW_RED_BITS, mode->redBits);
			glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

			if(_width == 0 || _height == 0) {
				_width = mode->width;
				_height = mode->height;
			}

			if(_fullscreen) {
				if(_vsync) {
					window = glfwCreateWindow(_width, _height, _name, glfwGetPrimaryMonitor(), NULL);
					glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, _width, _height, mode->refreshRate);
				}
				else {
					window = glfwCreateWindow(_width, _height, _name, glfwGetPrimaryMonitor(), NULL);
				}
			} else {
				if(_vsync) {
					window = glfwCreateWindow(_width, _height, _name, NULL, NULL);
					glfwSetWindowMonitor(window, NULL, 0, 0, _width, _height, mode->refreshRate);
				}
				else {
					window = glfwCreateWindow(_width, _height, _name, NULL, NULL);
				}
			}

			if (!window) {
				glfwTerminate();
				exit(EXIT_FAILURE);
			}

			/* Make the window's context current */
			glfwMakeContextCurrent(window);

			glewExperimental=GL_TRUE;

			if(glewInit() != GLEW_OK) {
				exit(EXIT_FAILURE);
			}
		}

		Window::~Window()
		{
			glfwDestroyWindow(window);
			glfwTerminate();
		}

		void Window::update()
		{
			if(!_vsync) glfwSwapInterval(0);
			// Swap front and back buffers
			glfwSwapBuffers(window);
			glfwGetFramebufferSize(window, (int*)&_width, (int*)&_height);

			// Poll for and process events
			glfwPollEvents();
		}

		bool Window::isClosed() const
		{
			return glfwWindowShouldClose(window) == 1;
		}
	}
}