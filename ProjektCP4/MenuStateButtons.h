#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum Buttons_states {NoAction = 0, Hovered, Clicked};
// Enum class of buttons with 3 states (mouse besides button, mouse on button, button is clicked)

// A class responsible for creating buttons in menu
// Is called in MenuState, GameOverState and How2State

class MenuStateButtons
{
private:
	short unsigned Button_state;

	sf::RectangleShape button;
	sf::Font* font;
	sf::Text text;
	sf::Color NormalColor;
	sf::Color HoverColor;

public:
	MenuStateButtons(float pos_x, float pos_y, float width, float height, sf::Font* font, std::string text, sf::Color NormalColor, sf::Color HoverColor);
	// constructor that creater a button with certain size, at certain position, with certain font, text and colours
	~MenuStateButtons(); // empty

	const bool isPressed() const; // returns true if the button is pressed

	void update(const sf::Vector2f pos); // updates button depending on the mouse position, uses enum class
	void render(sf::RenderTarget* target); // draw a button with text on it
};

