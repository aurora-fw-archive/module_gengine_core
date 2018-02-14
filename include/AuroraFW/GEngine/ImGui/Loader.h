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

#ifndef AURORAFW_GENGINE_IMGUI_LOADER_H
#define AURORAFW_GENGINE_IMGUI_LOADER_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#include <AuroraFW/Internal/Config.h>

#include <AuroraFW/GEngine/Window.h>
#include <AuroraFW/GEngine/ImGui/ImGui.h>

namespace AuroraFW {
	namespace GEngine {
		class AFW_API ImGuiLoader {
		public:
			static ImGuiLoader* Load(Window* , InputManager* );
			void Unload();

			void newFrame();
			void invalidateDeviceObjects();
			bool createDeviceObjects();
		private:
			void _mouseButtonCallback(GLFWwindow* , int , int , int );
			static void _scrollCallback(GLFWwindow* , double , double );
			static void _keyCallback(GLFWwindow* , int , int , int , int );
			static void _charCallback(GLFWwindow* , uint );

			virtual void _renderDrawLists(ImDrawData *) = 0;
			static void _setClipboardText(void* , const char* );
			static const char* _getClipboardText(void *);

			GLFWwindow* _window = AFW_NULLPTR;
			bool _mousePressed[3] = {false, false, false};
		};
	}
}

#endif // AURORAFW_GENGINE_IMGUI_LOADER_H