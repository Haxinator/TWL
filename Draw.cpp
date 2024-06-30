#include "Engine.h"

void Engine::draw()
{
	//Rub out the last frame
	m_Window.clear(Color::White);

	if (!m_SplitScreen)
	{
		//switch to background view
		m_Window.setView(m_BGMainView);
		//draw background
		m_Window.draw(m_BackgroundSprite);
		//Switch to m_MainView
		m_Window.setView(m_MainView);
	}
	else
	{
		//split screen view is active

		//first draw Thomas's screen

		//switch to background view
		m_Window.setView(m_BGLeftView);
		//draw background
		m_Window.draw(m_BackgroundSprite);
		//switch to left view
		m_Window.setView(m_LeftView);

		//now draw bob's screen

		//switch to background view
		m_Window.setView(m_BGRightView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to m_rightview
		m_Window.setView(m_RightView);
	}

	//Draw the HUD
	//switch to m_HudView
	m_Window.setView(m_HudView);

	//show everything we have just drawn
	m_Window.display();
}