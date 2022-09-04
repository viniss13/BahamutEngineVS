#include "BHM_SDL_GUI.hpp"

BHM_SDL_GUI::BHM_SDL_GUI(){
	cout << "SDL GUI Initialized" << endl;
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	
	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	} else {
		cout << "SDL initialized" << endl;
	}

	this->window = SDL_CreateWindow(BHM_Config::GAME_NAME.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, BHM_Config::SCREEN_WIDTH, BHM_Config::SCREEN_HEIGHT, windowFlags);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	this->renderer = SDL_CreateRenderer(this->window, -1, rendererFlags);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	
	//SDL_ShowCursor(0);
}

void BHM_SDL_GUI::BHM_PrepareScene(){
	SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
	SDL_RenderClear(renderer);
	BHM_DoInput();
}

void BHM_SDL_GUI::BHM_PresentScene()
{
	//SDL_Rect dest;

	//dest.x = 100;
	//dest.y = 100;
	//dest.w = w;
	//dest.h = h;
	//SDL_RenderCopy(renderer, texture, NULL, &dest);
	SDL_RenderPresent(renderer);
}

void BHM_SDL_GUI::BHM_Draw(BHM_Sprite* sprite){
	/*cout << "I am here" << "\n";
	SDL_Rect dest;

	BHM_Shape* shape = sprite->BHM_GetShape().lock().get();


	BHM_Vector2* vector2 = shape->BHM_GetVector2().lock().get();
	//BHM_Rectangle* rectangle = sprite->BHM_GetRectangle().lock().get();
	BHM_Texture* bhm_texture = textures[1];
	BHM_Rectangle* rectangle = bhm_texture->rectangle;
	dest.x = vector2->BHM_GetX();
	dest.y = vector2->BHM_GetY();
	dest.w = rectangle->BHM_GetWidth();
	dest.h = rectangle->BHM_GetHeight();
	
	SDL_Texture* texture = (SDL_Texture*)(bhm_texture->texture);

	SDL_RenderCopy(renderer, texture, NULL, &dest);*/
}

void BHM_SDL_GUI::BHM_LoadTexture(string path){
	//texture = IMG_LoadTexture(renderer, path.c_str());
	//SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	//BHM_Texture* texture = new BHM_Texture();
	/*
	system("pause");
	SDL_Texture* texture = NULL;
	if (renderer != NULL) {
		cout << "Renderer nao eh nulo\n";
		texture = testeSDL(path);
		if (texture != NULL) cout << "Texture nao eh nulo\n";
	}
	
	//BHM_Texture* bhm_texture1 = new BHM_Texture();
	
	if(texture == NULL){
		cout << "Error on loading texture: " << path;
		system("pause");
		return;
	} 
	int w = 0;
	int h = 0;

	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	*/

	//BHM_Rectangle* rectangle = new BHM_Rectangle(w, h);
	//BHM_Texture* bhm_texture  = new BHM_Texture(path, rectangle, texture);

	//textures[1] = bhm_texture;
	//this->testeSDL(path, bhm_texture);
}

/*SDL_Texture* BHM_SDL_GUI::testeSDL(string path) {
	return IMG_LoadTexture(renderer, path.c_str());
}*/

void BHM_SDL_GUI::BHM_DoInput(){
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN: 
				//doKeyDown(&event.key);
				break;

			case SDL_KEYUP:
			//	doKeyUp(&event.key);
				break;

			default:
				break;
		}
	}
}

