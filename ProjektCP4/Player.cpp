#include "Player.h"

void Player::initVariables()
{
	this->speed = 1000.f;

	this->cdMax = 5.f;
	this->cd = this->cdMax;

	this->hpMax = 5;
	this->hp = 3;
}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Textures/ship.png"))
		throw "COULD NOT LOAD TEXTURE";
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.scale(0.2f, 0.2f);
}

Player::Player(float pos_X, float pos_Y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(pos_X, pos_Y);
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::addHP(const int value)
{
	if (this->hp < 5)
	{
		this->hp += value;
	}
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::move(const float dt, const float dirX, const float dirY)
{
	this->sprite.move(this->speed * dirX * dt, this->speed * dirY * dt);
}

const bool Player::CheckAttack()
{
	if (this->cd >= this->cdMax)
	{
		this->cd = 0.f;
		return true;
	}

	return false;
}

void Player::updateCD()
{
	if (this->cd < this->cdMax)
	{
		this->cd += 0.5f;
	}
}

void Player::update()
{
	this->updateCD();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}