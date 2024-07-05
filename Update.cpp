#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		//load a level
		loadLevel();
	}

	if (m_Playing)
	{
		//update Thomas
		m_Thomas.update(dtAsSeconds);

		//Update Bob
		m_Bob.update(dtAsSeconds);

		//Detect collisions and see if characters reached goal.
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			//New level required if both thomas and bob reached the goal
			m_NewLevelRequired = true;

			//play the goal reached sound
		}
		else
		{
			//Run bobs collision detection
			detectCollisions(m_Bob);
		}

		//Let bob and Thomas jump on each others heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		//Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		//Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	} // end if playing

	//Set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		//center full screen around appropriate character
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}
}