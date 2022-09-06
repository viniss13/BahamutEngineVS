#include "BHM_Texture.hpp"


void BHM_Texture::BHM_LoadTexture(string path){
	if (!BHM_Texture::BHM_TextureExists(path))
		BHM_Config::standardGUI->BHM_LoadTexture(path);
}

void BHM_Texture::BHM_ForceLoadTexture(string path)
{
}

BHM_Texture* BHM_Texture::BHM_LoadAndGetTexture(string path)
{
	
	//if (BHM_Config::standardGUI->BHM_TextureExists(path)) return true;

	return nullptr;
}

BHM_Texture* BHM_Texture::BHM_GetTexture(string path)
{
	return nullptr;
}

bool BHM_Texture::BHM_TextureExists(string path)
{
	if (BHM_Config::standardGUI->BHM_TextureExists(path)) return true;
	else return false;
}


BHM_Texture::BHM_Texture(string path, BHM_Rectangle* rectangle, void* texture){
	this->path = path;
	this->rectangle = rectangle;
	this->texture = texture;
}