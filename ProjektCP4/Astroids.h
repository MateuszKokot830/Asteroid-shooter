#pragma once
#include "Objects.h"

// Children class of Objects, which publicaly inherits some methods
// A vector of astroids is created in GameState class

class Astroids : 
	public Objects
{
private:
	sf::Texture texture;

	void initVariables(); // initialize private variables of this class

public:
	Astroids(float pos_X, float pos_Y);
	// creates new shape with it's texture and position, calls initVariables function
	virtual ~Astroids(); // empty 


	void update(); // update asteroid's speed
	void render(sf::RenderTarget* target); // renders the astroid
};

