#include <SDL3/SDL.h>
#include "player.hpp"
#include "../core/constants.hpp"
#include <iostream>

Player::Player() {
    player = {100, 100, 100, 100};  // Increased size to 100x100
    velocity = 0;
    gravity = 0.2f;
    mass = 1.0f;
    isGrounded = false;
    lastPressedRight = true;
    currentSprite = nullptr;
    animationTimer = 0;
    currentFrame = 0;
}

Player::~Player() {
    for (auto sprite : walkingSprites) {
        SDL_DestroyTexture(sprite);
    }
}

void Player::loadSprites(SDL_Renderer* renderer) {
    SDL_Surface* surface1 = SDL_LoadBMP("../resources/sprites/player/walking.bmp");
    if (!surface1) {
        std::cerr << "Failed to load walking.bmp: " << SDL_GetError() << std::endl;
        return;
    }
    
    SDL_Surface* surface2 = SDL_LoadBMP("../resources/sprites/player/walking2.bmp");
    if (!surface2) {
        std::cerr << "Failed to load walking2.bmp: " << SDL_GetError() << std::endl;
        SDL_DestroySurface(surface1);
        return;
    }
    
    SDL_Texture* tex1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Texture* tex2 = SDL_CreateTextureFromSurface(renderer, surface2);
    
    if (!tex1 || !tex2) {
        std::cerr << "Failed to create textures: " << SDL_GetError() << std::endl;
        if (tex1) SDL_DestroyTexture(tex1);
        if (tex2) SDL_DestroyTexture(tex2);
    } else {
        walkingSprites.push_back(tex1);
        walkingSprites.push_back(tex2);
        currentSprite = walkingSprites[0];
    }
    
    SDL_DestroySurface(surface1);
    SDL_DestroySurface(surface2);
}

void Player::render(SDL_Renderer* renderer) {
    if (currentSprite && !walkingSprites.empty()) {
        SDL_RenderTexture(renderer, currentSprite, nullptr, &player);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player);
    }
}

void Player::move(bool is_right) {
    float moveSpeed = 0.06f;
    if (is_right) {
        player.x += moveSpeed;
        lastPressedRight = true;
    } else {
        player.x -= moveSpeed;
        lastPressedRight = false;
    }
    
    if (!walkingSprites.empty()) {
        animationTimer += 0.01f;
        if (animationTimer >= 0.1f) {
            animationTimer = 0;
            currentFrame = (currentFrame + 1) % walkingSprites.size();
            currentSprite = walkingSprites[currentFrame];
        }
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