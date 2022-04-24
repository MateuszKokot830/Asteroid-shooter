#include "MenuStateButtons.h"

MenuStateButtons::MenuStateButtons(float pos_x, float pos_y, float width, float height, sf::Font* font, std::string text, sf::Color NormalColor, sf::Color HoverColor)
{
	this->Button_state = NoAction;
	this->button.setPosition(sf::Vector2f(pos_x, pos_y));
	this->button.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::Yellow);
	this->text.setCharacterSize(25);
	this->text.setStyle(sf::Text::Bold);
	this->text.setPosition(
		this->button.getPosition().x + (this->button.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->button.getPosition().y + (this->button.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f -5);
	this->NormalColor = NormalColor;
	this->button.setFillColor(this->NormalColor);
	this->HoverColor = HoverColor;

}

MenuStateButtons::~MenuStateButtons()
{

}

const bool MenuStateButtons::isPressed() const
{
	if (this->Button_state == Clicked) {
		return true;
	}
	return false;
}

void MenuStateButtons::update(sf::Vector2f pos)
{
	this->Button_state = NoAction;

	if (this->button.getGlobalBounds().contains(pos))
	{
		this->Button_state = Hovered;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->Button_state = Clicked;
		}
	}

	switch (this->Button_state)
	{
	case NoAction:
		this->button.setFillColor(this->NormalColor);
		break;
	case Hovered:
		this->button.setFillColor(this->HoverColor);
		break;
	case Clicked:
		this->button.setFillColor(this->HoverColor);
		break;
	default:
		this->button.setFillColor(sf::Color::Red);
		break;
	}
}

void MenuStateButtons::render(sf::RenderTarget* target)
{
	target->draw(this->button);
	target->draw(this->text);
}
