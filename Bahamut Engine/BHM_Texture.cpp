#include "BHM_Texture.hpp"


BHM_Texture* BHM_Texture::BHM_LoadTexture(string path){

	return NULL;
}

BHM_Texture::BHM_Texture(string path, BHM_Rectangle* rectangle, void* texture){
	this->path = new string(path);
	this->rectangle = rectangle;
	this->texture = texture;
}

BHM_Texture::BHM_Texture(){

}