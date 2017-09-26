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

#ifndef AURORAFW_GENGINE_ASSETMANAGER_H
#define AURORAFW_GENGINE_ASSETMANAGER_H

#include <AuroraFW/Global.h>

#include <exception>
#include <fstream>
#include <sstream>

namespace AuroraFW {
	namespace GEngine {
		enum class AssetType {
			Audio,
			Font,
			GUI,
			Material,
			Model,
			Terrain,
			Texture,
			Shader
		};

		class AssetNotFoundException: public std::exception
		{
		private:
			const char* path;
		public:
			AssetNotFoundException(const char* );
			virtual const char* what() const throw();
		};

		class AssetTypeInvalidException: public std::exception
		{
			virtual const char* what() const throw();
		};

		class AFW_PREFIX AssetManager {
		private:
			static AssetManager* instance;
			AssetManager() {}
		public:
			static AssetManager& getInstance()
			{
				if(instance == nullptr)
					instance = new AssetManager();
				
				return *instance;
			}

			static auto loadAsset(const char* path , const AssetType& type);
		};
	}
}

#endif // AURORAFW_GENGINE_ASSETMANAGER_H