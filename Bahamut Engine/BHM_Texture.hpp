#pragma once
#include "BHM_Common.hpp"
#include "BHM_Rectangle.hpp"
#include "BHM_Config.hpp"


class BHM_Texture{
	private:

		string path;
		string teste;
		int x = 0;
		
	public:
		BHM_Texture(string path, BHM_Rectangle* rectangle, void* texture);
		BHM_Rectangle* rectangle;
		void* texture;
		//BHM_Texture(string path, BHM_Rectangle* rectangle, void* texture);
		//BHM_Texture();
		static void BHM_LoadTexture(string path);
		static void BHM_ForceLoadTexture(string path);

		static BHM_Texture* BHM_LoadAndGetTexture(string path);
		static BHM_Texture* BHM_GetTexture(string path);
		static bool BHM_TextureExists(string path);
		
};