#pragma once
#include "BHM_Standard_GUI.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "BHM_Config.hpp"

class BHM_SDL_GUI : public BHM_Standard_GUI{
public: 
	BHM_SDL_GUI();
	void BHM_PrepareScene();
	void BHM_PresentScene();
	void BHM_Draw(BHM_Sprite* sprite);
	void BHM_LoadTexture(string path);
	void BHM_DoInput();

	// Inherited via BHM_Standard_GUI
	virtual bool BHM_TextureExists(string path) override;
	
private:
	int w = 0;
	int h = 0;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture* texture;
};