#include "Player.h"
#include <iostream>

//Private Functions
void Player::initializeTexture()
{
	//Load texture from file
	if (!this->texture.loadFromFile("Textures/spaceship.png"))
	{
		std::cout << "ERROR::PLAYER::INITIALIZETEXTURE::FAILED TO LOAD TEXTURE FROM FILE" << std::endl;
	}
	else
	{
		std::cout << "SUCESSFULLY LOADED PLAYER TEXTURE FROM FILE." << std::endl;
	}
}

void Player::initializeSprite()
{
	// Gives our sprite a texture
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.scale(0.1f, 0.1f);
}



void Player::initializeVariables()
{	
	// Initializes player movement speed and attack cooldown
	this->maxMovementSpeed = 5.f;
	this->attackCooldownMax = 5.f;
	this->attackCooldown = this->attackCooldownMax;
	
}

//Constructor/Destructor
Player::Player()
{
	this->initializeTexture();
	this->initializeSprite();
	this->initializeVariables();
}
 
Player::~Player()
{
	// Free all pointers in Destructor
}

const sf::Vector2f& Player::getPosition() const
{
	return this->sprite.getPosition();
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}


void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax) {
		this->attackCooldown += 0.5f;
	}
}

//Functions
void Player::update()
{
	this->updateAttack();
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->maxMovementSpeed * dirX, this->maxMovementSpeed * dirY);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
