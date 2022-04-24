#pragma once
#include "Objects.h"

// Children class of Objects, which publicaly inherits some methods
// A vector of potions is created in GameState class

class Potions :
	public Objects
{
private:
	sf::Texture texture;

	void initVariables(); // initialize private variables of this class

public:
	Potions(float pos_X, float pos_Y); 
	// creates new shape with it's texture and position, calls initVariables function
	virtual ~Potions(); // empty 

	void update(); // update potion's speed
	void render(sf::RenderTarget* target); // renders the potion
};

