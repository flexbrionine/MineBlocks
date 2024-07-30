#pragma one

bool prev_input = false;
bool oneClick(bool input)
{
  if (input == 1 && prev_input == 0)
  {
    prev_input = input;
    return 1;
  }
  prev_input = input;
  return 0;
}

// void createTextInstance(std::vector<sf::Text> *vect, std::string str, sf::Vector2f pos, int fontSize, sf::Color fontColor)
// {
//   sf::Text createdText;
//   createdText.setString((sf::String)str);
//   vect->push_back(createdText);
// }