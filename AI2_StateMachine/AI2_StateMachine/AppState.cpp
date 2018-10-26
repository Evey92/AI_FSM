#include "pch.h"
#include "AppState.h"
#include "App.h"
#include <iostream>

void 
LogoState::OnEnter() {
 
 
  m_pApp->m_windowManager.m_textureLogo.loadFromFile("DarkDeep.png");
  std::cout << "I'm at the Logo"<< std::endl;

  m_pApp->m_windowManager.setSpritePosition(sf::Vector2f(400, 200));
  m_pApp->m_windowManager.SetRectangle(sf::Vector2f(800, 600),
                                       sf::Vector2f(300, 300),
                                       sf::Color::Black);
  m_pApp->m_windowManager.setSpriteTexture(m_pApp->m_windowManager.m_textureLogo);
   
}

void 
LogoState::OnUpdate() {

  std::cout << "I'm on Logo's update" << std::endl;
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
      (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Space)) {
    
    m_pApp->setState(m_pApp->m_menuState);
  
  }
}

void
LogoState::OnExit() {
  std::cout << "I'm getting out of the Logo" << std::endl;
  m_pApp->m_stateStack.pop();
}

void
MenuState::OnEnter() {
  std::cout << "I'm at the Menu" << std::endl;
  std::string message = ("Welcome to Galahad's Holy Grail!\n\n\n\n\n\t\t\t\t\t\tMain Menu\n\n\nPresiona Enter para jugar. \nPresiona O para opciones.");
  m_pApp->m_windowManager.SetRectangle(sf::Vector2f(1200, 800), 
                                       sf::Vector2f(200, 50),
                                       sf::Color::White);
  m_pApp->m_windowManager.setText(message, sf::Vector2f(500, 200),
                                  sf::Color::Black,
                                  m_pApp->m_windowManager.m_font);
  m_pApp->m_windowManager.setSpriteColor(sf::Color::Transparent);
  
}

void 
MenuState::OnUpdate() {
  std::cout << "I'm at the Menu's update" << std::endl;
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
      (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::O)) {

    m_pApp->setState(m_pApp->m_optionState);
  
  }
  else if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Enter)) {

    m_pApp->setState(m_pApp->m_playState);
  }
}

void 
MenuState::OnExit() {
  m_pApp->m_stateStack.pop();
}

void 
PlayState::OnEnter() {

  std::string message = ("GAME\n\nPress Esc for pause\nPress H for Help\nPress G to game over");
  std::cout << "We just entered Game" << std::endl;
  m_pApp->m_windowManager.setText(message, sf::Vector2f(600, 500));
  m_pApp->m_windowManager.SetRectangle(sf::Vector2f(1200, 800),
                                       sf::Vector2f(200, 50));

}

void PlayState::OnUpdate() {

  std::cout << "We're playing babyyyy!" << std::endl;
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
      (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Escape)) {
    
    m_pApp->setState(m_pApp->m_pauseState);
  
  }
  else if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
           (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::G)) {
    
    m_pApp->m_stateStack.pop();
    m_pApp->setState(m_pApp->m_gameOverState);

  }
  else if((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
          (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::H)) {

    m_pApp->setState(m_pApp->m_helpState);
  
  }
}

void 
PlayState::OnExit() {
  //m_pApp->m_stateStack.pop();
}

void 
PauseState::OnEnter() {

  std::string message = ("Pause.\n\nPress escape or enter to get back to the game\nPress O for Options.");
  std::cout << "Paused Game" << std::endl;
  m_pApp->m_windowManager.setText(message, sf::Vector2f(500, 600));
  m_pApp->m_windowManager.SetRectangle(sf::Vector2f(1300, 950), 
                                       sf::Vector2f(50, 50));
  m_pApp->m_isPaused = true;
}

void 
PauseState::OnUpdate() {

  std::cout << "Pause Update!" << std::endl;
  
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Escape || m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Enter)) {
    
    m_pApp->m_stateStack.pop();
    m_pApp->setState(m_pApp->m_playState);
  
  }
  else if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
           (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::O)) {
    
    m_pApp->setState(m_pApp->m_optionState);
  
  }

}

void
PauseState::OnExit() {
  
  std::cout << "Getting out of pause" << std::endl;
  m_pApp->m_stateStack.pop();

}

void
GameOverState::OnEnter() {
  std::cout << "Game Over!" << std::endl;
  m_pApp->m_windowManager.setTextString("Se acabó el jueguito mi estimado.\n\nPresiona Espacio para regresar al menú principal.");
}

void
GameOverState::OnUpdate() {
  
  std::cout << "Game Over Update" << std::endl;
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
      (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Space)) {
    m_pApp->setState(m_pApp->m_menuState);
  }
}

void
GameOverState::OnExit() {
  
  m_pApp->m_stateStack.pop();

}

void
HelpState::OnEnter() {
  
  std::string message = ("THERE'S NO HELP HERE BOI. \n\n\nPresiona Escape para regresar a Juego.");
  std::cout << "Entering a HELP" << std::endl;
  m_pApp->m_windowManager.setText(message, sf::Vector2f(500, 200),
                                  sf::Color::Red,
                                  m_pApp->m_windowManager.m_font);  
  m_pApp->m_windowManager.m_Testshape.setFillColor(sf::Color::White);
  m_pApp->m_windowManager.m_text.setCharacterSize(40);
  
}

void 
HelpState::OnUpdate() {

  std::cout << "HELP!" << std::endl;
  
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Escape)){
    m_pApp->m_windowManager.setTextColor(sf::Color::Black);
    m_pApp->setState(m_pApp->m_playState);
  
  }
}

void
HelpState::OnExit() {
  
  m_pApp->m_stateStack.pop();
  
}

void
OptionsState::OnEnter() {
  
  std::string message = ("Opciones.\n\n\nPresiona el numero del menu al que quieras ingresar\n1.-Gameplay\n2.-Graphics\n3.-Sound\nEsc para salir del menu.");
  std::cout << "Options" << std::endl;
  m_pApp->m_windowManager.setText(message, sf::Vector2f(300, 300));
  
}

void 
OptionsState::OnUpdate() {
  std::cout << "Options' Update" << std::endl;
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Num1)) {
    m_pApp->setState(m_pApp->m_gameplayState);
  }
  else if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Num2)) {
    m_pApp->setState(m_pApp->m_graphicState);
  }
  else if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Num3)) {
    m_pApp->setState(m_pApp->m_soundStae);
  }
  else if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Escape)) {
    if (m_pApp->m_isPaused) {
      m_pApp->setState(m_pApp->m_pauseState);
    }
    else {
      m_pApp->setState(m_pApp->m_menuState);
    }
  }

}

void 
OptionsState::OnExit() {
  
  m_pApp->m_stateStack.pop();
  m_pApp->m_isPaused = false;

}

void 
GameplayState::OnEnter() {

  std::cout << "Gameplay" << std::endl;
  m_pApp->m_windowManager.setTextString("Gameplay Options.\n\n\Por ahora no hay nada mas que hacer aquí D:\nEscape para regresar a opciones.");

}

void 
GameplayState::OnUpdate() {
  std::cout << "Gameplay Update" << std::endl;
 
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Escape)) {

    m_pApp->setState(m_pApp->m_optionState);
  
  }

}

void 
GameplayState::OnExit() {

  m_pApp->m_stateStack.pop();

}

void GraphicsState::OnEnter()
{
  std::cout << "Graphics" << std::endl;
  m_pApp->m_windowManager.setTextString("Graphics Options.\n\n\Por ahora no hay nada mas que hacer aquí :D\nEscape para regresar a opciones.");
}

void
GraphicsState::OnUpdate() {
  std::cout << "Graphics Update" << std::endl;
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Escape)) {
    
    m_pApp->setState(m_pApp->m_optionState);
  
  }
}

void
GraphicsState::OnExit() {

  m_pApp->m_stateStack.pop();

}

void 
SoundState::OnEnter() {
  std::cout << "Estoy en Sound" << std::endl;
  m_pApp->m_windowManager.setTextString("Sound Options.\n\n\Por ahora no hay nada mas que hacer aquí, que sad :(\nEscape para regresar a opciones.");
}

void 
SoundState::OnUpdate() {

  std::cout << "Estoy en el update de Sound" << std::endl;
  if ((m_pApp->m_windowManager.m_event.type == sf::Event::KeyPressed) &&
    (m_pApp->m_windowManager.m_event.key.code == sf::Keyboard::Escape)) {

    m_pApp->setState(m_pApp->m_optionState);
  
  }
}

void 
SoundState::OnExit() {

  m_pApp->m_stateStack.pop();

}