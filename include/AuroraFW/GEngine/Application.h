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


#ifndef AURORAFW_GENGINE_APPLICATION_H
#define AURORAFW_GENGINE_APPLICATION_H

#include <AuroraFW/Global.h>
#include <AuroraFW/_GEngine.h>

#include <AuroraFW/GEngine/API.h>
#include <AuroraFW/Core/Application.h>
#include <iostream>

#include <AuroraFW/GEngine/_Vulkan.h>

namespace AuroraFW {
	namespace GEngine {
		class AFW_PREFIX Application {
        friend class Window;
		public:
			Application(const char* , const GraphicsAPI& = GraphicsAPI::OpenGL);
            ~Application();
            Application(const Application&) = delete;
            Application& operator= (const Application&) = delete;
        protected:
            // TODO: Implement Vulkan backend
            /*VkApplicationInfo vkappinfo;
            VkInstanceCreateInfo vkinstanceinfo;
            VkInstance vkinstance;*/

        private:
            const char* _name;
            GraphicsAPI _gapi;
		};
	}
}

#endif // AURORAFW_GENGINE_APPLICATION_H
