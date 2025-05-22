#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL3/SDL.h>

class Player {
    private:
        SDL_FRect player;
        float velocity;
        float gravity;
        float mass;
        bool isGrounded;
        
    public:
        Player();
        
        void move(bool is_right);
        void jump();
        void update(float deltaTime);
        
        const SDL_FRect& getPosition() const { return player; }
};

#endif