#include "AnimatedSprite.h"
#include <stdexcept>

void AnimatedSprite::AddAnimation(const std::string& id, Animation ani)
{
	animations.emplace(id, ani);
}

Animation* AnimatedSprite::GetAnimation(const std::string& id)
{
	if (animations.count(id) <= 0) throw std::runtime_error("Undefined Animation id");
	return &animations[id];
}

void AnimatedSprite::Update(sf::Time deltaTime)
{
    if(currentAnim == nullptr) throw std::runtime_error("currentAnim returns nullptr"); 
    currentAnim->Update(deltaTime);
    setTextureRect(currentAnim->GetCurrentFrame());
}

void AnimatedSprite::SetCurrentAnimation(const std::string& id)
{
	if (animations.count(id) <= 0) throw std::runtime_error("Undefined Animation id");
	currentAnim = &animations[id];
}

Animation* AnimatedSprite::GetCurrentAnimation()
{
	return currentAnim;
}
