// 02-sdl2-video.cpp : SDL2 example - initialize video and display image
//

#include <stdio.h>
#include "SDL2/SDL.h"

int main(int argc, char* argv[]) {
    SDL_Window *win = NULL;
    SDL_Renderer *ren = NULL;
    SDL_Surface *bmp = NULL;
    SDL_Texture *tex = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        printf("Error initializing SDL:  %s\n", SDL_GetError());
        return 1;
    }

    win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == NULL){
        printf("%s\n", SDL_GetError());
        return 2;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        printf("%s\n", SDL_GetError());
        return 3;
    }

    bmp = SDL_LoadBMP("./src/main/resources/smajlik.bmp");
    if (bmp == NULL){
        printf("%s\n", SDL_GetError());
        return 4;
    }
    
    tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    SDL_Delay(2000);

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}

