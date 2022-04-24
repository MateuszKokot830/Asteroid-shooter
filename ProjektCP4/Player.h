#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Player class is responsible for creating an object - spaceship, which can be control by a user
// Player's object is created and controlled in GameState class

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
		
	float speed; // player's speed
	float cd; // player's current cooldown, when it reaches cdMax - a new bullet can be spawned
	float cdMax; // player's cooldown between shooting missless
	int hp; // player's hp
	int hpMax; // player's max hp

	void initVariables(); // initialize private variables of this class
	void initTexture(); // creates texture of the player
	void initSprite(); // creates sprite and size of the player

public:
	Player(float pos_X, float pos_Y); // calls all of the init functions, sets position of the player
	virtual ~Player(); // empty

	// These functions below are called in the GameState class and are responsible for updating the player
	const sf::Vector2f& getPos() const; // returns current position of the player
	const sf::FloatRect getBounds() const; // returns the bounding shape of the player
	
	const int& getHp() const; // returns current health points of the player
	const int& getHpMax() const; //returns maximum health points of the player
	void setHp(const int hp); // sets hp to a constant value
	void loseHp(const int value); // loses 1 health point of the player
	void addHP(const int value); // adds 1 health point of the player

	void setPosition(const float x, const float y); //  sets position of the player, called in the Player constructor
	void move(const float dt, const float dirX, const float dirY); // moves the player with a constant speed

	const bool CheckAttack(); // checks the cooldown between attacks and returns true if can attack or false if can't, it makes the bullets not spamable

	void updateCD(); // increases the current cooldown unless it reaches maximum cooldown
	void update(); // calls all the update fuctions
	void render(sf::RenderTarget& target); // renders the player
};

