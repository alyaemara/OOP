#include "drawable.h"
#include "gameConfig.h"
#include "game.h"

drawable::drawable(point r_uprlft, int r_width, int r_height, game* r_pGame)
{
	uprLft.x = r_uprlft.x;
	uprLft.y = r_uprlft.y;
	width = r_width;
	height = r_height;
	pGame = r_pGame;
}

void drawable::draw() const
{
	//draw image of this object
	window* pWind = pGame->getWind();
	pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
}

void drawable::DrawWRemove(int x, int y) 
{
	//draw image of this object
	window* pWind = pGame->getWind();
	//pWind->DrawRegta(imageName, uprLft.x, uprLft.y, width, height);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	if(x<0)
		pWind->DrawRectangle(uprLft.x - x + 95, uprLft.y - y, uprLft.x + 110, uprLft.y + 25, FILLED);
	else
		pWind->DrawRectangle(uprLft.x - x , uprLft.y - y, uprLft.x + 20, uprLft.y + 25, FILLED);
	uprLft.x = uprLft.x + x;
	uprLft.y = uprLft.y + y;
	pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
}

void drawable::setImageName(string path)
{
	imageName = path;
}





