#include "Objects.h"

void Objects::initVariables()
{
	this->texture = NULL;
	this->shape = NULL;
}

Objects::Objects()
{
	this->initVariables();
}

Objects::~Objects()
{
	delete this->shape;
}

void Objects::setTexture(sf::Texture* texture)
{
	this->texture = texture;
	this->shape->setTexture(this->texture);
}

const sf::FloatRect Objects::getBounds() const
{
	return this->shape->getGlobalBounds();
}

void Objects::setPosition(float pos_X, float pos_Y)
{
	if (this->shape)
	{
		this->shape->setPosition(pos_X, pos_Y);
	}
}


