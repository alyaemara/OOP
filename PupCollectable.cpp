//#include "PupCollectable.h"
//#include "game.h"
//#include"ball.h"
//
//PupCollectable::PupCollectable(point r_uprLft, int r_width, int r_height, game* r_pGame) : collidable(r_uprLft,r_width,r_height,r_pGame)
//{
//	imageName = "images\\PupCollectable.jpg";
//}
//void PupCollectable::collisionAction()
//{
//	pGame->printMessage("Power-up Collectable collided! Ball is now a fireball.");
//	ball* pBall = pGame->getBall();
//	if (pBall)
//	{
//		pBall->setFireball(true);
//	}
//}
//void PupCollectable::draw()
//{
//	window* pWind = pGame->getWind();
//	pWind->DrawImage(imageName, uprLft.x, uprLft.y, width, height);
//}
