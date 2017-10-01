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
		#define rgb(r,g,b) ((r << 32) | (g << 16) | (b << 8))

		enum class CommonColor : ArUInt32_t {
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
		};

		/** A template struct that represents colors
		 * This struct manipulate colors using a specific data type for color components.
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

		/** A struct that represents colors
		 * 24-bit colors and a 8-bit alpha channel using bytes as color components.
		 */
		typedef BaseColor<ArByte_t> Color;

		/** A struct that represents high precision colors
		 * 96-bit colors and a 32-bit alpha channel using precision floating point as color components.
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

		template<> inline void BaseColor<float>::setRed(float _r)
		{
			r = _r;
		}

		template<> inline void BaseColor<float>::setGreen(float _g)
		{
			g = _g;
		}

		template<> inline void BaseColor<float>::setBlue(float _b)
		{
			b = _b;
		}
		
		template<> inline void BaseColor<float>::setAlpha(float _a)
		{
			a = _a;
		}

		template<> inline void BaseColor<byte>::setRed(int _r)
		{
			r = _r;
		}

		template<> inline void BaseColor<byte>::setGreen(int _g)
		{
			g = _g;
		}

		template<> inline void BaseColor<byte>::setBlue(int _b)
		{
			b = _b;
		}
		
		template<> inline void BaseColor<byte>::setAlpha(int _a)
		{
			a = _a;
		}
	}
}

#endif // AURORAFW_GENGINE_COLOR_H