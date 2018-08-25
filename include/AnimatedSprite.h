#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <SFML/Graphics/Sprite.hpp>
#include "Animation.h"
#include "AnimationType.h"

class AnimatedSprite : public sf::Sprite
{
    std::map<AnimationType, Animation> animations;
	Animation* currentAnim = nullptr;
public:
    using sf::Sprite::Sprite;

    void AddAnimation(AnimationType id, Animation ani);
    Animation* GetAnimation(AnimationType id);
    void SetCurrentAnimation(AnimationType id);
    Animation* GetCurrentAnimation();

    virtual void Update(sf::Time deltaTime);
};

#endif // ANIMATED_SPRITE_H