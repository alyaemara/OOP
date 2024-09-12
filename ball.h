#pragma once

#include "collidable.h"

class ball : public collidable
{
	float BallAngle = 0;
public:
	ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	void draw();
	void GoPlay();
	void ballMovement();
	void SetAngle(float angleInDegrees);
	bool collisionDetection();
	//bool checkBrickCollision(brick* pBrick);
	//point GetUprLft() const;

	//bool collisionDetection(int brickX, int brickY, int brickWidth, int brickHeight);
	//void SetFireball(bool isFire);
	//bool isFireball();
};
