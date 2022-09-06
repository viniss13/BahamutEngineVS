// Bahamut Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bahamut.hpp"
#include "MyRunner.hpp"
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;
int w = 0;
int h = 0;


void cleanup(void)
{
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();
}

void initialize() {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    else {
        cout << "SDL initialized" << endl;
    }

    window = SDL_CreateWindow("Testando SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, windowFlags);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    renderer = SDL_CreateRenderer(window, -1, rendererFlags);

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    //SDL_ShowCursor(0);
    
}

void BHM_DoInput() {
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

void BHM_PrepareScene() {
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

int main(int argc, char* args[])
{

    BHM_Config::GAME_NAME = "Teste";
    BHM_Config::SCREEN_HEIGHT = 600;
    BHM_Config::SCREEN_WIDTH = 600;
    BHM_Config::LAYERS = 4;
    BHM_Config::standardGUI = new BHM_SDL_GUI();
    BHM_Init::BHM_Initialize(make_shared<MyRunner>());
    
    //initialize();
   // atexit(cleanup);
    /*
    int i = 0;
    while (true) {
        BHM_Config::standardGUI->BHM_PrepareScene();
        
        if (i == 0) {
            BHM_Config::standardGUI->BHM_LoadTexture("grumpy.jpg");
          //  BHM_Texture* bhm_texture = new BHM_Texture();
            i++;
        }
        BHM_Config::standardGUI->BHM_PresentScene();
    }*/

    

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
