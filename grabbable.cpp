#include "grabbable.hpp"

Grabbable::Grabbable(float my_x, float my_y, float my_width, float my_height, const sf::Color color):
  size(sf::Vector2f(my_width, my_height))
{
  pos = sf::Vector2f(my_x, my_y);
  box.setPosition(pos);
  box.setSize(size);
  box.setFillColor(color);
  grab_color = sf::Color::White;
  hover_color = sf::Color::Yellow;
}

void Grabbable::set_grabbed(bool is_grabbed) { grabbed = is_grabbed; }
void Grabbable::set_hover(bool is_hover) { hover = is_hover; }

void Grabbable::set_pos(float new_x, float new_y)
{
  sf::Vector2f new_pos = sf::Vector2f(new_x, new_y);
  box.setPosition(new_pos);
  pos = new_pos;
}

void Grabbable::set_pos(sf::Vector2f new_pos)
{
  box.setPosition(new_pos);
  pos = new_pos;
}

void Grabbable::set_fill_color(sf::Color new_color)
{
  box.setFillColor(new_color);
  fill_color = new_color;
}
void Grabbable::set_grab_color(sf::Color new_color) { grab_color = new_color; }
void Grabbable::set_hover_color(sf::Color new_color) { hover_color = new_color; }

void Grabbable::drag(sf::Vector2f new_pos)
{
    if (grabbed)
    {
      box.setPosition(new_pos);
      pos = new_pos;
    }
}

bool Grabbable::get_grabbed() {return grabbed;}
float Grabbable::get_x() {return pos.x;}
float Grabbable::get_y() {return pos.y;}
sf::Vector2f Grabbable::get_pos() {return pos;}
sf::Vector2f Grabbable::get_size() {return size;}


sf::RectangleShape Grabbable::rectangle_shape(float mouse_x, float mouse_y)
{
  if (grabbed)
  {
    box.setOutlineThickness(5.f);
    box.setOutlineColor(grab_color);
  }
  else if (hover)
  {
    box.setOutlineThickness(5.f);
    box.setOutlineColor(hover_color);
  }
  else
     box.setOutlineThickness(0.f);

  return box;
}
