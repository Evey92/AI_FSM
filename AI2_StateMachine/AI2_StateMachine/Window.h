#pragma once
#include <SFML/Graphics.hpp>

class Window {
 public:
  
   Window() {m_font.loadFromFile("Roboto-Bold.ttf");
             m_text.setCharacterSize(30);};
  ~Window() {};
  
  void
  Create();
    
  /**
   * @brief Rectangle functions
   */
  void 
  SetRectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color);

  void
  SetRectangle(sf::Vector2f size, sf::Vector2f position);
  
  void 
  SetRectangleSize(sf::Vector2f size);
  
  void 
  SetRectangleColor(sf::Color color);
  
  void 
  SetRectanglePosition(sf::Vector2f position);

 /**
  * @brief Sprite functions
  */
  void
  setTextString(std::string text);

  void
  setTextPosition(sf::Vector2f position);

  void
  setTextFont(const sf::Font& font);

  void
  setTextColor(sf::Color color);

  void
  setText(std::string text, sf::Vector2f position,
          sf::Color color, const sf::Font& font);
  void
  setText(std::string text, sf::Vector2f position,
      sf::Color color);

  void
  setText(std::string text, sf::Vector2f position);
  /**
  * @brief Sprite functions
  */
  void
  setSpritePosition(sf::Vector2f position);

  void
  setSpriteTexture(const sf::Texture& texture);

  void
  setSpriteColor(sf::Color color);

  void
  setSprite(sf::Vector2f position, const sf::Texture& texture,
            sf::Color color);

 public:
  
  sf::RenderWindow m_appWindow;
  sf::RectangleShape m_Testshape;
  sf::Sprite m_sprite;
  sf::Font m_font;
  sf::Text m_text;
  sf::Event m_event;
};