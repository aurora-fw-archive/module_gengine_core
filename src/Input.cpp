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
		InputManager::InputManager(const Window *parent)
			: _parent(parent)
		{
			for(int i = 0; i < AFW_GENGINE_INPUT_MAX_KEYS; i++)
			{
				_keys[i] = false;
			}

			for(int i = 0; i < AFW_GENGINE_INPUT_MAX_MOUSE_BUTTONS; i++)
			{
				_mouseButtons[i] = false;
			}

			glfwSetWindowUserPointer(_parent->window, this);
			glfwSetKeyCallback(_parent->window, _keyCallback);
			glfwSetMouseButtonCallback(_parent->window, _mouseButtonCallback);
			glfwSetCursorPosCallback(_parent->window, _cursorPosCallback);
		}

		InputManager::~InputManager()
		{}

		bool InputManager::isKeyPressed(const uint_t& key) const
		{
			if(key >= (AFW_GENGINE_INPUT_MAX_KEYS + AFW_GENGINE_INPUT_KEY_OFFSET))
				return false;
			return _keys[key];
		}

		bool InputManager::isMouseButtonPressed(const uint_t& btn) const
		{
			if(btn >= (AFW_GENGINE_INPUT_MAX_MOUSE_BUTTONS + AFW_GENGINE_INPUT_MOUSE_BUTTONS_OFFSET))
				return false;
			return _mouseButtons[btn];
		}

		void InputManager::getMousePosition(double& x, double& y) const
		{
			x = _mx;
			y = _my;
		}

		void InputManager::_keyCallback(GLFWwindow *window, int key, int /*scancode*/, int action, int /*mods*/)
		{
			InputManager *in = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
			in->_keys[key] = action != GLFW_RELEASE;
		}

		void InputManager::_mouseButtonCallback(GLFWwindow *window, int btn, int action, int /*mods*/)
		{
			InputManager *in = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
			in->_mouseButtons[btn] = action != GLFW_RELEASE;
		}

		void InputManager::_cursorPosCallback(GLFWwindow *window, double xpos, double ypos)
		{
			InputManager *in = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
			in->_mx = xpos;
			in->_my = ypos;
		}
	}
}
