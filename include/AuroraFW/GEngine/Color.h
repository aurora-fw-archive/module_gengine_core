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
		/**
		 * Converts 3 bytes into a hex color code (uint32)
		 * @param r g b The 3 bytes each corresponding to red, green, and blue values
		 * @since snapshot20170930
		 */
		#define rgb(r,g,b) ((r << 32) | (g << 16) | (b << 8))

		/**
		 * An enum that stores hex-coded colors to be used generally.
		 * @since snapshot20170930
		 */
		enum class CommonColor : ArUInt32_t {
			Black = 0x000000,			/**< <code>0x000000 = </code><span style="background-color:#000000;color:#000000;border:1px solid black">color</span> */
			Red = 0xFF0000,				/**< <code>0xFF0000 = </code><span style="background-color:#FF0000;color:#FF0000;border:1px solid black">color</span> */
			DarkRed = 0x800000,			/**< <code>0x800000 = </code><span style="background-color:#800000;color:#800000;border:1px solid black">color</span> */
			Green = 0x00FF00,			/**< <code>0x00FF00 = </code><span style="background-color:#00FF00;color:#00FF00;border:1px solid black">color</span> */
			DarkGreen = 0x008000,		/**< <code>0x008000 = </code><span style="background-color:#008000;color:#008000;border:1px solid black">color</span> */
			Blue = 0x0000FF,			/**< <code>0x0000FF = </code><span style="background-color:#0000FF;color:#0000FF;border:1px solid black">color</span> */
			DarkBlue = 0x000080,		/**< <code>0x000080 = </code><span style="background-color:#000080;color:#000080;border:1px solid black">color</span> */
			Cyan = 0x00FFFF,			/**< <code>0x00FFFF = </code><span style="background-color:#00FFFF;color:#00FFFF;border:1px solid black">color</span> */
			DarkCyan = 0x008080,		/**< <code>0x008080 = </code><span style="background-color:#008080;color:#008080;border:1px solid black">color</span> */
			Magenta = 0xFF00FF,			/**< <code>0xFF00FF = </code><span style="background-color:#FF00FF;color:#FF00FF;border:1px solid black">color</span> */
			DarkMagenta = 0x800080,		/**< <code>0x800080 = </code><span style="background-color:#800080;color:#800080;border:1px solid black">color</span> */
			Yellow = 0xFFFF00,			/**< <code>0xFFFF00 = </code><span style="background-color:#FFFF00;color:#FFFF00;border:1px solid black">color</span> */
			DarkYellow = 0x808000,		/**< <code>0x808000 = </code><span style="background-color:#808000;color:#808000;border:1px solid black">color</span> */
			White = 0xFFFFFF,			/**< <code>0xFFFFFF = </code><span style="background-color:#FFFFFF;color:#FFFFFF;border:1px solid black">color</span> */
			DarkGray = 0x808080,		/**< <code>0x808080 = </code><span style="background-color:#808080;color:#808080;border:1px solid black">color</span> */
			LightGray = 0xC0C0C0,		/**< <code>0xC0C0C0 = </code><span style="background-color:#C0C0C0;color:#C0C0C0;border:1px solid black">color</span> */
			Gray = 0xA0A0A0,			/**< <code>0xA0A0A0 = </code><span style="background-color:#A0A0A0;color:#A0A0A0;border:1px solid black">color</span> */
			Tomato = 0xFF6347,			/**< <code>0xFF6347 = </code><span style="background-color:#FF6347;color:#FF6347;border:1px solid black">color</span> */
			AliceBlue = 0xF0F8FF,		/**< <code>0xF0F8FF = </code><span style="background-color:#F0F8FF;color:#F0F8FF;border:1px solid black">color</span> */
			AntiqueWhite = 0xFAEBD7,	/**< <code>0xFAEBD7 = </code><span style="background-color:#FAEBD7;color:#FAEBD7;border:1px solid black">color</span> */
			Aquamarine = 0x7FFFD4,		/**< <code>0x7FFFD4 = </code><span style="background-color:#7FFFD4;color:#7FFFD4;border:1px solid black">color</span> */
			Azure = 0xF0FFFF,			/**< <code>0xF0FFFF = </code><span style="background-color:#F0FFFF;color:#F0FFFF;border:1px solid black">color</span> */
			Beige = 0xF5F5DC,			/**< <code>0xF5F5DC = </code><span style="background-color:#F5F5DC;color:#F5F5DC;border:1px solid black">color</span> */
			Bisque = 0xFFE4C4,			/**< <code>0xFFE4C4 = </code><span style="background-color:#FFE4C4;color:#FFE4C4;border:1px solid black">color</span> */
			BlanchedAlmond = 0xFFEBCD,	/**< <code>0xFFEBCD = </code><span style="background-color:#FFEBCD;color:#FFEBCD;border:1px solid black">color</span> */
			BlueViolet =0x8A2BE2,		/**< <code>0x8A2BE2 = </code><span style="background-color:#8A2BE2;color:#8A2BE2;border:1px solid black">color</span> */
			Brown = 0xA52A2A,			/**< <code>0xA52A2A = </code><span style="background-color:#A52A2A;color:#A52A2A;border:1px solid black">color</span> */
			BurlyWood = 0xDEB887,		/**< <code>0xDEB887 = </code><span style="background-color:#DEB887;color:#DEB887;border:1px solid black">color</span> */
			CadetBlue = 0x5F9EA0,		/**< <code>0x5F9EA0 = </code><span style="background-color:#5F9EA0;color:#5F9EA0;border:1px solid black">color</span> */
			Chartreuse = 0x7FFF00		/**< <code>0x7FFF00 = </code><span style="background-color:#7FFF00;color:#7FFF00;border:1px solid black">color</span> */
		};

		/**
		 * A template struct that represents colors.
		 * This struct manipulates colors using a specific data type for color components.
		 * @since snapshot20170930
		 */
		template<class T>
		struct BaseColor {
			BaseColor(ArInt_t , ArInt_t , ArInt_t , ArInt_t = 255);
			BaseColor(ArFloat_t , ArFloat_t , ArFloat_t , ArFloat_t = 1.0f);
			BaseColor(ArUInt32_t );
			BaseColor(CommonColor );
			explicit BaseColor(const BaseColor<T> &);
			ArInt_t red() const;
			ArFloat_t redF() const;
			ArInt_t green() const;
			ArFloat_t greenF() const;
			ArInt_t blue() const;
			ArFloat_t blueF() const;
			ArInt_t alpha() const;
			ArFloat_t alphaF() const;
			ArVoid_t setRed(ArInt_t );
			ArVoid_t setRed(ArFloat_t );
			ArVoid_t setGreen(ArInt_t );
			ArVoid_t setGreen(ArFloat_t );
			ArVoid_t setBlue(ArInt_t );
			ArVoid_t setBlue(ArFloat_t );
			ArVoid_t setAlpha(ArInt_t );
			ArVoid_t setAlpha(ArFloat_t );
			ArVoid_t setRGB(ArUInt32_t );
			ArVoid_t setRGB(ArInt_t[3] );
			ArVoid_t setRGBA(ArInt_t[4] );

			static BaseColor<T> CMYK(ArInt_t , ArInt_t , ArInt_t , ArInt_t , ArInt_t = 255);
			static BaseColor<T> CMYK(ArFloat_t , ArFloat_t , ArFloat_t , ArFloat_t = 1.0f);
			static BaseColor<T> HSL(ArInt_t , ArInt_t , ArInt_t , ArInt_t= 255);
			static BaseColor<T> HSL(ArFloat_t , ArFloat_t , ArFloat_t , ArFloat_t = 1.0f);
			static BaseColor<T> HSV(ArInt_t , ArInt_t , ArInt_t , ArInt_t = 255);
			static BaseColor<T> HSV(ArFloat_t , ArFloat_t , ArFloat_t , ArFloat_t = 1.0f);

			T r, g, b, a;
		};

		/**
		 * A struct that represents colors
		 * 24-bit colors and a 8-bit alpha channel using bytes as color components.
		 * @since snapshot20170930
		 */
		typedef BaseColor<ArByte_t> Color;

		/**
		 * A struct that represents high precision colors
		 * 96-bit colors and a 32-bit alpha channel using precision floating point as color components.
		 * @since snapshot20170930
		 */
		typedef BaseColor<ArFloat_t> ColorF;

		//Inline definitions
		template<> inline int BaseColor<byte>::red() const
		{
			return r;
		}
		template<> inline int BaseColor<byte>::green() const
		{
			return g;
		}
		template<> inline int BaseColor<byte>::blue() const
		{
			return b;
		}
		template<> inline int BaseColor<byte>::alpha() const
		{
			return a;
		}

		template<> inline float BaseColor<float>::redF() const
		{
			return r;
		}

		template<> inline float BaseColor<float>::greenF() const
		{
			return g;
		}

		template<> inline float BaseColor<float>::blueF() const
		{
			return b;
		}

		template<> inline float BaseColor<float>::alphaF() const
		{
			return a;
		}
	}
}

#endif // AURORAFW_GENGINE_COLOR_H