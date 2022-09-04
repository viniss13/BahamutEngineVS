#pragma once
#include "BHM_Common.hpp"
#include "BHM_Rectangle.hpp"


class BHM_Texture{
	private:

		string* path;
		string teste;
		int x = 0;
		
	public:
		BHM_Rectangle* rectangle;
		void* texture;
		BHM_Texture(string path, BHM_Rectangle* rectangle, void* texture);
		BHM_Texture();
		BHM_Texture* BHM_LoadTexture(string path);
};