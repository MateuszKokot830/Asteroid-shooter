#pragma once
#include "GameState.h"
#include "MenuState.h"
#include "How2State.h"
#include "GameOverState.h"
#include "Player.h"

// Engine class of the program
// Responsible for menaging states and creating window

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event eventes;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> States;

	void initWindow(); // creates window
	void initStates(); // pushes MainMenu state on top of the stack, as the program is started

public: 
	Game(); // contructor, calls all of the init functions
	virtual ~Game(); // destructor, delete window and states in order to avoid memeory leaks

	void run(); // calls all the functions of this class
	void updateDt(); // updates the clock
	void EndApp(); // does all the changes in the program when its closed
	void updateEvents(); // checks if the program is closed by escape/close buttons at any point
	void update(); // update the stack, by menaging the states
	void render(); // renders and displays window, also renders a state which is on top of the stack

};

