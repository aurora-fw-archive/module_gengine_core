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

#ifndef AURORAFW_GENGINE_COLOR_H
#define AURORAFW_GENGINE_COLOR_H

#include <AuroraFW/Global.h>

namespace AuroraFW {
	namespace GEngine {
		enum CommonColor : ArUInt16_t {
			Black = 0x000000,
			Red = 0xFF0000,
			DarkRed = 0x800000,
			Green = 0x00FF00,
			DarkGreen = 0x008000,
			Blue = 0x0000FF,
			DarkBlue = 0x000080,
			Cyan = 0x00FFF,
			DarkCyan = 0x008080,
			Magenta = 0xFF00FF,
			DarkMagenta = 0x800080,
			Yellow = 0xFFFF00,
			DarkYellow = 0x808000,
			White = 0xFFFFFF,
			DarkGray = 0x808080,
			LightGray = 0xC0C0C0,
			Gray = 0xA0A0A0,
			Tomato = 0xFF6347,
			AliceBlue = 0xF0F8FF,
			AntiqueWhite = 0xFAEBD7,
			Aquamarine = 0x7FFFD4,
			Azure = 0xF0FFFF,
			Beige = 0xF5F5DC,
			Bisque = 0xFFE4C4,
			BlanchedAlmond = 0xFFEBCD,
			BlueViolet =0x8A2BE2,
			Brown = 0xA52A2A,
			BurlyWood = 0xDEB887,
			CadetBlue = 0x5F9EA0,
			Chartreuse = 0x7FFF00
		}
		struct Color {
			Color(byte , byte , byte , byte = 0);
			Color(const Color &);
			Color(ArUInt16_t );
			ArByte_t red() const;
			ArByte_t green() const;
			ArByte_t blue() const;
			ArByte_t alpha() const;
			ArVoid_t setRed();
			ArVoid_t setGreen();
			ArVoid_t setBlue();
			ArVoid_t setAlpha();
			ArVoid_t setRGB();

		private:
			byte red, green, blue, alpha;
		};
		Color RGB(byte , byte , byte , byte = 0);
		Color CMYK(int , int , int , int , int , int = 0);
	}
}

#endif // AURORAFW_GENGINE_COLOR_H