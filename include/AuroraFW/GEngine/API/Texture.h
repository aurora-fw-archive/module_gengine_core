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

#ifndef AURORAFW_GENGINE_API_TEXTURE_H
#define AURORAFW_GENGINE_API_TEXTURE_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#include <AuroraFW/Internal/Config.h>

#include <AuroraFW/STDL/STL/String.h>

namespace AuroraFW::GEngine::API {
	class AFW_API Texture {
	public:
		virtual ~Texture() {}

		static Texture* Load(const std::string& );

		virtual void bind(uint = 0) const = 0;
		virtual void unbind(uint = 0) const = 0;
		
		AFW_FORCE_INLINE int width() const { return _width; }
		AFW_FORCE_INLINE int height() const { return _height; }
		AFW_FORCE_INLINE int bpp() const { return _bpp; }

		AFW_FORCE_INLINE byte_t* raw() const { return _rawbuf; }
		AFW_FORCE_INLINE std::string path() const { return _path; }

	protected:
		std::string _path;
		int _width, _height, _bpp;
		byte_t* _rawbuf;
	};
}

#endif // AURORAFW_GENGINE_API_TEXTURE_H