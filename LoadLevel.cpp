#include "Engine.h"

void Engine::loadLevel()
{
	m_Playing = false;

	//Delete previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}

	delete m_ArrayLevel;

	//load the next 2d arry with the map for the level
	//repopulate the vertex array as well
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	//How long is this new time limit
	m_TimeRemaining = m_LM.getTimeLimit();

	//Spawn Thomas and Bob
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);

	//make sure code isn't run again
	m_NewLevelRequired = false;
}