#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"

enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_HRD,		//Hard Brick
	BRK_ROCK,
	BRK_PwrUp,
	BRK_PwrDwn
	//TODO: Add more types
};

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
protected:
	int strength;
public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	//virtual void collisionAction() = 0;
	//int getWidth() const;
	//int getHeight() const;
	//point getUprLft() const;

};


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};

////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class hardBrick :public brick
{

public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};

class RockBrick :public brick
{

public:
	RockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};

//////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class PwrUpBrick :public brick
{

public:
	PwrUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};

//////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class PwrDwnBrick :public brick
{

public:
	PwrDwnBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};