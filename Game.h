#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <map>

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event event;
	float spawnTimer;
	float spawnTimerMax;


	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;
	std::vector<Enemy*> enemies;

	//Player
	Player* player;

	//Private functions

	void initializeWindow();
	void initializeTextures();
	void initializePlayer();
	void initializeEnemies();
public:
	// Constructors/Destructors
	Game();
	~Game();

	//Run Game functions
	void updateEnemies();
	void updateBullets();
	void updatePollEvents();
	void updateInput();
	void run();
	void update();
	void render();

};

