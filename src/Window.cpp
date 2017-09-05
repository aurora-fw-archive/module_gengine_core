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
        WindowProperties::WindowProperties(uint width, uint height, bool fullscreen, bool vsync)
            : width(width), height(height), fullscreen(fullscreen), vsync(vsync)
        {}

        Window::Window(const GEngine::Application& gapp, const char* name, const WindowProperties& wp)
            : window(), monitor(glfwGetPrimaryMonitor()), name(name), width(wp.width), height(wp.height),
              fullscreen(wp.fullscreen), vsync(wp.vsync)
              
        {

            if (!glfwInit())
                exit(EXIT_FAILURE);

            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

            if(fullscreen || vsync ||
               width == 0 || height == 0)
            {
                glfwWindowHint(GLFW_RED_BITS, mode->redBits);
                glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
                glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
                glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
            }

            if(width == 0 || height == 0) {
                width = mode->width;
                height = mode->height;
            }

            if(fullscreen) {
                if(vsync) {
                    window = glfwCreateWindow(width, height, name, glfwGetPrimaryMonitor(), NULL);
                    glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, width, height, mode->refreshRate);
                }
                else window = glfwCreateWindow(width, height, name, glfwGetPrimaryMonitor(), NULL);
            } else {
                if(vsync) {
                    window = glfwCreateWindow(width, height, name, NULL, NULL);
                    glfwSetWindowMonitor(window, NULL, 0, 0, width, height, mode->refreshRate);

                }
                else window = glfwCreateWindow(width, height, name, NULL, NULL);
            }

            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }

            /* Make the window's context current */
            glfwMakeContextCurrent(window);
            if(gapp.gapi == GraphicsAPI::OpenGL) {
                glfwSetWindowSizeCallback(window, [](GLFWwindow* window __attribute__((unused)), int width, int height) {
                    glViewport(0, 0, width, height);
                });
            }

            if(glewInit() != GLEW_OK)
            {
                exit(EXIT_FAILURE);
            }
        }

        void Window::Update() {
            /* Swap front and back buffers */
            glfwSwapBuffers(window);
            glfwGetFramebufferSize(window, (int*)&width, (int*) &height);
            /* Poll for and process events */
            glfwPollEvents();
        }

        void Window::Clear() const {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        bool Window::isClosed() const {
            return glfwWindowShouldClose(window) == 1;
        }

        Window::~Window() {
            glfwDestroyWindow(window);
            glfwTerminate();
        }
    }
}
