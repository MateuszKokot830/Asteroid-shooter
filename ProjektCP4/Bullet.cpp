#include "Bullet.h"

Bullet::Bullet(sf::Texture * texture, float pos_X, float pos_Y, float X, float Y, float speed)
{
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos_X, pos_Y);

	this->dir.x = X;
	this->dir.y = Y;
	this->speed = speed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Bullet::update()
{
	this->sprite.move(this->speed * this->dir);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}