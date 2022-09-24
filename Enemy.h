#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	//Variables
	sf::CircleShape shape;

	int type;
	int hp;
	int hpMax;
	int damage;
	int points;
	//Resources
	

	//Functions
	void initializeVariables();
	void initializeShape();
public:
	//Constructors
	Enemy();
	Enemy(float posX, float posY);
	~Enemy();

	//Functions;
	
	void update();
	void render(sf::RenderTarget& target);
};
#endif

