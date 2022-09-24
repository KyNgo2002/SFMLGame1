#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
class Player
{
private:
	//Variables
	sf::Sprite sprite;
	sf::Texture texture;
	
	float attackCooldown;
	float attackCooldownMax;
	float maxMovementSpeed;

	//Private functions
	void initializeTexture();
	void initializeSprite();
	void initializeVariables();
public:
	//Constructors/Destructor
	Player();
	~Player();

	//Accessors
	const sf::Vector2f& getPosition() const;
	const bool canAttack();

	//Player functions
	void updateAttack();
	void update();
	void move(const float dirX, const float dirY);
	void render(sf::RenderTarget& target);
}; //Player class
#endif
