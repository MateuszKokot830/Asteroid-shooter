#pragma once
#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "Astroids.h"
#include "Potions.h"
#include "Obstacles.h"
#include "GameOverState.h"

// A children class to State, iherits its public methods
// Displays GameState scene

class GameState :
	public State
{
private:
	Player* player;
	std::vector<Bullet*> bullets;
	std::vector<Astroids*> astroids;
	std::vector<Potions*> potions;
	std::vector<Obstacles*> obstacles;
	std::map<std::string, sf::Texture*> textures;
	sf::RectangleShape background;
	sf::Texture Texture;
	sf::Font font;
	sf::Text scoreText;
	sf::Text HighscoreText;
	sf::Sprite HPBar;

	void initPlayer(); // creates object of the Player class
	void initTextures(); // initialize all of the textures
	void initVariables(); // initialize all of the variables
	void initBackground(); // creates the background
	void initFonts(); // initialize Arial font
	void initText(); // initalize Text
	void initHPBar(); // initialize Health Bar

	// private variables
	float Timer; 
	float Timer2;
	float Timer3;
	float MaxTimer;
	unsigned score;
	unsigned highscore;
	std::string textfile;

public:
	GameState(sf::RenderWindow *window, std::stack<State*> *States); // constructor, calls all the private functions
	virtual ~GameState(); // destructor, deletes all of the created objects in map and vector of objects

	void updatePlayer(const float& dt); // moves the player by using WASD and arrows
	void ScreenCollision(); // checks the collision between player and the screen
	void updateBullet(); // creates new bullet if all the cooldown the requirements are fulfilled, calls bullet update function, deletes all the bullets that reach top of the screen
	void updateAstroids(); // creates new asteroid, calls asteroid update function, deletes all the asteroids that reach the bottom of the screen, checks for collisions
	void updatePotions(); // creates new obstacle, calls obstacle update function, deletes all the obstacles that reach the bottom of the screen, checks for collisions
	void updateObstacles(); // creates new potion, calls potion update function, deletes all the potions that reach the bottom of the screen, checks for collisions
	void updateText(); // displays the text (score and highscore)
	void updateHPBar(); // updates HP bar as HP changes during the game
	void clearObjects(); //clears all of the created objects, is called when the game ends
	void FinishState(); // check if the current score is higher than highscore, if so, then it saves it to the file using regex expression
	void updateKeybinds(); // calls CheckEnd function from Game class
	void update(const float& dt); // calls all the update functions if the game is on, when hp = 0 calls finishstate function
	void render(sf::RenderTarget* Target = NULL); // renders window, background, textes and all of the objects with their textures


};

