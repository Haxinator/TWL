#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	//bob constructor
	Bob();

	//overridden virtual function
	bool virtual handleInput();
};