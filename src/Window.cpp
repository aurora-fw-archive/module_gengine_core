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

#include <AuroraFW/GEngine/Window.h>
#include <AuroraFW/Core/Debug.h>

#include <cstring>

namespace AuroraFW {
	namespace GEngine {
		WindowProperties::WindowProperties(const uint& width, const uint& height, const bool& fullscreen)
			: width(width), height(height), fullscreen(fullscreen)
		{}

		Window::Window(const GEngine::Application& gapp, const char *name, const WindowProperties& wp)
			: _monitor(glfwGetPrimaryMonitor()), _name(name), _width(wp.width), _height(wp.height),
				_fullscreen(wp.fullscreen), _vsync(wp.vsync)
		{
			if (!glfwInit())
				exit(EXIT_FAILURE);

			const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

			if(gapp._gapi == GraphicsAPI::OpenGL) {
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
				#ifdef AFW__DEBUG
					glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
				#endif
			}

			if(_fullscreen || _vsync ||
				_width == 0 || _height == 0) {
				glfwWindowHint(GLFW_RED_BITS, mode->redBits);
				glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
				glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
				glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
			}

			if(_width == 0 || _height == 0) {
				_width = mode->width;
				_height = mode->height;
			}

			if(_fullscreen) {
				if(_vsync) {
					window = glfwCreateWindow(_width, _height, _name, glfwGetPrimaryMonitor(), NULL);
					glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, _width, _height, mode->refreshRate);
				}
				else window = glfwCreateWindow(_width, _height, _name, glfwGetPrimaryMonitor(), NULL);
			} else {
				if(_vsync) {
					window = glfwCreateWindow(_width, _height, _name, NULL, NULL);
					glfwSetWindowMonitor(window, NULL, 0, 0, _width, _height, mode->refreshRate);
				}
				else window = glfwCreateWindow(_width, _height, _name, NULL, NULL);
			}

			if (!window) {
				glfwTerminate();
				exit(EXIT_FAILURE);
			}

			/* Make the window's context current */
			glfwMakeContextCurrent(window);
			if(gapp._gapi == GraphicsAPI::OpenGL) {
				glfwSetWindowSizeCallback(window, [](GLFWwindow *window __attribute__((unused)), int width, int height)
				{
					glViewport(0, 0, width, height);
				});
			}

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
			// Swap front and back buffers
			glfwSwapBuffers(window);
			glfwGetFramebufferSize(window, (int*)&_width, (int*)&_height);

			// Poll for and process events
			glfwPollEvents();
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::isClosed() const
		{
			return glfwWindowShouldClose(window) == 1;
		}
	}
}
