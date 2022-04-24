#include "Obstacles.h"

void Obstacles::initVariables()
{
	this->speed = 1.5f;
}

Obstacles::Obstacles(float pos_X, float pos_Y)
{
	this->shape = new sf::RectangleShape(sf::Vector2f((rand() % 200) + 200.f, 40.f));
	this->setPosition(pos_X, pos_Y);
	texture.loadFromFile("Textures/Obstacles.png");
	this->setTexture(&texture);
	this->initVariables();

}

Obstacles::~Obstacles()
{

}

void Obstacles::update()
{
	this->shape->move(0.f, this->speed);
}

void Obstacles::render(sf::RenderTarget* target)
{
	target->draw(*this->shape);
}