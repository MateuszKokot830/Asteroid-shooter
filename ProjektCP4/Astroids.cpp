#include "Astroids.h"

void Astroids::initVariables()
{
	this->speed = 2.0f;
}

Astroids::Astroids(float pos_X, float pos_Y)
{
	this->shape = new sf::CircleShape(40.f, 100);
	this->setPosition(pos_X, pos_Y);
	texture.loadFromFile("Textures/Asteroid.png");
	this->setTexture(&texture);
	this->shape->setTextureRect(sf::IntRect(52, 11, 94, 94));
	this->initVariables();

}

Astroids::~Astroids()
{

}

void Astroids::update()
{
	this->shape->move(0.f, speed);
}

void Astroids::render(sf::RenderTarget* target)
{
	target->draw(*this->shape);
}
