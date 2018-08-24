#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

class Animation
{
    std::vector<sf::IntRect> frames;
    unsigned int current = 0;

    bool isPlaying = true;

    sf::Time delay;
	sf::Time elapsed;
public:
    void AddFrame(sf::IntRect frame);
    const sf::IntRect& GetCurrentFrame();

    void ClearFrames();

    void Pause();
    void Play();
    void Reset();

    void SetDelay(sf::Time delay);
    sf::Time GetDelay();

    void Update(sf::Time deltaTime);
};

#endif // ANIMATION_H