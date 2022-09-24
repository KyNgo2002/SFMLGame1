#include "Enemy.h"

void Enemy::initializeVariables()
{
	type = 0;
	hp = 10;
	hpMax = 10;
	damage = 1;
	points = 5;
}

void Enemy::initializeShape()
{
	this->shape.setRadius(rand() % 20 + 20);
	this->shape.setPointCount(rand() % 15 + 3);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

Enemy::Enemy()
{
	this->initializeShape();
	this->initializeVariables();
}

Enemy::Enemy(float posX, float posY)
{
	this->initializeShape();
	this->initializeVariables();
	this->shape.setPosition(posX, posY);
}

Enemy::~Enemy()
{
	
}

void Enemy::update()
{
	
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
