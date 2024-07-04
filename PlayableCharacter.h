#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
protected:
	Sprite m_Sprite;

	//jump duration
	float m_JumpDuration;

	//Is the character jumping or falling?
	bool m_IsJumping;
	bool m_IsFalling;

	//which direction is the character moving in
	bool m_LeftPressed;
	bool m_RightPressed;

	//How long has this jump lasted so far
	float m_TimeThisJump;

	//Has the player just initiated a jump
	bool m_JustJumped = false;

private:
	//what is the gravity
	float m_Gravity;

	//How fast is the character
	float m_Speed = 400;

	//Where is the player
	Vector2f m_Position;

	//Where are the character's body parts
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	//characters texture
	Texture m_Texture;

public:
	void spawn(Vector2f startPosition, float gravity);

	//Pure virtual function
	bool virtual handleInput() = 0;

	//Where is the player
	FloatRect getPosition();

	//Rectangle representing position of different parts of sprite
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	Sprite getSprite();

	//make character stand
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	//where is the center of the character
	Vector2f getCenter();

	//We will call this function once every frame
	void update(float elapsedTime);
};