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

#ifndef AURORAFW_GENGINE_RENDERER_H
#define AURORAFW_GENGINE_RENDERER_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#include <AuroraFW/Internal/Config.h>

namespace AuroraFW {
	namespace GEngine {
		enum AFW_API RendererBufferType {
			RENDERER_BUFFER_NONE = 0,
			RENDERER_BUFFER_COLOR = AFW_BIT(0),
			RENDERER_BUFFER_DEPTH = AFW_BIT(1),
			RENDERER_BUFFER_STENCIL = AFW_BIT(2)
		};

		class AFW_API Renderer
		{
		public:
			static Renderer* Load();

			virtual void clear(uint ) = 0;
			virtual void setViewport(uint , uint , uint , uint ) = 0;
			virtual void setDepthTesting(bool ) = 0;
			virtual void setBlend(bool ) = 0;
		};
	}
}

#endif // AURORAFW_GENGINE_RENDERER_H