#include "ball.h"
#include <cmath>
#include "game.h"
#include "gameConfig.h"
#include <iostream>

ball::ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\ball.jpg";
}

void ball::ballMovement()
{
	window* pWind = pGame->getWind();
	if (config.toolBarHeight+10 >= uprLft.y || uprLft.y >= (config.windHeight - config.statusBarHeight - 10) || uprLft.x >= config.windWidth-10 || uprLft.x <= 10) {
		SetAngle((BallAngle)*180.0/3.141 + 90);
		pWind->SetPen(config.bkGrndColor, 1);
		pWind->SetBrush(config.bkGrndColor);
		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + 20, uprLft.y + 20, FILLED);
		uprLft.y -= int(cos(BallAngle) / 0.2);
		uprLft.x -= int(sin(BallAngle) / 0.2);
		pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
		cout << "Wall_Collision" <<endl;
	}
	else if (collisionDetection())
	{

		collisionAction();
		/*
		SetAngle((BallAngle) * 180.0 / 3.141 + 90);
		pWind->SetPen(config.bkGrndColor, 1);
		pWind->SetBrush(config.bkGrndColor);
		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + 20, uprLft.y + 20, FILLED);
		uprLft.y -= int(cos(BallAngle) / 0.2);
		uprLft.x -= int(sin(BallAngle) / 0.2);
		pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
		*/
	}
	else{
		//window* pWind = pGame->getWind();
		pWind->SetPen(config.bkGrndColor, 1);
		pWind->SetBrush(config.bkGrndColor);
		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + 20, uprLft.y + 20, FILLED);
		uprLft.y -= int(cos(BallAngle)/0.2);
		uprLft.x -= int(sin(BallAngle)/0.2);
		pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
	}

}

void ball::draw() 
{
	//draw image of this object
	window* pWind = pGame->getWind();
	pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
}


void ball::GoPlay()
{
	pGame->GoPlayStart();
}

void ball::collisionAction() 
{
	cout << "Bricks_Collision" << endl;


	window* pWind = pGame->getWind();
	SetAngle((BallAngle) * 180.0 / 3.141 + 90);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + 20, uprLft.y + 20, FILLED);
	uprLft.y -= int(cos(BallAngle) / 0.2);
	uprLft.x -= int(sin(BallAngle) / 0.2);
	pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);

}

void ball::SetAngle(float angleInDegrees)
{
	BallAngle = angleInDegrees * (3.141 / 180.0);
}

//bool ball::collisionDetection(int brickX, int brickY, int brickWidth, int brickHeight)
//{
//	// Check if the ball's bounding box intersects with the brick's bounding box
//	if (uprLft.x < brickX + brickWidth &&
//		uprLft.x + width > brickX &&
//		uprLft.y < brickY + brickHeight &&
//		uprLft.y + height > brickY)
//	{
//		return true;  // Collision detected
//	}
//
//	return false;  // No collision
//}


bool ball::collisionDetection()
{
	window* pWind = pGame->getWind();
	color holder = pWind->GetColor(uprLft.x+5, uprLft.y-5);
	if (holder.ucBlue != config.bkGrndColor.ucGreen && holder.ucGreen != config.bkGrndColor.ucBlue && holder.ucRed != config.bkGrndColor.ucRed)
	{
		return true; 
	}
	/*
	holder = pWind->GetColor(uprLft.x - 5, uprLft.y);
	if (holder.ucBlue != config.bkGrndColor.ucGreen && holder.ucGreen != config.bkGrndColor.ucBlue && holder.ucRed != config.bkGrndColor.ucRed)
		return true;
	*/
	return false;

}

//void ball::ballMovement()
//{
//	window* pWind = pGame->getWind();
//	if (config.toolBarHeight + 10 >= uprLft.y || uprLft.y >= (config.windHeight - config.statusBarHeight - 10) || uprLft.x >= config.windWidth - 10 || uprLft.x <= 10) {
//		SetAngle((BallAngle) * 180.0 / 3.141 + 90);
//		pWind->SetPen(config.bkGrndColor, 1);
//		pWind->SetBrush(config.bkGrndColor);
//		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + 20, uprLft.y + 20, FILLED);
//		uprLft.y -= int(cos(BallAngle) / 0.2);
//		uprLft.x -= int(sin(BallAngle) / 0.2);
//		pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
//		cout << "Wall_Collision" << endl;
//	}
//	else if (collisionDetection())
//	{
//		collisionAction();
//	}
//	else {
//		pWind->SetPen(config.bkGrndColor, 1);
//		pWind->SetBrush(config.bkGrndColor);
//		pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + 20, uprLft.y + 20, FILLED);
//		uprLft.y -= int(cos(BallAngle) / 0.2);
//		uprLft.x -= int(sin(BallAngle) / 0.2);
//		pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
//	}
//}
//
//bool ball::checkBrickCollision(brick* pBrick)
//{
//
//	if (uprLft.x + width >= pBrick->getUprLft().x &&
//		uprLft.x <= pBrick->getUprLft().x + pBrick->getWidth() &&
//		uprLft.y + height >= pBrick->getUprLft().y &&
//		uprLft.y <= pBrick->getUprLft().y + pBrick->getHeight())
//	{
//		pBrick->collisionAction();
//		return true;
//	}
//
//	return false;
//}

//void ball::collisionAction()
//{
//	pGame->printMessage("Collision of collectable and ball");
//	if (isFireball())
//	{
//		//pGame->destroyRockBrick(uprLft);
//	}
//}
//void ball::setFireball(bool isFire)
//{
//	FireballState= isFire;
//}
//bool ball::isFireball()
//{
//	return isFireball;
//}
