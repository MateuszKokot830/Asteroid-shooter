#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*> *States)
{
	this->window = window;
	this->States = States;
	this->End = false;
}

State::~State()
{

}

const bool& State::Exit() const
{
	return this->End;
}

void State::CheckEnd()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->End = true;
	}
}

void State::updateMousePos()
{
	this->MouseScreen = sf::Mouse::getPosition();
	this->MouseWindow = sf::Mouse::getPosition(*this->window);
	this->MouseView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}
