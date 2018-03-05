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

namespace AuroraFW {
	namespace GEngine {
		GraphicsContext::GraphicsContext(std::string name, const API::RenderAPI& api, WindowProperties wp)
		{}

		GraphicsContext::~GraphicsContext()
		{
			delete _window;
		}

		void GraphicsContext::renderLoop()
		{
			while (!_window->isClosed())
			{
				_frametimer.reset();
				_window->update();

				_internalRender();
				onRender();

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

		}

		void GraphicsContext::removeInputListener(InputListener* in)
		{
			
		}
	}
}