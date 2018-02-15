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

/** @file AuroraFW/GEngine/Input.h
 * Input Header. Contains a class that handles all
 * the input inside a Window object. Also contains
 * all the key codes AuroraFW supports.
 * @since snapshot20170930
 */

#ifndef AURORAFW_GENGINE_INPUT_H
#define AURORAFW_GENGINE_INPUT_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#include <AuroraFW/Internal/Config.h>

#include <AuroraFW/GEngine/_GLFW.h>
#include <AuroraFW/GEngine/Window.h>

#include <list>
#include <functional>

//Max Array Values

#define AFW_GENGINE_INPUT_MAX_KEYS 316
#define AFW_GENGINE_INPUT_KEY_OFFSET 32
#define AFW_GENGINE_INPUT_MAX_MOUSE_BUTTONS 7
#define AFW_GENGINE_INPUT_MOUSE_BUTTONS_OFFSET 0

///Keycodes
//Mouse
#define AFW_GENGINE_MOUSE_BUTTON_1 0
#define AFW_GENGINE_MOUSE_BUTTON_2 1
#define AFW_GENGINE_MOUSE_BUTTON_3 2
#define AFW_GENGINE_MOUSE_BUTTON_4 3
#define AFW_GENGINE_MOUSE_BUTTON_5 4
#define AFW_GENGINE_MOUSE_BUTTON_6 5
#define AFW_GENGINE_MOUSE_BUTTON_7 6
#define AFW_GENGINE_MOUSE_BUTTON_8 7
#define AFW_GENGINE_MOUSE_LEFT AFW_GENGINE_MOUSE_BUTTON_1 /**< The mouse's left button. */
#define AFW_GENGINE_MOUSE_MIDDLE AFW_GENGINE_MOUSE_BUTTON_3 /**< The mouse's middle button. */
#define AFW_GENGINE_MOUSE_RIGHT AFW_GENGINE_MOUSE_BUTTON_2 /**< The mouse's right button. */

#define AFW_GENGINE_KEY_ESC		/**< The Esc (Escape) key.*/
// FIXME: Which Shift key? The left, right or both?
#define AFW_GENGINE_KEY_LEFT_SHIFT 340 /**< The Left Shift key.*/
#define AFW_GENGINE_KEY_RIGHT_SHIFT 344 /**< The Right Shift key.*/
#define AFW_GENGINE_KEY_TAB		/**< The Tab (Tabulation) key.*/
// FIXME: Which Ctrl key? The left, right or both?
#define AFW_GENGINE_KEY_CTRL	/**< The Ctrl (Control) key.*/
#define AFW_GENGINE_KEY_ALT		/**< The Alt key.*/
#define AFW_GENGINE_KEY_SUPER	/**< The Super (Windows logo) key.*/
#define AFW_GENGINE_KEY_SPACE 32 /**< The Space key.*/
#define AFW_GENGINE_KEY_UP		/**< The Up Arrow key.*/
#define AFW_GENGINE_KEY_DOWN	/**< The Down Arrow key.*/
#define AFW_GENGINE_KEY_LEFT	/**< The Left Arrow key.*/
#define AFW_GENGINE_KEY_RIGHT	/**< The Right Arrow key.*/

#define AFW_GENGINE_KEY_INSERT 260 /**< The Insert key..*/
#define AFW_GENGINE_KEY_DELETE 261 /**< The Delete key..*/
#define AFW_GENGINE_KEY_HOME 268 /**< The Home key..*/
#define AFW_GENGINE_KEY_END 269 /**< The End key..*/
#define AFW_GENGINE_KEY_PAGEUP 266 /**< The Page Up key..*/
#define AFW_GENGINE_KEY_PAGEDOWN 267 /**< The Page Down key..*/

//Numbers
#define AFW_GENGINE_KEY_0 48 /**< The 0 key.*/
#define AFW_GENGINE_KEY_1 49 /**< The 1 key.*/
#define AFW_GENGINE_KEY_2 50 /**< The 2 key.*/
#define AFW_GENGINE_KEY_3 51 /**< The 3 key.*/
#define AFW_GENGINE_KEY_4 52 /**< The 4 key.*/
#define AFW_GENGINE_KEY_5 53 /**< The 5 key.*/
#define AFW_GENGINE_KEY_6 54 /**< The 6 key.*/
#define AFW_GENGINE_KEY_7 55 /**< The 7 key.*/
#define AFW_GENGINE_KEY_8 56 /**< The 8 key.*/
#define AFW_GENGINE_KEY_9 57 /**< The 9 key.*/

//Letters
#define AFW_GENGINE_KEY_A 65 /**< The A key.*/
#define AFW_GENGINE_KEY_B 66 /**< The B key.*/
#define AFW_GENGINE_KEY_C 67 /**< The C key.*/
#define AFW_GENGINE_KEY_D 68 /**< The D key.*/
#define AFW_GENGINE_KEY_E 69 /**< The E key.*/
#define AFW_GENGINE_KEY_F 70 /**< The F key.*/
#define AFW_GENGINE_KEY_G 71 /**< The G key.*/
#define AFW_GENGINE_KEY_H 72 /**< The H key.*/
#define AFW_GENGINE_KEY_I 73 /**< The I key.*/
#define AFW_GENGINE_KEY_J 74 /**< The J key.*/
#define AFW_GENGINE_KEY_K 75 /**< The K key.*/
#define AFW_GENGINE_KEY_L 76 /**< The L key.*/
#define AFW_GENGINE_KEY_M 77 /**< The M key.*/
#define AFW_GENGINE_KEY_N 78 /**< The N key.*/
#define AFW_GENGINE_KEY_O 79 /**< The O key.*/
#define AFW_GENGINE_KEY_P 80 /**< The P key.*/
#define AFW_GENGINE_KEY_Q 81 /**< The Q key.*/
#define AFW_GENGINE_KEY_R 82 /**< The R key.*/
#define AFW_GENGINE_KEY_S 83 /**< The S key.*/
#define AFW_GENGINE_KEY_T 84 /**< The T key.*/
#define AFW_GENGINE_KEY_U 85 /**< The U key.*/
#define AFW_GENGINE_KEY_V 86 /**< The V key.*/
#define AFW_GENGINE_KEY_W 87 /**< The W key.*/
#define AFW_GENGINE_KEY_X 88 /**< The X key.*/
#define AFW_GENGINE_KEY_Y 89 /**< The Y key.*/
#define AFW_GENGINE_KEY_Z 90 /**< The Z key.*/

//Function Keys
#define AFW_GENGINE_KEY_F1 290 /**< The F1 key.*/
#define AFW_GENGINE_KEY_F2 291 /**< The F2 key.*/
#define AFW_GENGINE_KEY_F3 292 /**< The F3 key.*/
#define AFW_GENGINE_KEY_F4 293 /**< The F4 key.*/
#define AFW_GENGINE_KEY_F5 294 /**< The F5 key.*/
#define AFW_GENGINE_KEY_F6 295 /**< The F6 key.*/
#define AFW_GENGINE_KEY_F7 296 /**< The F7 key.*/
#define AFW_GENGINE_KEY_F8 297 /**< The F8 key.*/
#define AFW_GENGINE_KEY_F9 298 /**< The F9 key.*/
#define AFW_GENGINE_KEY_F10 299 /**< The F10 key.*/
#define AFW_GENGINE_KEY_F11 230 /**< The F11 key.*/
#define AFW_GENGINE_KEY_F12	231 /**< The F12 key.*/

//Numpad
#define AFW_GENGINE_KEY_NUMLOCK 282 /**< The Num Lock key.*/
#define AFW_GENGINE_KEY_NUMPAD0 320 /**< The Numpad 0 key.*/
#define AFW_GENGINE_KEY_NUMPAD1 321 /**< The Numpad 1 key.*/
#define AFW_GENGINE_KEY_NUMPAD2 322 /**< The Numpad 2 key.*/
#define AFW_GENGINE_KEY_NUMPAD3 323 /**< The Numpad 3 key.*/
#define AFW_GENGINE_KEY_NUMPAD4 324 /**< The Numpad 4 key.*/
#define AFW_GENGINE_KEY_NUMPAD5 325 /**< The Numpad 5 key.*/
#define AFW_GENGINE_KEY_NUMPAD6 326 /**< The Numpad 6 key.*/
#define AFW_GENGINE_KEY_NUMPAD7 327 /**< The Numpad 7 key.*/
#define AFW_GENGINE_KEY_NUMPAD8 328 /**< The Numpad 8 key.*/
#define AFW_GENGINE_KEY_NUMPAD9 329 /**< The Numpad 9 key.*/

namespace AuroraFW {
	namespace GEngine {
		class Window;

		/**
		 * A class that handles user input.
		 * A class that listens to any input ocurred inside a Window object.
		 * @since snapshot20170930
		 */
		class AFW_API InputManager {
		public:
			/**
			 * Constructs an InputManager object associated with the given Window.
			 * @param parent The window's pointer
			 * @see ~InputManager()
			 * @since snapshot20170930
			 */
			InputManager(const Window* );

			/**
			 * Destructs the object
			 * @see InputManager()
			 * @since snapshot20170930
			 */
			~InputManager();

			/**
			 * Checks to see if the given key is being pressed.
			 * @param key The key code to check.
			 * @return <code>true</code> if the key is being pressed. <code>false</code> otherwise.
			 * @see isMouseButtonPressed()
			 * @since snapshot20170930
			 */
			bool isKeyPressed(const uint_t& ) const;

			/**
			 * Checks to see if the given mouse button is being pressed.
			 * @param btn The mouse button code code to check.
			 * @return <code>true</code> if the mouse button is being pressed. <code>false</code> otherwise.
			 * @see isKeyPressed()
			 * @since snapshot20170930
			 */
			bool isMouseButtonPressed(const uint_t& ) const;

			/**
			 * Stores the mouse's current position in the two given variables.
			 * @param x,y The variables to store respectively the mouse's X and Y coordinates.
			 * @see getScrollPosition()
			 * @since snapshot20170930
			 */
			void getMousePosition(double& , double& ) const;

			/**
			 * Not implemented yet, presumably stores the mouse's scroll position in the two given variables.
			 * @see getMousePosition()
			 * @since snapshot20170930
			 */
			void getScrollPosition(const double& , const double& ) const;

		private:
			static void _keyCallback(GLFWwindow* , int , int , int , int );
			static void _mouseButtonCallback(GLFWwindow* , int , int , int );
			static void _cursorPosCallback(GLFWwindow* , double , double );
			static void _scrollCallback(GLFWwindow* , double , double );

			const Window* _parent;
			bool _keys[AFW_GENGINE_INPUT_MAX_KEYS + AFW_GENGINE_INPUT_KEY_OFFSET];
			bool _mouseButtons[AFW_GENGINE_INPUT_MAX_MOUSE_BUTTONS + AFW_GENGINE_INPUT_MOUSE_BUTTONS_OFFSET];
			double _mx, _my;
			std::list <std::function<void(GLFWwindow*, int, int, int, int)>> _keyCallbacks;
			std::list <std::function<void(GLFWwindow*, int, int, int)>> _mouseButtonCallbacks;
			std::list <std::function<void(GLFWwindow*, double, double)>> _cursorPosCallbacks;
			std::list <std::function<void(GLFWwindow*, int)>> _cursorEnterCallbacks;
			std::list <std::function<void(GLFWwindow*, uint)>> _charCallbacks;
			std::list <std::function<void(GLFWwindow*, uint, int)>> _charModsCallbacks;
			std::list <std::function<void(GLFWwindow*, int, const char**)>> _dropCallbacks;
			std::list <std::function<void(GLFWwindow*, int, int)>> _joystickCallbacks;
		};
	}
}

#endif // AURORAFW_GENGINE_INPUT_H
