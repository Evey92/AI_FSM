#include "pch.h"
#include "Window.h"

/**
 * @brief Rectangle functions
 */
void
Window::Create()
{
  m_appWindow.create(sf::VideoMode(1600, 1000), "Galahads Holy Grail");
}

void
Window::SetRectangleSize(sf::Vector2f size) {
  m_Testshape.setSize(size);
}

void
Window::SetRectanglePosition(sf::Vector2f position) {
  m_Testshape.setPosition(position);
}

void
Window::SetRectangleColor(sf::Color color) {
  m_Testshape.setFillColor(color);
}

void
Window::SetRectangle(sf::Vector2f size, 
                     sf::Vector2f position,
                     sf::Color color) {

  Window::SetRectangleSize(size);
  Window::SetRectanglePosition(position);
  Window::SetRectangleColor(color);

}

void
Window::SetRectangle(sf::Vector2f size, sf::Vector2f position) {
  Window::SetRectangleSize(size);
  Window::SetRectanglePosition(position);
}

/**
 * @brief Text functions
 */
void
Window::setTextString(std::string text) {
  m_text.setString(text);
}

void
Window::setTextPosition(sf::Vector2f position) {
  m_text.setPosition(position);
}

void
Window::setTextFont(const sf::Font& font) {
  m_text.setFont(font);
}

void
Window::setTextColor(sf::Color color) {
  m_text.setFillColor(color);
}

void
Window::setText(std::string text, sf::Vector2f position,
  sf::Color color, const sf::Font& font) {

  Window::setTextString(text);
  Window::setTextPosition(position);
  Window::setTextFont(font);
  Window::setTextColor(color);

}

void
Window::setText(std::string text, sf::Vector2f position,
  sf::Color color) {

  Window::setTextString(text);
  Window::setTextPosition(position);
  Window::setTextColor(color);

}

void
Window::setText(std::string text, sf::Vector2f position) {
  
  Window::setTextString(text);
  Window::setTextPosition(position);

}

/**
 * @brief Sprite functions
 */
void
Window::setSpritePosition(sf::Vector2f position) {
  
  m_sprite.setPosition(position);

}

void
Window::setSpriteTexture(const sf::Texture& texture) {

  m_sprite.setTexture(texture, true);

}

void
Window::setSpriteColor(sf::Color color) {

  m_sprite.setColor(color);

}

void
Window::setSprite(sf::Vector2f position, const sf::Texture& texture,
  sf::Color color) {

  Window::setSpritePosition(position);
  Window::setSpriteTexture(texture);
  Window::setSpriteColor(color);

}
