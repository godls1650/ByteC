#pragma once
#include "Character.h"
#include "Playable.h"
class Magician : public Character , Playable {

	Magician(const char* nickname = "(NULL)",
		int hp = 0, int mp = 0) :Character(nickname, hp, mp),
	Playable(4,10,3,8,3,5){};

};

