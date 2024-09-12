#include "Bricks.h"
#include "ball.h"
#include "game.h"

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	strength = 1;
	imageName = "images\\bricks\\NormalBrick.jpg";
}

void normalBrick::collisionAction()
{

}

hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	strength = 3;
	imageName = "images\\bricks\\HardBrick.jpg";
}

void hardBrick::collisionAction()
{
	//TODO: Add collision action logic
}

RockBrick::RockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)

{
	imageName = "images\\bricks\\RockBrick.jpg";
}

void RockBrick::collisionAction()
{
}

PwrUpBrick::PwrUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)

{
	imageName = "images\\bricks\\PowerUp.jpg";
}

void PwrUpBrick::collisionAction()
{
}

PwrDwnBrick::PwrDwnBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)

{
	imageName = "images\\bricks\\PowerDown.jpg";
}

void PwrDwnBrick::collisionAction()
{
}