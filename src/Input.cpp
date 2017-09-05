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

#include <AuroraFW/GEngine/Input.h>

namespace AuroraFW {
	namespace GEngine {
		// FIXME: parent argument is never used, see later
		Input::Input(Window* parent __attribute__((unused)))
			// FIXME: mx and my were initialized zero to supress compiler warnings,
			// this may not be the intended behaviour. See later
			:	mx(0), my(0)
		{
			for(int i = 0; i < AFW_GENGINE_INPUT_MAX_KEYS; i++) {
				keys[i] = false;
			}

			for(int i = 0; i < AFW_GENGINE_INPUT_MAX_BUTTONS; i++) {
				buttons[i] = false;
			}
		}

		Input::~Input() {}
	}
}
