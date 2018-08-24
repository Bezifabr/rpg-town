#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <SFML/Graphics/Sprite.hpp>
#include "Animation.h"

class AnimatedSprite : public sf::Sprite
{
    std::map<std::string, Animation> animations;
	Animation* currentAnim = nullptr;
public:
    using sf::Sprite::Sprite;

    void AddAnimation(const std::string& id, Animation ani);
    Animation* GetAnimation(const std::string& id);
    void SetCurrentAnimation(const std::string& id);
    Animation* GetCurrentAnimation();

    virtual void Update(sf::Time deltaTime);
};

#endif // ANIMATED_SPRITE_H