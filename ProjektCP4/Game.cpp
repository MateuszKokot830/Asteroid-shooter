#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1200,800), "ProjektCP4 - Asteroid Shooter", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
	this->States.push(new MenuState(this->window, &this->States));
}

Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->States.empty())
	{
		delete this->States.top();
		this->States.pop();
	}
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateEvents();
		this->update();
		this->updateDt();
		this->render();
	}
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::EndApp()
{

}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->eventes))
	{
		if (this->eventes.type == sf::Event::Closed)
			this->window->close();
		if (this->eventes.KeyPressed && eventes.key.code == sf::Keyboard::Escape)
			this->window->close();
	}

}

void Game::update()
{

	if (!this->States.empty())
	{
		this->States.top()->update(this->dt);

		if (this->States.top()->Exit())
		{
			this->EndApp();
			this->window->close();
		}
	}
	else
	{
		this->EndApp();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	if (!this->States.empty())
	{
		this->States.top()->render();
	}

	this->window->display();
}
