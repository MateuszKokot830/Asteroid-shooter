#pragma once
#include <SFML/Graphics.hpp>

// Bullet class is responsible for creating an object - bullet, which are spawned from the spaceship and move upwards
// Bullet's vector of objects is created and controlled in GameState class
class Bullet
{
private:
	sf::Sprite sprite;

	sf::Vector2f dir;

	float speed; // bullet's speed

public:
	Bullet(sf::Texture * texture, float pos_X, float pos_Y, float X, float Y, float speed); 
	// sets texure, position, direction and speed of the bullet
	virtual ~Bullet(); // empty

	const sf::FloatRect getBounds() const; // returns the bounding shape of the bullet

	void update(); // calls all the update fuctions
	void render(sf::RenderTarget* target); // renders the bullet
};

