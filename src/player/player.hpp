#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL3/SDL.h>
#include <string>
#include <vector>

class Player {
    private:
        SDL_FRect player;
        float velocity;
        float gravity;
        float mass;
        bool lastPressedRight;
        bool isGrounded;
        
        SDL_Texture* currentSprite;
        std::vector<SDL_Texture*> walkingSprites;
        float animationTimer;
        int currentFrame;
        
    public:
        Player();
        ~Player();
        
        void move(bool is_right);
        void jump();
        void update(float deltaTime);
        void loadSprites(SDL_Renderer* renderer);
        void render(SDL_Renderer* renderer);
        
        const SDL_FRect& getPosition() const { return player; }
};

#endif