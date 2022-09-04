#include "Bahamut.hpp"
#include "MyRunner.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture* texture;
int w = 0;
int h = 0;

void initialize(){
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

    window = SDL_CreateWindow("Testando SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, windowFlags);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    
    //SDL_ShowCursor(0);
}

void BHM_DoInput(){
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
            //  doKeyUp(&event.key);
                break;

            default:
                break;
        }
    }
}

void BHM_PrepareScene(){
    SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
    SDL_RenderClear(renderer);
    BHM_DoInput();
}

void BHM_PresentScene()
{
    SDL_Rect dest;

    dest.x = 100;
    dest.y = 100;
    dest.w = w;
    dest.h = h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);
    SDL_RenderPresent(renderer);
}

void cleanup(void)
{
    SDL_DestroyRenderer(renderer);
    
    SDL_DestroyWindow(window);
    
    SDL_Quit();
}

int main(int argc, char *argv[])
{

    atexit(cleanup);
    /*
    BHM_Config::GAME_NAME = "Teste";
    BHM_Config::SCREEN_HEIGHT = 600;
    BHM_Config::SCREEN_WIDTH = 600;
    BHM_Config::LAYERS = 4;
    BHM_Init::BHM_Initialize(make_shared<MyRunner>());*/

    initialize();
    int i = 0;
    while(true){
        BHM_PrepareScene();

        if(i == 0){
            texture = IMG_LoadTexture(renderer, "res/gfx/selectedArea.png");
            BHM_Texture* bhm_texture = new BHM_Texture();
            SDL_QueryTexture(texture, NULL, NULL, &w, &h);

            cout << w << "\n";
            cout << h << "\n";
            i++;
        }
        BHM_PresentScene();
    }


    system("pause");
    return 0;
}