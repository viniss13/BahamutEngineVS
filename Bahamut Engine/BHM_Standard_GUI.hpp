#pragma once
#include "BHM_Common.hpp"
#include "BHM_Sprite.hpp"
#include "BHM_Texture.hpp"
#include "BHM_Rectangle.hpp"

class BHM_Texture;

class BHM_Standard_GUI{
	public:
		virtual void BHM_PrepareScene() = 0;
		virtual void BHM_PresentScene() = 0;
		virtual void BHM_Draw(BHM_Sprite* sprite) = 0;
		virtual void BHM_LoadTexture(string path) = 0;
		virtual bool BHM_TextureExists(string path) = 0;
	protected:
		std::unordered_map<string, BHM_Texture*> textures;
};