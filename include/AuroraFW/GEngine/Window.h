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

#ifndef AURORAFW_GENGINE_WINDOW_H
#define AURORAFW_GENGINE_WINDOW_H

#include <AuroraFW/Global.h>

#include <AuroraFW/GEngine/Application.h>
#include <AuroraFW/GEngine/OpenGL.h>
#include <AuroraFW/GEngine/Input.h>

#include <AuroraFW/GEngine/_GLEW.h>
#include <AuroraFW/GEngine/_OpenGL.h>
#include <AuroraFW/GEngine/_Vulkan.h>
#include <AuroraFW/GEngine/_GLFW.h>

//typedef struct GLFWwindow GLFWwindow;
//typedef struct GLFWmonitor GLFWmonitor;

namespace AuroraFW {
    namespace GEngine {
        struct AFW_PREFIX WindowProperties {
            WindowProperties(const uint& , const uint& , const bool& = false, const bool& = false);
            uint width, height;
		    bool fullscreen;
            bool vsync;
        };

        class InputManager;

        class AFW_PREFIX Window
        {
            friend InputManager;
        	public:
        		Window(const GEngine::Application& , const char* , const WindowProperties& );
                ~Window();
                Window(const Window&) = delete;
                Window& operator=(const Window&) = delete;
                void Update();
                void Clear() const;
                bool isClosed() const;
                inline uint getWidth() const { return _width; }
                inline uint getHeight() const { return _height; }

            protected:
                GLFWwindow *window;

        	private:
                //void Init();
                const GLFWmonitor *_monitor;
                const char *_name;
                uint _width, _height;
                const bool _fullscreen, _vsync;
        };
    }
}

#endif // AURORAFW_GENGINE_WINDOW_H
