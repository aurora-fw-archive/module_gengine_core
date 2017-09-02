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

#ifndef AURORAFW_GENGINE_INPUT_H
#define AURORAFW_GENGINE_INPUT_H

#include <AuroraFW/Global.h>

#include <AuroraFW/GEngine/Window.h>

//Max Array Values
#define AFW_GENGINE_INPUT_MAX_KEYS    1024
#define AFW_GENGINE_INPUT_MAX_BUTTONS 32

///Keycodes
//Mouse
#define AFW_GENGINE_MOUSE_LEFT
#define AFW_GENGINE_MOUSE_MIDDLE
#define AFW_GENGINE_MOUSE_RIGHT

#define AFW_GENGINE_KEY_ESC
#define AFW_GENGINE_KEY_SHIFT
#define AFW_GENGINE_KEY_TAB
#define AFW_GENGINE_KEY_CTRL
#define AFW_GENGINE_KEY_ALT
#define AFW_GENGINE_KEY_SUPER
#define AFW_GENGINE_KEY_SPACE
#define AFW_GENGINE_KEY_UP
#define AFW_GENGINE_KEY_DOWN
#define AFW_GENGINE_KEY_LEFT
#define AFW_GENGINE_KEY_RIGHT

#define AFW_GENGINE_KEY_INSERT
#define AFW_GENGINE_KEY_DELETE
#define AFW_GENGINE_KEY_END
#define AFW_GENGINE_KEY_HOME
#define AFW_GENGINE_KEY_PAGEUP
#define AFW_GENGINE_KEY_PAGEDOWN

//Numbers
#define AFW_GENGINE_KEY_0
#define AFW_GENGINE_KEY_1
#define AFW_GENGINE_KEY_2
#define AFW_GENGINE_KEY_3
#define AFW_GENGINE_KEY_4
#define AFW_GENGINE_KEY_5
#define AFW_GENGINE_KEY_6
#define AFW_GENGINE_KEY_7
#define AFW_GENGINE_KEY_8
#define AFW_GENGINE_KEY_9

//Letters
#define AFW_GENGINE_KEY_A
#define AFW_GENGINE_KEY_B
#define AFW_GENGINE_KEY_C
#define AFW_GENGINE_KEY_D
#define AFW_GENGINE_KEY_E
#define AFW_GENGINE_KEY_F
#define AFW_GENGINE_KEY_G
#define AFW_GENGINE_KEY_H
#define AFW_GENGINE_KEY_I
#define AFW_GENGINE_KEY_J
#define AFW_GENGINE_KEY_K
#define AFW_GENGINE_KEY_L
#define AFW_GENGINE_KEY_M
#define AFW_GENGINE_KEY_N
#define AFW_GENGINE_KEY_O
#define AFW_GENGINE_KEY_P
#define AFW_GENGINE_KEY_Q
#define AFW_GENGINE_KEY_R
#define AFW_GENGINE_KEY_S
#define AFW_GENGINE_KEY_T
#define AFW_GENGINE_KEY_U
#define AFW_GENGINE_KEY_V
#define AFW_GENGINE_KEY_W
#define AFW_GENGINE_KEY_X
#define AFW_GENGINE_KEY_Y
#define AFW_GENGINE_KEY_Z

//Function Keys
#define AFW_GENGINE_KEY_F1
#define AFW_GENGINE_KEY_F2
#define AFW_GENGINE_KEY_F3
#define AFW_GENGINE_KEY_F4
#define AFW_GENGINE_KEY_F5
#define AFW_GENGINE_KEY_F6
#define AFW_GENGINE_KEY_F7
#define AFW_GENGINE_KEY_F8
#define AFW_GENGINE_KEY_F9
#define AFW_GENGINE_KEY_F10
#define AFW_GENGINE_KEY_F11
#define AFW_GENGINE_KEY_F12

//Numpad
#define AFW_GENGINE_KEY_NUMLOCK
#define AFW_GENGINE_KEY_NUMPAD0
#define AFW_GENGINE_KEY_NUMPAD1
#define AFW_GENGINE_KEY_NUMPAD2
#define AFW_GENGINE_KEY_NUMPAD3
#define AFW_GENGINE_KEY_NUMPAD4
#define AFW_GENGINE_KEY_NUMPAD5
#define AFW_GENGINE_KEY_NUMPAD6
#define AFW_GENGINE_KEY_NUMPAD7
#define AFW_GENGINE_KEY_NUMPAD8
#define AFW_GENGINE_KEY_NUMPAD9

namespace AuroraFW {
    namespace GEngine {
        class Input {
            Input(Window* );
            ~Input();
        public:
            bool isKeyPressed(unsigned int keycode) const;
            bool isButtonPressed(unsigned int button) const;
            void getMousePosition(double& x, double& y) const;
        private:
            bool keys[AFW_GENGINE_INPUT_MAX_KEYS];
            bool buttons[AFW_GENGINE_INPUT_MAX_BUTTONS];
            double mx, my;
        };
    }
}

#endif // AURORAFW_GENGINE_INPUT_H
