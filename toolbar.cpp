#include "toolbar.h"
#include "game.h"
#include "grid.h"
#include "gameConfig.h"
#include<fstream>

////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
toolbarIcon::toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{}




////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
iconAddNormalBrick::iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddNormalBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Normal Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_NRM, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

iconAddHardBrick::iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddHardBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Hard Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_HRD, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////

iconAddRockBrick::iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

void iconAddRockBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Rock Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_ROCK, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddPowerUpBrick   //////////////////////////////////////////////

iconAddPwrUpBrick::iconAddPwrUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

void iconAddPwrUpBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add PowerUp Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_PwrUp, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}


////////////////////////////////////////////////////  class iconAddPwrDwnBrick   //////////////////////////////////////////////

iconAddPwrDwnBrick::iconAddPwrDwnBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

void iconAddPwrDwnBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add PowerDown Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_PwrDwn, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconDesignMode   //////////////////////////////////////////////

iconDesignMode::iconDesignMode(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
}


void iconDesignMode::onClick()
{
	pGame->printMessage("Design Mode On");
	pGame->ChangeMode(1);
	/*
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		pGame->clearStatusBar();
	}
	pGame->printMessage("");
	*/
}



iconSave::iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}


void iconSave::onClick()
{

	//int rows = height / config.brickHeight;
	//int cols = width / config.brickWidth;

	//brickMatrix = new brick * *[rows];
	//for (int i = 0; i < rows; i++)
	//	brickMatrix[i] = new brick * [cols];

	//for (int i = 0; i < rows; i++)
	//	for (int j = 0; j < cols; j++)
	//		brickMatrix[i][j] = nullptr;

	//// Open a file for writing
	//ofstream outFile("saved_game.txt");

	//// Check if the file is successfully opened
	//if (!outFile.is_open())
	//{
	//	pGame->printMessage("Error: Could not open file for saving.");
	//	return;
	//}
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		if (brickMatrix[i][j] != nullptr)
	//			outFile << i << " " << j << endl;
	//	}
	//}


}

////////////////////////////////////////////////////  class iconLoad   //////////////////////////////////////////////
iconLoad::iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconLoad::onClick()
{
	//TO DO: add code for loading from file here
}

/////////////////////////////////////////////////////  class iconPlayMode   //////////////////////////////////////////////
iconPlayMode::iconPlayMode(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
}



void iconPlayMode::onClick()
{
	pGame->printMessage("Switching to Play Mode");
	pGame->ChangeMode(0);
}


////////////////////////////////////////////////////  class iconPlay   //////////////////////////////////////////////
iconPlay::iconPlay(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}



void iconPlay::onClick()
{
	//pGame->printMessage("Playing the game");
	pGame->StartPlay();

}


////////////////////////////////////////////////////  class iconPause   //////////////////////////////////////////////
iconPause::iconPause(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)

{}



void iconPause::onClick()
{
	pGame->printMessage("Pausing the game");
}


////////////////////////////////////////////////////  class iconContinue   //////////////////////////////////////////////
iconContinue::iconContinue(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}



void iconContinue::onClick()
{
	pGame->printMessage("Continuing the game");
}


////////////////////////////////////////////////////  class iconStop   //////////////////////////////////////////////
iconStop::iconStop(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}



void iconStop::onClick()
{
	pGame->printMessage("Stopping the game");
}

////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
iconExit::iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconExit::onClick()
{
	//TO DO: add code for cleanup and game exit here
}


////////////////////////////////////////////////////  class iconDeleteBrick   //////////////////////////////////////////////

iconDeleteBrick::iconDeleteBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :

	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)

{}



void iconDeleteBrick::onClick()

{

	pGame->printMessage("Click on a brick to delete it ==> Right-Click to stop <==");

	int x, y;

	clicktype t = pGame->getMouseClick(x, y);

	while (t == LEFT_CLICK)

	{

		point clicked;

		clicked.x = x;

		clicked.y = y;

		grid* pGrid = pGame->getGrid();

		pGrid->deleteBrick(clicked);

		t = pGame->getMouseClick(x, y);

	}

	pGame->printMessage(" ");

}


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{

	height = hght;
	pGame = pG;

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_ADD_NORM] = new string("images\\ToolbarIcons\\NormalBrickIcon.jpg");
	iconsImages[ICON_ADD_HARD] = new string("images\\ToolbarIcons\\HardBrickIcon.jpg");
	iconsImages[ICON_ADD_ROCK] = new string("images\\ToolbarIcons\\RockBrick.jpg");
	iconsImages[ICON_ADD_PwrUp] = new string("images\\ToolbarIcons\\PowerUp.jpg");
	iconsImages[ICON_ADD_PwrDwn] = new string("images\\ToolbarIcons\\PowerDown.jpg");
	iconsImages[ICON_DESUGN_MODE] = new string("images\\ToolbarIcons\\DesignModeIcon.jpg");
	iconsImages[ICON_SAVE] = new string("images\\ToolbarIcons\\SaveIcon.jpg");
	iconsImages[ICON_LOAD] = new string("images\\ToolbarIcons\\IconLoad.jpg");
	iconsImages[ICON_PLAY_MODE] = new string("images\\ToolbarIcons\\PlayModeIcon.jpg");
	iconsImages[ICON_PLAY] = new string("images\\ToolbarIcons\\PlayIcon.jpg");
	iconsImages[ICON_PAUSE] = new string("images\\ToolbarIcons\\PauseIcon.jpg");
	iconsImages[ICON_CONTINUE] = new string("images\\ToolbarIcons\\ContinueIcon.jpg");
	iconsImages[ICON_STOP] = new string("images\\ToolbarIcons\\StopIcon.jpg");
	iconsImages[ICON_EXIT] = new string("images\\ToolbarIcons\\ExitIcon.jpg");
	iconsImages[ICON_DELETE_BRICK] = new string("images\\ToolbarIcons\\DeleteIcon.jpg");

	point p;
	p.x = 0;
	p.y = 0;

	iconsList = new toolbarIcon * [ICON_COUNT];

	//For each icon in the tool bar
	//	1- Create an object setting its upper left corner, width and height
	iconsList[ICON_ADD_NORM] = new iconAddNormalBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_HARD] = new iconAddHardBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	p.x += 1;
	iconsList[ICON_ADD_ROCK] = new iconAddRockBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_PwrUp] = new iconAddPwrUpBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_PwrDwn] = new iconAddPwrDwnBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_DESUGN_MODE] = new iconDesignMode(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_SAVE] = new iconSave(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_LOAD] = new iconLoad(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_PLAY_MODE] = new iconPlayMode(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_PLAY] = new iconPlay(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_PAUSE] = new iconPause(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_CONTINUE] = new iconContinue(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_STOP] = new iconStop(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_EXIT] = new iconExit(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_DELETE_BRICK] = new iconDeleteBrick(p, config.iconWidth, height, pGame);

	//	2-Set its image (from the above images list)
	for (int i = 0; i < ICON_COUNT; i++)
	{
		iconsList[i]->setImageName(iconsImages[i]->c_str());

	}
}

toolbar::~toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, height, pWind->GetWidth(), height);

}

//handles clicks on toolbar icons, returns true if exit is clicked
bool toolbar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;


	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;

	return false;


}