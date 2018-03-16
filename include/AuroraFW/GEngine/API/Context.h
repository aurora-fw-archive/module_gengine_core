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

#ifndef AURORAFW_GENGINE_API_CONTEXT_H
#define AURORAFW_GENGINE_API_CONTEXT_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#include <AuroraFW/Internal/Config.h>
#include <AuroraFW/GEngine/Window.h>

namespace AuroraFW {
	namespace GEngine {
		namespace API {
			enum AFW_API RenderAPI
			{
				OpenGL,
				#ifdef AFW_TARGET_PLATFORM_WINDOWS
					Direct3D,
				#endif
					Vulkan
			};

			class AFW_API Context
			{
			protected:
				static Context* _instance;
				static RenderAPI _rapi;
			public:
				static void create(WindowProperties , std::string&);

				static void init(GLFWwindow* );
				static void destroy();

				static RenderAPI getRenderAPI() { return _rapi; }
				static void setRenderAPI(RenderAPI api) { _rapi = api; }

			protected:
				virtual void _init(GLFWwindow* ) = 0;
				virtual void _destroy() = 0;
			};
		}
	}
}

#endif // AURORAFW_GENGINE_CONTEXT_H
