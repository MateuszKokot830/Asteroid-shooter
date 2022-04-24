#pragma once
#include "MenuStateButtons.h"
#include "GameState.h"
#include "MenuState.h"

// A children class to State, iherits its public methods
// Displays GameOver scene

class GameOverState :
	public State
{
private:
	sf::RectangleShape background;
	sf::Texture Texture;
	sf::Font font;
	sf::Text text;

	std::map<std::string, MenuStateButtons*> buttons;

	void initFonts(); // initialize Arial font
	void initButtons();  // creates new buttons from MenuStateButtons class
	void initBackground(); // creates background
	void initTitle(float pos_x, float pos_y, sf::Font font, std::string text);  // initialize title of the menu

public:
	GameOverState(sf::RenderWindow* window, std::stack<State*>* States); // constructor, calls all the private functions
	virtual ~GameOverState();  // destructor, deletes created buttons in the map

	void FinishState(); // returns true, means the state is ended
	void updateKeybinds(); // calls CheckEnd function from Game class
	void update(const float& dt); // calls all of the update functions
	void render(sf::RenderTarget* target = NULL); // renders all of the objects
	void updateButtons(); // does certain actions when any button is pressed
	void renderButtons(sf::RenderTarget* target = NULL);  // render buttons

};

