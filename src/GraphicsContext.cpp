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

#include <AuroraFW/GEngine/GraphicsContext.h>

#include <AuroraFW/CoreLib/Callback.h>
#include <AuroraFW/CoreLib/Allocator.h>
#include <AuroraFW/GEngine/Input.h>

namespace AuroraFW {
	namespace GEngine {
		GraphicsContext::GraphicsContext(std::string name, const API::RenderAPI& api, WindowProperties wp)
		{
			API::Context::setRenderAPI(api);

			_window = AFW_NEW Window(name, wp);
			root = AFW_NEW Root;
			root->inputHandler = std::make_unique<InputManager>(_window);
			root->addRenderer(GEngine::Renderer::Load());
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO(); (void)io;
			_guiLoader = GEngine::ImGuiLoader::Load(_window, root->inputHandler.get());
		}

		GraphicsContext::GraphicsContext(std::string name, const char* path)
		{
			//if(path == AFW_NULLPTR)
		}

		GraphicsContext::~GraphicsContext()
		{
			delete root;
		}

		void GraphicsContext::renderLoop()
		{
			while (!_window->isClosed())
			{
				_frametimer.reset();
				_window->update();
				root->getRenderer()->setViewport(0, 0, _window->getWidth(), _window->getHeight());
				root->getRenderer()->clear();

				_guiLoader->newFrame();

				_internalRender();
				onRender();

				ImGui::Render();
				_guiLoader->renderDrawLists(ImGui::GetDrawData());
				_window->present();
				_tpf = _frametimer.elapsedMillis();
			}
		}

		void GraphicsContext::onRender()
		{}

		void GraphicsContext::_internalRender()
		{

		}

		void GraphicsContext::addInputListener(InputListener* in)
		{
			root->inputHandler->addKeyCallback([in](InputKey key, int scancode, InputAction action, InputMod mods) {
				if(action == InputAction::Pressed)
					in->keyPressed({static_cast<int>(key), scancode, static_cast<ushort>(mods)});
				else if(action == InputAction::Released)
					in->keyReleased({static_cast<int>(key), scancode, static_cast<ushort>(mods)});
			});
			root->inputHandler->addMouseButtonCallback([in](InputButton btn, InputAction action, InputMod mods) {
				if(action == InputAction::Pressed)
					in->mousePressed({static_cast<int>(btn), static_cast<ushort>(mods)});
				else if(action == InputAction::Released)
					in->mouseReleased({static_cast<int>(btn), static_cast<ushort>(mods)});
			});
		}
	}
}
