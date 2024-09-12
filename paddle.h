#pragma once

#include "collidable.h"

class paddle : public drawable
{
public:
	paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void paddleMovement();
	void draw();
};