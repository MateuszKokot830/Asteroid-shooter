#include "GameState.h"

void GameState::initPlayer()
{
	this->player = new Player(550.f, 350.f);
}

void GameState::initTextures()
{
	this->textures["Bullet"] = new sf::Texture();
	this->textures["Bullet"]->loadFromFile("Textures/Bullet.png");
	this->textures["HPBar"] = new sf::Texture();
	this->textures["HPBar"]->loadFromFile("Textures/HPBar.png");
}

void GameState::initVariables()
{
	this->MaxTimer = 100.f;
	this->Timer = this->MaxTimer;
	this->Timer2 = this->MaxTimer;
	this->Timer3 = this->MaxTimer;
	this->score = 0;


	std::fstream file;
	file.open("highscore.txt");
	if (file.good() == true)
	{
		getline(file, textfile);
		std::regex rx("\\D");
		std::string string1;
		string1 = std::regex_replace(textfile, rx, "\0");
		std::stringstream ss;
		ss << string1;
		ss >> highscore;
		file.close();
	}


}

void GameState::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));

	if (!this->Texture.loadFromFile("Textures/Background1.png"))
	{
		throw "ERROR: BACKGROUND TEXTURE NOT LOADED";
	}
	this->background.setTexture(&this->Texture);
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("arial.ttf"))
	{
		throw ("ERRROR: FONT NOT LOADED");
	}
}

void GameState::initText()
{
	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(36);
	this->scoreText.setFillColor(sf::Color::Yellow);

	this->HighscoreText.setFont(this->font);
	this->HighscoreText.setCharacterSize(36);
	this->HighscoreText.setFillColor(sf::Color::Yellow);
	this->HighscoreText.setPosition(sf::Vector2f(950.f, 0.f));
}

void GameState::initHPBar()
{
	this->HPBar.setPosition(sf::Vector2f(0.f, 50.f));
	this->HPBar.setTexture(*this->textures["HPBar"]);
	this->HPBar.setScale(0.2f, 0.2f);
}

GameState::GameState(sf::RenderWindow *window, std::stack<State*> *States)
	: State(window, States)
{
	this->initBackground();
	this->initPlayer();
	this->initTextures();
	this->initVariables();
	this->initFonts();
	this->initText();
	this->initHPBar();
}

GameState::~GameState()
{

	delete this->player;

	for (auto& i : this->textures)
	{
		delete i.second;
	}

	for (auto* i : this->bullets)
	{
		delete i;
	}

	for (auto* i : this->astroids)
	{
		delete i;
	}

	for (auto* i : this->potions)
	{
		delete i;
	}

	for (auto* i : this->obstacles)
	{
		delete i;
	}
}

void GameState::FinishState()
{

	if (this->score > this->highscore)
	{
		std::ofstream file;
		file.open("highscore.txt");
		if (file.good() == true)
		{
			std::stringstream ss;
			std::regex rx("\\d");
			std::string string2;
			string2 = std::regex_replace(textfile, rx, "\0");
			ss << score;
			ss >> textfile;
			file << string2;
			file << textfile;
			file.close();
		}
	}

	this->clearObjects();

	this->States->push(new GameOverState(this->window, this->States));
}

void GameState::updatePlayer(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->player->move(dt, -1.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->player->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->player->move(dt, 0.f, -1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->player->move(dt, 0.f, 1.f);
}

void GameState::ScreenCollision()
{
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}

}

void GameState::updateBullet()
{

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Mouse::isButtonPressed(sf::Mouse::Left))
		&& this->player->CheckAttack()
		&& this->bullets.size() <= 6)
	{
		this->bullets.push_back(new Bullet(this->textures["Bullet"], this->player->getPos().x + 50, this->player->getPos().y, 0.f, -1.f, 5.f));
	}

	unsigned count = 0;

	for (auto* bullet : this->bullets)
	{
		bullet->update();

		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			delete this->bullets.at(count);
			this->bullets.erase(this->bullets.begin() + count);
			--count;
		}
		++count;
	}


}

void GameState::updateAstroids()
{
	this->Timer += 0.5f;
	if (this->Timer >= this->MaxTimer)
	{
		this->astroids.push_back(new Astroids( rand()%(this->window->getSize().x-100) + 50.f , 0.f));
			this->Timer = 0.f;
			if (this->MaxTimer > 10.f)
			this->MaxTimer -= 0.1f;
	}

	for (int i = 0; i < this->astroids.size(); ++i)
	{
		bool canErase = false;
		this->astroids[i]->update();

		for (size_t j = 0; j < this->bullets.size() && !canErase; j++)
		{
			if (this->bullets[j]->getBounds().intersects(this->astroids[i]->getBounds()))
			{
				this->score++;
				this->bullets.erase(this->bullets.begin() + j);
				this->astroids.erase(this->astroids.begin() + i);
				canErase = true;
			}
		}

		if (!canErase)
		{
			if (this->astroids[i]->getBounds().top > this->window->getSize().y)
			{
				this->astroids.erase(this->astroids.begin() + i);
				canErase = true;
				this->player->loseHp(1);
			}
			else if (this->astroids[i]->getBounds().intersects(this->player->getBounds()))
			{
				this->astroids.erase(this->astroids.begin() + i);
				canErase = true;
				this->player->loseHp(1);
			}
		}
	}
}

void GameState::updatePotions()
{

	this->Timer2 += 0.2f;
	if (this->Timer2 >= this->MaxTimer)
	{
		this->potions.push_back(new Potions(rand() % (this->window->getSize().x - 100) + 50.f, 0.f));
		this->Timer2 = 0.f;
	}

	for (int i = 0; i < this->potions.size(); ++i)
	{
		bool canErase = false;
		this->potions[i]->update();

		if (!canErase)
		{
			if (this->potions[i]->getBounds().top > this->window->getSize().y)
			{
				this->potions.erase(this->potions.begin() + i);
				canErase = true;
			}
			else if (this->potions[i]->getBounds().intersects(this->player->getBounds()))
			{
				this->potions.erase(this->potions.begin() + i);
				canErase = true;
				this->player->addHP(1);
			}
		}
	}
}

void GameState::updateObstacles()
{
	this->Timer3 += 0.4f;
	if (this->Timer3 >= this->MaxTimer)
	{
		this->obstacles.push_back(new Obstacles(rand() % (this->window->getSize().x - 100) + 50.f, 0.f));
		this->Timer3 = 0.f;
	}

	for (int i = 0; i < this->obstacles.size(); ++i)
	{
		bool canErase = false;
		this->obstacles[i]->update();

		if (!canErase)
		{
			if (this->obstacles[i]->getBounds().top > this->window->getSize().y)
			{
				this->score += 3;
				this->obstacles.erase(this->obstacles.begin() + i);
				canErase = true;
			}
			else if (this->obstacles[i]->getBounds().intersects(this->player->getBounds()))
			{
				this->obstacles.erase(this->obstacles.begin() + i);
				canErase = true;
				this->player->loseHp(1);
			}
		}
	}
}

void GameState::updateText()
{
	std::stringstream string;
	string << "Current score: " << this->score;

	this->scoreText.setString(string.str());

	std::stringstream string2;
	string2 << "Highscore: " << this->highscore;

	this->HighscoreText.setString(string2.str());
}

void GameState::updateHPBar()
{
	switch (this->player->getHp())
	{
	case 0:
		this->HPBar.setTextureRect(sf::IntRect(0, 0, 0, 0));
		break;
	case 1:
		this->HPBar.setTextureRect(sf::IntRect(0, 0, 200, 200));
		break;
	case 2:
		this->HPBar.setTextureRect(sf::IntRect(0, 0, 400, 200));
		break;
	case 3:
		this->HPBar.setTextureRect(sf::IntRect(0, 0, 600, 200));
		break;
	case 4:
		this->HPBar.setTextureRect(sf::IntRect(0, 0, 800, 200));
		break;
	case 5:
		this->HPBar.setTextureRect(sf::IntRect(0, 0, 1200, 200));
		break;
	default:
		break;
	}
}

void GameState::clearObjects()
{
	this->bullets.clear();
	this->astroids.clear();
	this->potions.clear();
	this->obstacles.clear();
}

void GameState::updateKeybinds()
{
	this->CheckEnd();
}

void GameState::update(const float& dt)
{
	this->updateKeybinds();

	if (this->player->getHp() > 0)
	{
		this->updatePlayer(dt);
		this->player->update();
		this->ScreenCollision();
		this->updateBullet();
		this->updateAstroids();
		this->updatePotions();
		this->updateObstacles();
		this->updateText();
		this->updateHPBar();
	}
	else
	{
		this->FinishState();

	}
}

void GameState::render(sf::RenderTarget* Target)
{
	this->window->draw(this->background);
	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* asteroid : this->astroids)
	{
		asteroid->render(this->window);
	}

	for (auto* potion : this->potions)
	{
		potion->render(this->window);
	}

	for (auto* obstacle : this->obstacles)
	{
		obstacle->render(this->window);
	}

	this->window->draw(this->scoreText);
	this->window->draw(this->HighscoreText);
	this->window->draw(this->HPBar);
}