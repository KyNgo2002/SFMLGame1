#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:
	//Variables
	sf::Sprite sprite;


	sf::Vector2f direction;
	float movementSpeed;


public:
	//Constructors
	Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed);
	Bullet();
	~Bullet();

	//Accessors
	const sf::FloatRect getBounds() const;


	//Functions
	void update();
	void render(sf::RenderTarget& target);

};
#endif

