#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// A parent class to Obstacles, Asteroids and Potions
// Is responsible for creating a shape object with its texture and position

class Objects
{
private:
	void initVariables(); // initialize private variables of this class

protected:
	sf::Shape *shape;
	sf::Texture* texture;

	float speed; // speed of the object, will be defined different for each of the objects

public:
	Objects(); // constructor, calls all of the init functions
	virtual ~Objects(); //destructor, destroyes shape in order to avoid memory leaks

	void setTexture(sf::Texture* texture); // sets given texture to a shape

	const sf::FloatRect getBounds() const; // returns the bounding shape of the object

	// virtual functions
	virtual void setPosition(const float pos_X, const float pos_Y); // sets position of the object
	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

