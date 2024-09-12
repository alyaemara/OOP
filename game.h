#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "paddle.h"
#include "ball.h"
#include "grid.h"

//Main class that coordinates the game operation
class game
{
	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	MODE gameMode;

	/// Add more members if needed

	int lives = 3;
	int GameTime = 0;
	int score = 0;
	bool Play = 0;
	bool GameStart = 0;
	
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	paddle* newPaddle;	
	paddle* Paddle_2;
	ball* NewBall;
	ball* Ball_2;
	grid* bricksGrid;

public:
	game();
	~game();

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window


	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go() const;

	window* getWind() const;		//returns a pointer to the graphics window

	void ChangeMode(int NewMode);

	grid* getGrid() const;

	void gameTime(time_t StratTime);

	void StartPlay();

	void GoPlayStart();

	//ball* getBall() const;

};

