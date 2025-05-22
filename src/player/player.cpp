#include <SDL3/SDL.h>
#include "player.hpp"
#include "../core/constants.hpp"

Player::Player() {
    player = {100, 100, 50, 50};  // x, y, width, height
    velocity = 0;
    gravity = 0.2f;
    mass = 1.0f;
    isGrounded = false;
}

void Player::move(bool is_right) {
    float moveSpeed = 0.06f;
    if (is_right) {
        player.x += moveSpeed;
    } else {
        player.x -= moveSpeed;
    }
}

void Player::jump() {
    if (isGrounded) {
        velocity = -10.0f;
        isGrounded = false;
    }
}

void Player::update(float deltaTime) {
    if (!isGrounded) {
        velocity += gravity * deltaTime;
        player.y += velocity * deltaTime;
    }
    
    if (player.y >= SCREENHEIGHT - player.h) {
        player.y = SCREENHEIGHT - player.h;
        velocity = 0;
        isGrounded = true;
    }
}