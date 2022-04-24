#include "Potions.h"

void Potions::initVariables()
{
	this->speed = 2.5f;
}

Potions::Potions(float pos_X, float pos_Y)
{
	this->shape = new sf::CircleShape(40.f, 100);
	this->setPosition(pos_X, pos_Y);
	texture.loadFromFile("Textures/Potion.png");
	this->setTexture(&texture);
	this->shape->setTextureRect(sf::IntRect(11, 11, 125, 125));
	this->initVariables();

}

Potions::~Potions()
{

}

void Potions::update()
{
	this->shape->move(0.f, speed);
}

void Potions::render(sf::RenderTarget* target)
{
	target->draw(*this->shape);
}