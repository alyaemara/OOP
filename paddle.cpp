#include "paddle.h"
#include "game.h"
#include "gameConfig.h"
#include <iostream>


paddle::paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\paddle.jpg";
}


void paddle::paddleMovement()
{

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		int x = 3; int y = 0;
		std::cout << "moveRight";
		//draw image of this object
		window* pWind = pGame->getWind();
		//pWind->DrawRegta(imageName, uprLft.x, uprLft.y, width, height);
		pWind->SetPen(config.bkGrndColor, 1);
		pWind->SetBrush(config.bkGrndColor);
		if (x < 0)
			pWind->DrawRectangle(uprLft.x - x + 95, uprLft.y - y, uprLft.x + 110, uprLft.y + 25, FILLED);
		else
			pWind->DrawRectangle(uprLft.x - x, uprLft.y - y, uprLft.x + 20, uprLft.y + 25, FILLED);
		uprLft.x = uprLft.x + x;
		uprLft.y = uprLft.y + y;
		pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		int x = -3; int y = 0;
		std::cout << "moveLeft";
		//draw image of this object
		window* pWind = pGame->getWind();
		//pWind->DrawRegta(imageName, uprLft.x, uprLft.y, width, height);
		pWind->SetPen(config.bkGrndColor, 1);
		pWind->SetBrush(config.bkGrndColor);
		if (x < 0)
			pWind->DrawRectangle(uprLft.x - x + 95, uprLft.y - y, uprLft.x + 110, uprLft.y + 25, FILLED);
		else
			pWind->DrawRectangle(uprLft.x - x, uprLft.y - y, uprLft.x + 20, uprLft.y + 25, FILLED);
		uprLft.x = uprLft.x + x;
		uprLft.y = uprLft.y + y;
		pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
	}
}


void paddle::draw()
{
	window* pWind = pGame->getWind();
	pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
}
