#include "grabbable.hpp"

#include <vector>

int round (float num, int multiple)
{
  return ((int)(num + multiple) / multiple) * multiple;
}

int main()
{
  bool clicked = false;
  bool left_down = false;
  int mode = 2; //edit mode
  // Create the main window
  sf::RenderWindow App(sf::VideoMode::getFullscreenModes()[1], "FactoryScape", sf::Style::Close);
  App.setVisible(false);
  std::vector<Grabbable> blocks;
  blocks.push_back(Grabbable(00.f, 00.f, 50.f, 50.f, sf::Color::Blue));
  blocks.push_back(Grabbable(300.f, 300.f, 50.f, 50.f, sf::Color::Red));

  App.setVisible(true);
	// Start the game loop
  while (App.isOpen())
  {
    // Process events
    sf::Event Event;
    while (App.pollEvent(Event))
    {
      if (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Escape)
        App.close();

      // Close window : exit
      if (Event.type == sf::Event::Closed)
        App.close();
    }


    // Clear screen
    App.clear();


    // switching modes
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
      mode = 1;
      clicked = false;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
      mode = 2;
      clicked = false;
    }

    // work out whether the left button was pressed then released again.
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      left_down = true;

    if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
      if (left_down)
      {
        clicked = true;
        left_down = false;
      }
    }

    // draw grid


    switch (mode)
    {
      case 2:
          for (std::vector<int>::size_type i = 0; i < blocks.size(); i++)
          {
            float mouse_x = sf::Mouse::getPosition().x;
            float mouse_y = sf::Mouse::getPosition().y;
            sf::Vector2f pos = blocks[i].get_pos();
            sf::Vector2f size = blocks[i].get_size();

            if ((mouse_x >= pos.x && mouse_x <= (pos.x + size.x)) && (mouse_y > pos.y && mouse_y < pos.y + size.y))
            {
              if (clicked)
              {
                blocks[i].set_grabbed(!blocks[i].get_grabbed());
                clicked = false;
              }
              else
              {
                blocks[i].set_hover(true);

              }
            }
            else
            {
              if (clicked)
              {
                if (blocks[i].get_grabbed())
                  blocks[i].set_grabbed(false);
              }
              blocks[i].set_hover(false);
            }


            blocks[i].drag(sf::Vector2f(round(mouse_x - (size.x), 50), round(mouse_y - (size.y), 50)));
            // Draw the sprite
            App.draw(blocks[i].rectangle_shape(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
          }
        break;
    }

    // Update the window
    App.display();
  }

  return EXIT_SUCCESS;
}
