#ifndef GRABBABLE_HPP_INCLUDED
#define GRABBABLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Grabbable
{
  bool grabbed = false;
  bool hover = false;

  sf::Color fill_color;
  sf::Color grab_color;
  sf::Color hover_color;
  sf::RectangleShape box;
  sf::Vector2f pos, size;

  public:

    Grabbable(float my_x, float my_y, float my_width, float my_height, const sf::Color color);

    void set_grabbed(bool is_grabbed);
    void set_hover(bool is_hover);
    void set_pos(float new_x, float new_y);
    void set_pos(sf::Vector2f new_pos);
    void set_fill_color(sf::Color new_color);
    void set_grab_color(sf::Color new_color);
    void set_hover_color(sf::Color new_color);
    void drag(sf::Vector2f new_pos);

    bool get_grabbed();
    bool get_hover();
    float get_x();
    float get_y();
    sf::Vector2f get_pos();
    sf::Vector2f get_size();

    sf::RectangleShape rectangle_shape(float mouse_x, float mouse_y);
};

#endif // GRABBABLE_HPP_INCLUDED
