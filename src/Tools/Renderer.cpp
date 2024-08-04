#include <iostream>
// #include <string.h>
// #include <sstream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

void insertSprite(std::string filePath, sf::Vector2f spritePosition);

class Renderer
{
private:
  sf::Font font_JetBrainsMono;

public:
  Renderer();
  ~Renderer();

  void insertText(std::string str, sf::Vector2f pos, int fontSize, sf::Color fontColor);
  // void insertSprite(std::string filePath, sf::Vector2f spritePosition, sf::Texture texture);

  // template <typename T>
  // void insertSprite(std::string filePath, sf::Vector2f spritePosition)
  // {
  //   sf::Texture texture;
  //   sf::Sprite sprite;
  //   if (!texture.loadFromFile(filePath))
  //   {
  //     std::cout << "Error while loading texture: " << filePath << std::endl;
  //   }
  //   texture.setSmooth(true);

  //   sprite.setPosition(spritePosition);

  //   sprite.setTexture(texture);
  //   spriteVect.push_back(sprite);
  // }

  void renderViewport(sf::RenderWindow *window);

  // sf::Sprite sprite;
  // sf::Texture texture;
  std::vector<sf::Text> textVect;
  std::vector<sf::Sprite> spriteVect;
};

Renderer::Renderer()
{
  if (!font_JetBrainsMono.loadFromFile("../res/Fonts/JetBrainsMono-Medium.ttf"))
  {
    std::cout << "Error while loading font: JetBrainsMono-Medium.ttf" << std::endl;
  }
}

Renderer::~Renderer() {}

void Renderer::renderViewport(sf::RenderWindow *window)
{
  for (sf::Text tx : textVect)
  {
    window->draw(tx);
  }
  for (sf::Sprite sp : spriteVect)
  {
    window->draw(sp);
  }
}

void Renderer::insertText(std::string str, sf::Vector2f pos, int fontSize, sf::Color fontColor)
{
  sf::Text createdText;
  createdText.setFont(font_JetBrainsMono);
  createdText.setString(str);
  createdText.setCharacterSize(fontSize);
  createdText.setPosition(pos);
  createdText.setFillColor(fontColor);
  textVect.push_back(createdText);
}

// void Renderer::insertSprite(std::string filePath, sf::Vector2f spritePosition, sf::Texture texture)
// {
//   if (!texture.loadFromFile(filePath))
//   {
//     std::cout << "Error while loading texture: " << filePath << std::endl;
//   }
//   texture.setSmooth(true);

//   sprite.setPosition(spritePosition);

//   sprite.setTexture(texture);
//   spriteVect.push_back(sprite);
// }
