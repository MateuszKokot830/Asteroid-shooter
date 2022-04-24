#pragma once
#include "State.h"
#include "MenuState.h"
#include "MenuStateButtons.h"

// A children class to State, iherits its public methods
// Displays How To Play scene

class How2State :
	public State
{
private:
	sf::RectangleShape background;
	sf::Texture Texture;
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	sf::Text text5;
	sf::Text text6;
	sf::Text text7;

	sf::Sprite player;
	sf::Sprite bullet;
	sf::Sprite hpBar;
	sf::CircleShape Astroid;
	sf::CircleShape Potion;
	sf::RectangleShape Obstacle;

	std::map<std::string, MenuStateButtons*> buttons;
	std::map<std::string, sf::Texture*> textures;

	void initFonts(); // initialize Arial font
	void initButtons(); // creates new buttons from MenuStateButtons class
	void initTextures(); // initialize textures
	void initBackground();  // creates background
	void initSpirites(); // creates sprites
	void initText(); // initalize text 

public:
	How2State(sf::RenderWindow* window, std::stack<State*>* States); // constructor, calls all the private functions
	virtual ~How2State(); // destructor, deletes created buttons and textures in the map

	void FinishState();  // returns true, means the state is ended
	void updateKeybinds(); // calls CheckEnd function from Game class
	void update(const float& dt); // calls all of the update functions
	void render(sf::RenderTarget* target = NULL); // renders all of the objects
	void renderText(sf::RenderTarget* target); // renders all the text
	void updateButtons(); // does certain actions when any button is pressed
	void renderButtons(sf::RenderTarget* target = NULL); // render buttons

};

