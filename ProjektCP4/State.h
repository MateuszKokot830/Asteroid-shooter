#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// A parent class to MenuState, GameState, GameOverState and How2State
// Uses stack and window as its parameters

class State
{
private:

protected:
	sf::RenderWindow* window;
	std::stack<State*> *States; // creates a stack, which will store states
	std::vector<sf::Texture> Textures; //creates vector of texture, which will store texture
	bool End; // bool, if returned yes - then it means the state is ended, otherwise the state goes on

	sf::Vector2i MouseScreen; 
	sf::Vector2i MouseWindow; 
	sf::Vector2f MouseView; 

public:
	State(sf::RenderWindow* window, std::stack<State*> *States); //contructor of the class, which defines its parameters
	virtual ~State(); // empty

	const bool& Exit() const; // returns bool End defined in this class

	// virtual functions that are declared in children classes
	virtual void CheckEnd(); //checks if the escape button is pressed, if yes, the state is ended by returning bool End = true
	virtual void FinishState() = 0;
	virtual void updateMousePos(); //checks and update current mouse position on the screen
	virtual void updateKeybinds() = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

