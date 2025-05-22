#include <SDL3/SDL.h>
#include "player.hpp"

Player::Player() {
    currPos = {0, 0};
    velocity = 0;
    gravity = 9.8f;
    mass = 1.0f;
    isGrounded = false;
}

void Player::move(bool is_right) {
    float moveSpeed = 5.0f;
    if (is_right) {
        currPos.x += moveSpeed;
    } else {
        currPos.x -= moveSpeed;
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
        currPos.y += velocity * deltaTime;
    }
    
    if (currPos.y >= 0) {
        currPos.y = 0;
        velocity = 0;
        isGrounded = true;
    }
}