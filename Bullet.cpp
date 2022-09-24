#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed)
{
	this->sprite.setPosition(posX, posY);
	this->sprite.setTexture(*texture);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = movementSpeed;
}

Bullet::Bullet()
{
	this->movementSpeed = 0;
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
	//Movement
	this->sprite.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
