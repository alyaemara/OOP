#include "game.h"
#include <iostream>
#include <windows.h>
#include <ctime>
#include <thread>
#include "gameConfig.h"

using namespace std;
using namespace chrono;

game::game()
{
	//Initialize playgrond parameters
	gameMode = MODE_DSIGN;


	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	//gameToolbar = new toolbar(toolbarUpperleft, config.windWidth, config.toolBarHeight, this);

	gameToolbar = new toolbar(toolbarUpperleft,0,config.toolBarHeight, this);
	gameToolbar->draw();

	//3 - create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();
	
	//4- Create the Paddle
	//TODO: Add code to create and draw the paddle
	point paddlePlace;
	paddlePlace.x = config.windWidth/2 - 50;
	paddlePlace.y = config.windHeight-75;
	//newPaddle = new paddle(paddlePlace, 100, 23, this);
	Paddle_2 = new paddle(paddlePlace, 100, 23, this);
	Paddle_2->draw();

	//5- Create the ball
	//TODO: Add code to create and draw the ball
	point ballplace;
	ballplace.x = config.windWidth / 2 - 10;
	ballplace.y = config.windHeight - 95;
	Ball_2 = new ball(ballplace, 20, 20, this);
	//6- Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	//delete newPaddle;
	//delete NewBall;
	delete bricksGrid;
}


clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return bricksGrid;
}

void game::ChangeMode(int NewMode)
{
	if (NewMode == 0)
		gameMode = MODE_PLAY;
	else
		gameMode = MODE_DSIGN;
}

////////////////////////////////////////////////////////////////////////
void game::go() const
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");

	
	do
	{
		printMessage("Ready...");
		Ball_2->SetAngle(-45);
		//std:cout << "Ready";
		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			std::cout << "DesignMode";
			getMouseClick(x, y);	//Get the coordinates of the user click

			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}
		}
		else
		{
			time_t startTime = time(nullptr);
			int ITime = time(nullptr) - startTime;
			//NewBall->draw();
			while (!isExit || gameMode != MODE_PLAY) {
				//gameTime(startTime);
				pWind->GetMouseClick(x, y);
				if (x != -1) //Detect the mouse click
				{
					if (y >= 0 && y < config.toolBarHeight)
					{
						isExit = gameToolbar->handleClick(x, y);
					}
				}

				if (time(nullptr) - startTime != ITime) {
					std::string result = "Time: " + std::to_string(time(nullptr) - startTime) +
						", Score: " + std::to_string(score) +
						", Lives: " + std::to_string(lives);
					printMessage(result);
					ITime = time(nullptr) - startTime;
					int remainingBricks = bricksGrid->areAllBricksDestroyed();
					if (remainingBricks == 0)
					{
						printMessage("All bricks are destroyed!Game over. Final Score: " + std::to_string(score));
					}

				}
				//std::cout << "PlayMode";
				Paddle_2->paddleMovement();

				if (Play) 
				{
					if (GetAsyncKeyState(VK_SPACE) & 0x8000)
					{
						Ball_2->GoPlay();
					}

					if (GameStart)
					{
						Ball_2->ballMovement();
					}
				}
				Sleep(1);
			}
		}


	} while (!isExit);

}

	void game::gameTime(time_t StratTime)
	{
		time_t elapsedTime = time(nullptr) - StratTime;
		GameTime = int(elapsedTime);
	}

	void game::StartPlay() {
		Ball_2->draw();
		Play = true;
	}

	void game::GoPlayStart()
	{
		 GameStart = 1;
	}

//ball* game::getBall() const
//{
//	return Ball_2;
//}


