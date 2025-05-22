#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL3/SDL.h>

struct PosVector {
    float x;
    float y;
};

class Player {
    private:
        PosVector currPos;
        float velocity;
        float gravity;
        float mass;
        bool isGrounded;
        
    public:
        Player();
        
        void move(bool is_right);
        void jump();
        void update(float deltaTime);
        
        const PosVector& getPosition() const { return currPos; }
};

#endif