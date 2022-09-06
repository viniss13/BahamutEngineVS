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
	SDL_Rect dest;

	dest.x = 100;
	dest.y = 100;
	dest.w = w;
	dest.h = h;
	SDL_RenderCopy(renderer, texture, NULL, &dest);
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
	if (!this->BHM_TextureExists(path)) {
		SDL_Texture* sdl_texture = IMG_LoadTexture(renderer, path.c_str());

		if (sdl_texture == nullptr) {
			cout << path << " not found\n";
			return;
		}
		int width = 0;
		int height = 0;
		SDL_QueryTexture(sdl_texture, NULL, NULL, &width, &height);

		BHM_Rectangle* rect = new BHM_Rectangle(width, height);

		BHM_Texture* bhm_texture = new BHM_Texture(path, rect, sdl_texture);

		textures[path] = bhm_texture;
	}
	else {
		cout << "Texture Already Exists\n";
	}
}

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

bool BHM_SDL_GUI::BHM_TextureExists(string path)
{
	if (textures.find(path) == textures.end()) {
		return false;
	}
	else return true;
}

