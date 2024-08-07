#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;

	//Make rect for all his parts
	FloatRect detectionZone = character.getPosition();

	//Make a floatRect to test each block
	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	//Build a zone around thomas to detect collisions
	int startX = (int) (detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;

	//Thomas is tall so check a few tiles vertically
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	//Make sure we don't test positions lower than zero.
	//or higher than the end of the array
	if (startX < 0)
	{
		startX = 0;
	}
	if (startY < 0)
	{
		startY = 0;
	}
	if (endX >= m_LM.getLevelSize().x)
	{
		endX = m_LM.getLevelSize().x;
	}
	if (endY >= m_LM.getLevelSize().y)
	{
		endY = m_LM.getLevelSize().y;
	}

	//Has the character fallen out of the map?
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);

	if (!character.getPosition().intersects(level))
	{
		//respawn the character
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}

	//loop through all local blocks
	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			//Initalise the starting position of the current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			//Has the character been burnt or drowned?
			//Use head as this allows him to sink a bit.
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					character.spawn(m_LM.getStartPosition(), GRAVITY);

					//which sound should be played?
					if (m_ArrayLevel[y][x] == 2)
					{
						//fire
					}
					else 
					{
						//water
					}
				}
			}

			//Is character colliding with a regular block
			if (m_ArrayLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}

				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}

			}

			//More collision detection here

			//Has the character reached the goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				//Character has reached the goal
				reachedGoal = true;
			}

		}

	}

	//all done return whether a new level is required
	return reachedGoal;
}