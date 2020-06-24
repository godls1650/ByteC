#pragma once
#include "MiddleCls.h"
#include "MiddleClsTwo.h"
// class FinalCls extends MiddleCls implements optionable
// class Monster extends Character implements NonPlayer, Playable
// interface


class FinalCls : public MiddleCls , MiddleClsTwo {
	void result() {
		MiddleCls::function();
		MiddleClsTwo::function();
	
	}

};

