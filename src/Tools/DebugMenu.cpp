#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include "Renderer.cpp"

#define DEBUG_MENU_VERSION_MAJOR 1
#define DEBUG_MENU_VERSION_MINOR 1
#define DEBUG_MENU_VERSION_PATCH 0

Renderer debugPort;

// void createTextInstance(std::vector<sf::Text> *vect, std::string str,
// 												sf::Vector2f pos, int fontSize, sf::Color fontColor, sf::Font *main_font);
// void createSpriteInstance(std::vector<sf::Sprite> *vect, std::string texturePath);
// void loadSprite(std::string filename, std::vector<sf::Sprite> &vect);
sf::Texture t1, t2;

class DebugMenu
{
private:
	bool state = false;
	bool prev_state = false;
	sf::Texture texture;
	std::vector<sf::Text> textVector;
	std::vector<sf::Sprite> spriteVector;

public:
	DebugMenu();
	~DebugMenu();

	bool getState(void) { return state; }
	void setState(bool input) { state = input; }
	void flipState(void) { state = !state; }

	void show(bool is_toggled, sf::RenderWindow *window);
};

DebugMenu::DebugMenu()
{
	//* DebugMenu Items
	std::stringstream debugMenu_version;
	debugMenu_version << "Welcome to DebugMenu v" << DEBUG_MENU_VERSION_MAJOR
										<< '.' << DEBUG_MENU_VERSION_MINOR << '.' << DEBUG_MENU_VERSION_PATCH;
	std::string dm_version_str = debugMenu_version.str();

	std::stringstream sfml_version;
	sfml_version << "SFML version: " << SFML_VERSION_MAJOR
							 << '.' << SFML_VERSION_MINOR << '.' << SFML_VERSION_PATCH;
	std::string sfml_version_str = sfml_version.str();

	debugPort.insertText(dm_version_str, sf::Vector2f(0.0, 0.0), 24, sf::Color::White);
	debugPort.insertText(sfml_version_str, sf::Vector2f(0.0, 26.0), 16, sf::Color::Green);

	// debugPort.insertSprite("../res/Textures/16x9_by_Pengo.png", sf::Vector2f(320.0, 320.0), t1);
	// debugPort.insertSprite("../res/Textures/test300x300image.png", sf::Vector2f(20.0, 20.0), t2);

	// debugPort.insertSprite<sf::Texture>("../res/Textures/16x9_by_Pengo.png", sf::Vector2f(120.0, 20.0));
}

DebugMenu::~DebugMenu() {}

void DebugMenu::show(bool is_toggled, sf::RenderWindow *window)
{
	// TODO: Rewrite using classes
	if (is_toggled)
	{
		debugPort.renderViewport(window);
	}
}

// void createTextInstance(std::vector<sf::Text> *vect, std::string str, sf::Vector2f pos, int fontSize, sf::Color fontColor, sf::Font *main_font)
// {
// 	sf::Text createdText;
// 	createdText.setFont(*main_font);
// 	createdText.setString(str);
// 	createdText.setCharacterSize(fontSize);
// 	createdText.setPosition(pos);
// 	createdText.setFillColor(fontColor);
// 	vect->push_back(createdText);
// }

// void createSpriteInstance(std::vector<sf::Sprite> *vect, std::string texturePath)
// {
// sf::Texture createdTexture;
// if (!createdTexture.loadFromFile((texturePath), sf::IntRect(10, 10, 32, 32)))
// {
// 	std::cout << "Error white loading texture: " << texturePath << std::endl;
// }
// createdTexture.setSmooth(true);
// vect.push_back(createdTexture);
// }

// void loadSprite(std::string filename, std::vector<sf::Sprite> &vect)
// {
// 	sf::Texture texture;
// 	if (!texture.loadFromFile("../res/Textures/test300x300image.png"))
// 	{
// 		std::cout << "Error white loading texture" << std::endl;
// 	}
// 	texture.setSmooth(true);

// 	sf::Sprite sprite;
// 	sprite.setTexture(texture);
// 	vect.push_back(sprite);
// }