#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	//Thomas contructor
	Thomas();

	//overridden input handler for Thomas
	bool virtual handleInput();
};