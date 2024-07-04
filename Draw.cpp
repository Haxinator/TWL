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

		//Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//Draw Thomas
		m_Window.draw(m_Thomas.getSprite());

		//Draw Bob
		m_Window.draw(m_Bob.getSprite());
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

		//Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw bob
		m_Window.draw(m_Bob.getSprite());

		//draw Thomas
		m_Window.draw(m_Thomas.getSprite());

		//now draw bob's screen

		//switch to background view
		m_Window.setView(m_BGRightView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to m_rightview
		m_Window.setView(m_RightView);

		//draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw Thomas
		m_Window.draw(m_Thomas.getSprite());

		//draw bob
		m_Window.draw(m_Bob.getSprite());
	}

	//Draw the HUD
	//switch to m_HudView
	m_Window.setView(m_HudView);

	//show everything we have just drawn
	m_Window.display();
}