#include "How2State.h"

void How2State::initFonts()
{
	if (!this->font.loadFromFile("arial.ttf"))
	{
		throw ("ERRROR: FONT NOT LOADED");
	}
}

void How2State::initButtons()
{

	this->buttons["Back2MenuState"] = new MenuStateButtons(200, 700, 300, 80, &this->font, "BACK TO MENU", sf::Color(192, 192, 192), sf::Color(150, 150, 150));
	this->buttons["CloseApp"] = new MenuStateButtons(600, 700, 300, 80, &this->font, "EXIT GAME", sf::Color(192, 192, 192), sf::Color(150, 150, 150));
}

void How2State::initTextures()
{
	this->textures["Player"] = new sf::Texture();
	this->textures["Player"]->loadFromFile("Textures/Ship.png");
	this->textures["Bullet"] = new sf::Texture();
	this->textures["Bullet"]->loadFromFile("Textures/Bullet.png");
	this->textures["HPBar"] = new sf::Texture();
	this->textures["HPBar"]->loadFromFile("Textures/HPBar.png");
	this->textures["Astroid"] = new sf::Texture();
	this->textures["Astroid"]->loadFromFile("Textures/Asteroid.png");
	this->textures["Potion"] = new sf::Texture();
	this->textures["Potion"]->loadFromFile("Textures/Potion.png");
	this->textures["Obstacle"] = new sf::Texture();
	this->textures["Obstacle"]->loadFromFile("Textures/Obstacles.png");
}

void How2State::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));

	if (!this->Texture.loadFromFile("Textures/Background.png"))
	{
		throw "ERROR: BACKGROUND TEXTURE NOT LOADED";
	}
	this->background.setTexture(&this->Texture);
}

void How2State::initSpirites()
{
	this->player.setTexture(*this->textures["Player"]);
	this->player.scale(0.15f, 0.15f);
	this->player.setPosition(sf::Vector2f(20.f, 100.f));
	this->bullet.setTexture(*this->textures["Bullet"]);
	this->bullet.scale(1.5f, 1.5f);
	this->bullet.setPosition(sf::Vector2f(40.f, 200.f));
	this->hpBar.setTexture(*this->textures["HPBar"]);
	this->hpBar.scale(0.12f, 0.3f);
	this->hpBar.setPosition(sf::Vector2f(10.f, 350.f));
	this->Astroid.setRadius(40.f);
	this->Astroid.setTexture(this->textures["Astroid"]);
	this->Astroid.setTextureRect(sf::IntRect(52, 11, 94, 94));
	this->Astroid.setPosition(sf::Vector2f(40.f, 400.f));
	this->Potion.setRadius(40.f);
	this->Potion.setTexture(this->textures["Potion"]);
	this->Potion.setTextureRect(sf::IntRect(11, 11, 125, 125));
	this->Potion.setPosition(sf::Vector2f(40.f, 500.f));
	this->Obstacle.setSize(sf::Vector2f(120.f, 30.f));
	this->Obstacle.setTexture(this->textures["Obstacle"]);
	this->Obstacle.setPosition(sf::Vector2f(10.f, 640.f));
	
}

void How2State::initText()
{

	this->text1.setFont(this->font);
	this->text1.setCharacterSize(30);
	this->text1.setFillColor(sf::Color::Red);
	this->text1.setString("Welcome to my version of astroid shooter! \n     Here you can see rules of the game:");
	this->text1.setPosition(sf::Vector2f(300.f, 30.f));

	this->text2.setFont(this->font);
	this->text2.setCharacterSize(25);
	this->text2.setFillColor(sf::Color::Green);
	this->text2.setString("1) In this game you control a spaceship, use WASD or Arrow keys in order to move!");
	this->text2.setPosition(sf::Vector2f(140.f, 140.f));

	this->text3.setFont(this->font);
	this->text3.setCharacterSize(25);
	this->text3.setFillColor(sf::Color::Green);
	this->text3.setString("2) Shoot missles by clicking Mouse or Space buttons. Be careful, ammo has cooldown!");
	this->text3.setPosition(sf::Vector2f(140.f, 260.f));

	this->text4.setFont(this->font);
	this->text4.setCharacterSize(25);
	this->text4.setFillColor(sf::Color::Green);
	this->text4.setString("3) You start with 3 lives. You can collect extra healths (up to 5). If you lose them, you die!");
	this->text4.setPosition(sf::Vector2f(140.f, 360.f));

	this->text5.setFont(this->font);
	this->text5.setCharacterSize(25);
	this->text5.setFillColor(sf::Color::Green);
	this->text5.setString("4) Shoot astroids in order to destroy them. If you miss or you get hit - you lose 1 HP. \n    You earn 1 point for destroying each astroid! Try to improve your highscore ;)");
	this->text5.setPosition(sf::Vector2f(140.f, 410.f));

	this->text6.setFont(this->font);
	this->text6.setCharacterSize(25);
	this->text6.setFillColor(sf::Color::Green);
	this->text6.setString("5) Pick up bonus health points, they cannot be shot down. Each Potion is 1 bonus HP (up to 5)");
	this->text6.setPosition(sf::Vector2f(140.f, 520.f));

	this->text7.setFont(this->font);
	this->text7.setCharacterSize(25);
	this->text7.setFillColor(sf::Color::Green);
	this->text7.setString("6) Dodge dangerous meteroids, you can't shoot them. If you get hit - you lose 1 HP. \n    You earn 3 points for dodging each of the magma's meteroids! ");
	this->text7.setPosition(sf::Vector2f(140.f, 620.f));

}

How2State::How2State(sf::RenderWindow* window, std::stack<State*>* States)
	: State(window, States)
{
	this->initBackground();
	this->initFonts();
	this->initButtons();
	this->initTextures();
	this->initSpirites();
	this->initText();

}

How2State::~How2State()
{
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	for (auto& i : this->buttons)
	{
		delete i.second;
	}
}

void How2State::FinishState()
{

}

void How2State::updateKeybinds()
{
	this->CheckEnd();
}

void How2State::update(const float& dt)
{
	this->updateMousePos();
	this->updateKeybinds();
	this->updateButtons();

}

void How2State::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);
	target->draw(this->player);
	target->draw(this->bullet);
	target->draw(this->hpBar);
	target->draw(this->Astroid);
	target->draw(this->Potion);
	target->draw(this->Obstacle);
	this->renderButtons(target);
	this->renderText(target);
}

void How2State::renderText(sf::RenderTarget* target)
{
	target->draw(this->text1);
	target->draw(this->text2);
	target->draw(this->text3);
	target->draw(this->text4);
	target->draw(this->text5);
	target->draw(this->text6);
	target->draw(this->text7);
}

void How2State::updateButtons()
{
	for (auto it : this->buttons)
	{
		it.second->update(this->MouseView);
	}

	if (this->buttons["Back2MenuState"]->isPressed())
	{
		this->States->push(new MenuState(this->window, this->States));
	}

	if (this->buttons["CloseApp"]->isPressed())
	{
		this->End = true;
	}
}

void How2State::renderButtons(sf::RenderTarget* target)
{
	for (auto it : this->buttons)
	{
		it.second->render(target);
	}
}