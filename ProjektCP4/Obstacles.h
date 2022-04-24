#pragma once
#include "Objects.h"

// Children class of Objects, which publicaly inherits some methods
// A vector of obstacles is created in GameState class

class Obstacles :
	public Objects
{
private:
	sf::Texture texture;

	void initVariables(); // initialize private variables of this class

public:
	Obstacles(float pos_X, float pos_Y);
	// creates new shape with it's texture and position, calls initVariables function
	virtual ~Obstacles(); // empty 


	void update(); // update obstacle's speed
	void render(sf::RenderTarget* target); // renders the obstacle
};

