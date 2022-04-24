#include "MenuState.h"

void MenuState::initFonts()
{
	if (!this->font.loadFromFile("arial.ttf"))
	{
		throw ("ERRROR: FONT NOT LOADED");
	}
}

void MenuState::initButtons()
{
	this->buttons["LoadGameState"] = new MenuStateButtons(450, 350, 300, 80, &this->font, "START A NEW GAME", sf::Color(192, 192, 192), sf::Color(150, 150, 150));
	this->buttons["How2PlayState"] = new MenuStateButtons(450, 475, 300, 80, &this->font, "HOW TO PLAY", sf::Color(192, 192, 192), sf::Color(150, 150, 150));
	this->buttons["CloseApp"] = new MenuStateButtons(450, 600, 300, 80, &this->font, "EXIT GAME", sf::Color(192, 192, 192), sf::Color(150, 150, 150));
}

void MenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));

	if (!this->Texture.loadFromFile("Textures/Background.png"))
	{
		throw "ERROR: BACKGROUND TEXTURE NOT LOADED";
	}
	this->background.setTexture(&this->Texture);
}

void MenuState::initTitle(float pos_x, float pos_y, sf::Font font, std::string text)
{
	this->font = font;
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::Green);
	this->text.setPosition(sf::Vector2f(pos_x, pos_y));
	this->text.setOutlineThickness(1);
	this->text.setStyle(sf::Text::Bold);
	this->text.setCharacterSize(80);
}

MenuState::MenuState(sf::RenderWindow *window, std::stack<State*> *States)
	: State(window, States)
{
	this->initBackground();
	this->initFonts();
	this->initButtons();
	this->initTitle(200, 100, this->font, "        Welcome to \n Asteroid Shooter Game!");
}

MenuState::~MenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MenuState::FinishState()
{
	this->End = true;
}

void MenuState::updateKeybinds()
{
	this->CheckEnd();
}

void MenuState::update(const float& dt)
{
	this->updateMousePos();
	this->updateKeybinds();
	this->updateButtons();
}

void MenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);
	target->draw(this->text);
	this->renderButtons(target);
}

void MenuState::updateButtons()
{
	for (auto it : this->buttons)
	{
		it.second->update(this->MouseView);
	}

	if (this->buttons["LoadGameState"]->isPressed())
	{
		this->States->push(new GameState(this->window, this->States));
	}

	if (this->buttons["How2PlayState"]->isPressed())
	{
		this->States->push(new How2State(this->window, this->States));
	}

	if (this->buttons["CloseApp"]->isPressed())
	{
		this->End = true;
	}

}

void MenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto it : this->buttons)
	{
		it.second->render(target);
	}
}
