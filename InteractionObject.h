#ifndef INTERACTION_OBJECT_H
#define INTERACTION_OBJECT_H

#include "HUD/Button.h"

class InteractionObject : public HUD::Button
{

public:
	


private:
	virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !INTERACTION_OBJECT_H
