/** @ready:
  g++ -c main.cpp -I /home/sopmod/Downloads/SFML-2.6.1-linux-gcc-64-bit/SFML-2.6.1/include
  g++ main.o -o MineBlocks -L /home/sopmod/Downloads/SFML-2.6.1-linux-gcc-64-bit/SFML-2.6.1/lib -lsfml-graphics
  ./MineBlocks
*/
/** @run:
  clear; neofetch; g++ -c main.cpp -I /home/sopmod/Downloads/SFML-2.6.1-linux-gcc-64-bit/SFML-2.6.1/include; g++ main.o -o MineBlocks -L /home/sopmod/Downloads/SFML-2.6.1-linux-gcc-64-bit/SFML-2.6.1/lib -lsfml-graphics; clear; ./MineBlocks
*/
/** @path:
  /home/sopmod/code/MineBlocks/src
*/

#include "Tools/FileLinks.hpp"
#include "Tools/Declaration.hpp"
using namespace std;
// using namespace sf;

DebugMenu debugMenu;
sf::Event event;

int main(void)
{
  sf::RenderWindow window(sf::VideoMode(1280, 720), "initFailed");
  window.setSize(sf::Vector2u(1280, 720));
  window.setTitle("MineBlocks");

  window.setVerticalSyncEnabled(false);
  window.setFramerateLimit(144);

  while (window.isOpen())
  {
    // check all the window's events that were triggered since the last iteration of the loop

    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
    }

    window.clear(sf::Color::Blue);
    toggleDebugMenu(&window);
    window.display();
  }

  cout << "Terminated by user" << endl;
  return 0;
}

void toggleDebugMenu(sf::RenderWindow *window)
{
  if (oneClick(sf::Keyboard::isKeyPressed(sf::Keyboard::F12)))
  {
    debugMenu.flipState();
  }
  debugMenu.show(debugMenu.getState(), window);
}
