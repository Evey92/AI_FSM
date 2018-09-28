#include "pch.h"
#include "App.h"
#include <iostream>

App::App() {

  m_currentState = nullptr;
  m_logoState =  LogoState();
  m_menuState = MenuState();
  m_playState = PlayState();
  m_pauseState = PauseState();
  m_gameOverState = GameOverState();
  m_helpState = HelpState();
  m_optionState = OptionsState();
  m_gameplayState = GameplayState();
  m_graphicState = GraphicsState();
  m_soundStae = SoundState();
  setState(&m_logoState);
  m_windowManager.Create();

}

void 
App::setState(AppState* pNewState) {
  
  //Load the logo for the first time.
  
  if (m_currentState == nullptr) {
    
    m_stateStack.push(pNewState);
    m_currentState = pNewState;
    m_currentState->m_pApp = this;
    m_currentState->OnEnter();
    
  }

  //Check if game is paused
  else 
  {
      m_currentState->OnExit();
      //delete(m_currentState);
      m_stateStack.push(pNewState);
      m_currentState = m_stateStack.top();
      m_currentState->m_pApp = this;
      m_currentState->OnEnter();
  }
}

void 
App::Update()
{
  while (m_windowManager.m_appWindow.isOpen()) {
    
    while (m_windowManager.m_appWindow.pollEvent(m_windowManager.m_event)) {
      
      if (m_windowManager.m_event.type == sf::Event::Closed) {
        m_windowManager.m_appWindow.close();
      }

      else {
        if (m_stateStack.empty()) {
          std::cout << "Stack is empty" << std::endl;
        }
        else {
          m_currentState->OnUpdate();
        }
      }
    }

    m_windowManager.m_appWindow.clear();
    m_windowManager.m_appWindow.draw(m_windowManager.m_Testshape);
    m_windowManager.m_appWindow.draw(m_windowManager.m_sprite);
    m_windowManager.m_appWindow.draw(m_windowManager.m_text);
    m_windowManager.m_appWindow.display();
  }
  
}