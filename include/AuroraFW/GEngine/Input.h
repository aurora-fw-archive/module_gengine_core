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

#include <AuroraFW/GEngine/Window.h>

#include <AuroraFW/GEngine/_GLFW.h>

//Max Array Values

#define AFW_GENGINE_INPUT_MAX_KEYS    1024
#define AFW_GENGINE_INPUT_MAX_MOUSE_BUTTONS 32

///Keycodes
//Mouse
#define AFW_GENGINE_MOUSE_LEFT		/**< The mouse's left button. */
#define AFW_GENGINE_MOUSE_MIDDLE	/**< The mouse's middle button. */
#define AFW_GENGINE_MOUSE_RIGHT		/**< The mouse's right button. */

#define AFW_GENGINE_KEY_ESC		/**< The Esc (Escape) key.*/
// FIXME: Which Shift key? The left, right or both?
#define AFW_GENGINE_KEY_SHIFT	/**< The Shift key.*/
#define AFW_GENGINE_KEY_TAB		/**< The Tab (Tabulation) key.*/
// FIXME: Which Ctrl key? The left, right or both?
#define AFW_GENGINE_KEY_CTRL	/**< The Ctrl (Control) key.*/
#define AFW_GENGINE_KEY_ALT		/**< The Alt key.*/
#define AFW_GENGINE_KEY_SUPER	/**< The Super (Windows logo) key.*/
#define AFW_GENGINE_KEY_SPACE	/**< The Space key.*/
#define AFW_GENGINE_KEY_UP		/**< The Up Arrow key.*/
#define AFW_GENGINE_KEY_DOWN	/**< The Down Arrow key.*/
#define AFW_GENGINE_KEY_LEFT	/**< The Left Arrow key.*/
#define AFW_GENGINE_KEY_RIGHT	/**< The Right Arrow key.*/

#define AFW_GENGINE_KEY_INSERT		/**< The Insert key..*/
#define AFW_GENGINE_KEY_DELETE		/**< The Delete key..*/
#define AFW_GENGINE_KEY_END			/**< The End key..*/
#define AFW_GENGINE_KEY_HOME		/**< The Home key..*/
#define AFW_GENGINE_KEY_PAGEUP		/**< The Page Up key..*/
#define AFW_GENGINE_KEY_PAGEDOWN	/**< The Page Down key..*/

//Numbers
#define AFW_GENGINE_KEY_0	/**< The 0 key.*/
#define AFW_GENGINE_KEY_1	/**< The 1 key.*/
#define AFW_GENGINE_KEY_2	/**< The 2 key.*/
#define AFW_GENGINE_KEY_3	/**< The 3 key.*/
#define AFW_GENGINE_KEY_4	/**< The 4 key.*/
#define AFW_GENGINE_KEY_5	/**< The 5 key.*/
#define AFW_GENGINE_KEY_6	/**< The 6 key.*/
#define AFW_GENGINE_KEY_7	/**< The 7 key.*/
#define AFW_GENGINE_KEY_8	/**< The 8 key.*/
#define AFW_GENGINE_KEY_9	/**< The 9 key.*/

//Letters
#define AFW_GENGINE_KEY_A	/**< The A key.*/
#define AFW_GENGINE_KEY_B	/**< The B key.*/
#define AFW_GENGINE_KEY_C	/**< The C key.*/
#define AFW_GENGINE_KEY_D	/**< The D key.*/
#define AFW_GENGINE_KEY_E	/**< The E key.*/
#define AFW_GENGINE_KEY_F	/**< The F key.*/
#define AFW_GENGINE_KEY_G	/**< The G key.*/
#define AFW_GENGINE_KEY_H	/**< The H key.*/
#define AFW_GENGINE_KEY_I	/**< The I key.*/
#define AFW_GENGINE_KEY_J	/**< The J key.*/
#define AFW_GENGINE_KEY_K	/**< The K key.*/
#define AFW_GENGINE_KEY_L	/**< The L key.*/
#define AFW_GENGINE_KEY_M	/**< The M key.*/
#define AFW_GENGINE_KEY_N	/**< The N key.*/
#define AFW_GENGINE_KEY_O	/**< The O key.*/
#define AFW_GENGINE_KEY_P	/**< The P key.*/
#define AFW_GENGINE_KEY_Q	/**< The Q key.*/
#define AFW_GENGINE_KEY_R	/**< The R key.*/
#define AFW_GENGINE_KEY_S	/**< The S key.*/
#define AFW_GENGINE_KEY_T	/**< The T key.*/
#define AFW_GENGINE_KEY_U	/**< The U key.*/
#define AFW_GENGINE_KEY_V	/**< The V key.*/
#define AFW_GENGINE_KEY_W	/**< The W key.*/
#define AFW_GENGINE_KEY_X	/**< The X key.*/
#define AFW_GENGINE_KEY_Y	/**< The Y key.*/
#define AFW_GENGINE_KEY_Z	/**< The Z key.*/

//Function Keys
#define AFW_GENGINE_KEY_F1	/**< The F1 key.*/
#define AFW_GENGINE_KEY_F2	/**< The F2 key.*/
#define AFW_GENGINE_KEY_F3	/**< The F3 key.*/
#define AFW_GENGINE_KEY_F4	/**< The F4 key.*/
#define AFW_GENGINE_KEY_F5	/**< The F5 key.*/
#define AFW_GENGINE_KEY_F6	/**< The F6 key.*/
#define AFW_GENGINE_KEY_F7	/**< The F7 key.*/
#define AFW_GENGINE_KEY_F8	/**< The F8 key.*/
#define AFW_GENGINE_KEY_F9	/**< The F9 key.*/
#define AFW_GENGINE_KEY_F10	/**< The F10 key.*/
#define AFW_GENGINE_KEY_F11	/**< The F11 key.*/
#define AFW_GENGINE_KEY_F12	/**< The F12 key.*/

//Numpad
#define AFW_GENGINE_KEY_NUMLOCK		/**< The Num Lock key.*/
#define AFW_GENGINE_KEY_NUMPAD0		/**< The Numpad 0 key.*/
#define AFW_GENGINE_KEY_NUMPAD1		/**< The Numpad 1 key.*/
#define AFW_GENGINE_KEY_NUMPAD2		/**< The Numpad 2 key.*/
#define AFW_GENGINE_KEY_NUMPAD3		/**< The Numpad 3 key.*/
#define AFW_GENGINE_KEY_NUMPAD4		/**< The Numpad 4 key.*/
#define AFW_GENGINE_KEY_NUMPAD5		/**< The Numpad 5 key.*/
#define AFW_GENGINE_KEY_NUMPAD6		/**< The Numpad 6 key.*/
#define AFW_GENGINE_KEY_NUMPAD7		/**< The Numpad 7 key.*/
#define AFW_GENGINE_KEY_NUMPAD8		/**< The Numpad 8 key.*/
#define AFW_GENGINE_KEY_NUMPAD9		/**< The Numpad 9 key.*/

namespace AuroraFW {
	namespace GEngine {
		class Window;

		/**
		 * A class that handles user input.
		 * A class that listens to any input ocurred inside a Window object.
		 * @since snapshot20170930
		 */
		class AFW_EXPORT InputManager {
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
			afwbool_t isKeyPressed(const afwuint_t& ) const;

			/**
			 * Checks to see if the given mouse button is being pressed.
			 * @param btn The mouse button code code to check.
			 * @return <code>true</code> if the mouse button is being pressed. <code>false</code> otherwise.
			 * @see isKeyPressed()
			 * @since snapshot20170930
			 */
			afwbool_t isMouseButtonPressed(const afwuint_t& ) const;

			/**
			 * Stores the mouse's current position in the two given variables.
			 * @param x,y The variables to store respectively the mouse's X and Y coordinates.
			 * @see getScrollPosition()
			 * @since snapshot20170930
			 */
			afwvoid_t getMousePosition(afwdouble_t& , afwdouble_t& ) const;

			/**
			 * Not implemented yet, presumably stores the mouse's scroll position in the two given variables.
			 * @see getMousePosition()
			 * @since snapshot20170930
			 */
			afwvoid_t getScrollPosition(const afwdouble_t& , const afwdouble_t& ) const;

		private:
			static afwvoid_t _keyCallback(GLFWwindow* , afwint_t , afwint_t , afwint_t , afwint_t );
			static afwvoid_t _mouseButtonCallback(GLFWwindow* , afwint_t , afwint_t , afwint_t );
			static afwvoid_t _cursorPosCallback(GLFWwindow* , afwdouble_t , afwdouble_t );
			static afwvoid_t _scrollCallback(GLFWwindow* , afwdouble_t , afwdouble_t );

			const Window* _parent;
			afwbool_t _keys[AFW_GENGINE_INPUT_MAX_KEYS];
			afwbool_t _mouseButtons[AFW_GENGINE_INPUT_MAX_MOUSE_BUTTONS];
			afwdouble_t _mx, _my;
		};
	}
}

#endif // AURORAFW_GENGINE_INPUT_H
