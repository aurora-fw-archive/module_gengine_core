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

#include <AuroraFW/GEngine/Application.h>

#include <AuroraFW/GEngine/_Vulkan.h>
#include <AuroraFW/GEngine/_Direct3D.h>

#include <iostream>
#include <assert.h>

namespace AuroraFW {
	namespace GEngine {
		Application::Application(const char* name, const API::RenderAPI& api)
			: //vkappinfo(), vkinstanceinfo(), vkinstance(),
			  _name(name)
		{
			API::Context::setRenderAPI(api);
			#if 0
			#ifdef AFW_TARGET_PLATFORM_WINDOWS
				//LPDIRECT3D9 d3d = Direct3DCreate9( D3D_SDK_VERSION );
				//D3DCAPS9 caps;
			#endif
			switch (_gapi)
			{
				case GraphicsAPI::Vulkan:
					// TODO: Implement Vulkan backend
					/*vkappinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
					vkappinfo.pNext = NULL;
					vkappinfo.pApplicationName = name;
					vkappinfo.pEngineName = "Aurora GEngine";
					vkappinfo.engineVersion = AFW_GENGINE_VERSION;
					vkappinfo.apiVersion = VK_API_VERSION_1_0;*/
					break;
			#ifdef AFW_TARGET_PLATFORM_WINDOWS
				// TODO: Implement Direct3D backend
				case GraphicsAPI::Direct3D: break;
			#endif
				case GraphicsAPI::OpenGL: break;
			}
			#endif
		}
		Application::~Application() {}
	}
}
