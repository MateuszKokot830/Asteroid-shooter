#include "GameOverState.h"

void GameOverState::initFonts()
{
	if (!this->font.loadFromFile("arial.ttf"))
	{
		throw ("ERRROR: FONT NOT LOADED");
	}
}

void GameOverState::initButtons()
{
	this->buttons["LoadGameState"] = new MenuStateButtons(450, 350, 300, 80, &this->font, "START A NEW GAME", sf::Color(192, 192, 192), sf::Color(150, 150, 150));
	this->buttons["Back2MenuState"] = new MenuStateButtons(450, 475, 300, 80, &this->font, "BACK TO MENU", sf::Color(192, 192, 192), sf::Color(150, 150, 150));
	this->buttons["CloseApp"] = new MenuStateButtons(450, 600, 300, 80, &this->font, "EXIT GAME", sf::Color(192, 192, 192), sf::Color(150, 150, 150));
}

void GameOverState::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));

	if (!this->Texture.loadFromFile("Textures/Background.png"))
	{
		throw "ERROR: BACKGROUND TEXTURE NOT LOADED";
	}
	this->background.setTexture(&this->Texture);
}

void GameOverState::initTitle(float pos_x, float pos_y, sf::Font font, std::string text)
{
	this->font = font;
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::Red);
	this->text.setPosition(sf::Vector2f(pos_x, pos_y));
	this->text.setOutlineThickness(1);
	this->text.setStyle(sf::Text::Bold);
	this->text.setCharacterSize(120);
}

GameOverState::GameOverState(sf::RenderWindow* window, std::stack<State*>* States)
	: State(window, States)
{
	this->initBackground();
	this->initFonts();
	this->initButtons();
	this->initTitle(220, 150, this->font, "GAME OVER!");
}

GameOverState::~GameOverState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void GameOverState::FinishState()
{

}

void GameOverState::updateKeybinds()
{
	this->CheckEnd();
}

void GameOverState::update(const float& dt)
{
	this->updateMousePos();
	this->updateKeybinds();
	this->updateButtons();

}

void GameOverState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);
	target->draw(this->text);
	this->renderButtons(target);
}

void GameOverState::updateButtons()
{
	for (auto it : this->buttons)
	{
		it.second->update(this->MouseView);
	}

	if (this->buttons["LoadGameState"]->isPressed())
	{
		this->States->push(new GameState(this->window, this->States));
	}

	if (this->buttons["Back2MenuState"]->isPressed())
	{
		this->States->push(new MenuState(this->window, this->States));
	}

	if (this->buttons["CloseApp"]->isPressed())
	{
		this->End = true;
	}
}

void GameOverState::renderButtons(sf::RenderTarget* target)
{
	for (auto it : this->buttons)
	{
		it.second->render(target);
	}
}