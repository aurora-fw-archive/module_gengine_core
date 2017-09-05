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
		InputManager::InputManager(Window* parent)
			: parent(parent)
		{
			for(int i = 0; i < AFW_GENGINE_INPUT_MAX_KEYS; i++) {
				keys[i] = false;
			}

			for(int i = 0; i < AFW_GENGINE_INPUT_MAX_MOUSE_BUTTONS; i++) {
				mouseButtons[i] = false;
			}

			glfwSetWindowUserPointer(parent->window, this);
			glfwSetKeyCallback(parent->window, keyCallback);
			glfwSetMouseButtonCallback(parent->window, mouseButtonCallback);
			glfwSetCursorPosCallback(parent->window, cursorPosCallback);
		}

		InputManager::~InputManager()
		{}

		bool InputManager::isKeyPressed(uint_t key) const {
			if(key >= AFW_GENGINE_INPUT_MAX_KEYS)
				return false;
			return keys[key];
		}

		bool InputManager::isMouseButtonPressed(uint_t btn) const {
			if(btn >= AFW_GENGINE_INPUT_MAX_MOUSE_BUTTONS)
				return false;
			return mouseButtons[btn];
		}

		void InputManager::getMousePosition(double& x, double& y) const {
			x = mx;
			y = my;
		}

		void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			InputManager* in = (InputManager*)glfwGetWindowUserPointer(window);
			in->keys[key] = action != GLFW_RELEASE;
		}

		void InputManager::mouseButtonCallback(GLFWwindow* window, int btn, int action, int mods)
		{
			InputManager* in = (InputManager*)glfwGetWindowUserPointer(window);
			in->mouseButtons[btn] = action != GLFW_RELEASE;
		}

		void InputManager::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
		{
			InputManager* in = (InputManager*)glfwGetWindowUserPointer(window);
			in->mx = xpos;
			in->my = ypos;
		}
	}
}
