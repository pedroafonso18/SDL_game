#include <SDL3/SDL.h>
#include "../player/player.hpp"
#include "constants.hpp"

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* window = SDL_CreateWindow("Platformer", SCREENWIDTH, SCREENHEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    
    Player player;
    player.loadSprites(renderer);
    
    bool running = true;
    SDL_Event event;
    
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        
        const bool* keyState = SDL_GetKeyboardState(nullptr);
        if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A]) {
            player.move(false);
        }
        if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D]) {
            player.move(true);
        }
        if (keyState[SDL_SCANCODE_SPACE]) {
            player.jump();
        }
        
        player.update(1.0f/60.0f);
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        player.render(renderer);
        
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}