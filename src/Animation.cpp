#include "Animation.h"

void Animation::AddFrame(sf::IntRect frame)
{
	frames.emplace_back(frame);
}

const sf::IntRect & Animation::GetCurrentFrame()
{
	return frames[current];
}

void Animation::ClearFrames()
{
	Pause();
	Reset();
	this->frames.clear();
}

void Animation::Pause()
{
	isPlaying = false;
}

void Animation::Play()
{
	isPlaying = true;
}

void Animation::Reset()
{
	current = 0;
}

void Animation::SetDelay(sf::Time delay)
{
	this->delay = delay;
}

sf::Time Animation::GetDelay()
{
	return delay;
}

void Animation::Update(sf::Time deltaTime)
{
	elapsed += deltaTime;
	if (isPlaying && elapsed >= delay)
	{
		elapsed = sf::Time::Zero;
		current++;
		if (current == frames.size()) current = 0;
	}
}
