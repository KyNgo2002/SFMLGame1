#include "Game.h"


//Private Functions
void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "SFML GAME 1", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initializeTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	if (!this->textures["BULLET"]->loadFromFile("Textures/bullet.png")) {
		std::cout << "ERROR::GAME::INTIALIZETEXTURES::FAILED TO LOAD BULLET TEXTURE" << std::endl;
	}
	else
	{
		std::cout << "SUCCESSFULLY RENDERED BULLET TEXTURE" << std::endl;
	}
}

void Game::initializePlayer()
{
	this->player = new Player();
}

void Game::initializeEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

//Constructor/Destructor
Game::Game()
{
	this->initializeWindow();
	this->initializeTextures();
	this->initializePlayer();
	this->initializeEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	// Delete Textures
	for (auto& texture : this->textures)
	{
		delete texture.second;
	}
	// Delete Bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}
	// Delete Enemies
	for (auto* enemy : this->enemies)
	{
		delete enemy;
	}
}


void Game::updateEnemies()
{
	this->spawnTimer += 1.f;
	if (this->spawnTimerMax <= this->spawnTimer)
	{
		this->enemies.push_back(new Enemy(rand() % 200, rand() % 200));
		this->spawnTimer = 0.f;
	}

	for (auto* enemy : this->enemies)
	{
		enemy->update();
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* i : this->bullets)
	{
		i->update();
		if (i->getBounds().top + i->getBounds().height < 0.f) 
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

//Public Functions
void Game::updatePollEvents()
{
	// Polls user events through an event object(Game.h)
	while (this->window->pollEvent(event))
	{
		// Clicked close window
		if (event.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		// Clicked escape
		else if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::updateInput()
{
	// Detect key pressed (WASD), and move player corresondingly
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(0.f, 1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(0.f, -1.f);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(textures["BULLET"], this->player->getPosition().x + 30.f, this->player->getPosition().y, 0.f, -1.f, 10.f));
	}
}

//Main game loop
void Game::run()
{
	// While the window is open, call update() and render()
	// update(): updates game state(player movement, enemy generation, positions)
	// render(): renders previous updates to the RenderWindow
	while (this->window->isOpen())
	{
		update();
		render();
	}
}

void Game::update()
{
	
	this->updatePollEvents();
	this->updateInput();
	this->player->update();
	this->updateBullets();
	this->updateEnemies();
}

void Game::render()
{

	// Renders objects to the RenderWindow
	// 1. Clear the previous screen
	// 2. Draw all of the elements onto the screen.
	// 3. Display elements to screen using display();

	this->window->clear();

	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(*this->window);
	}
	for (auto* enemy : enemies)
	{
		enemy->render(*this->window);
	}

	this->window->display();
}
