#pragma once

//This file contains all classes related to toolbar (toolbar icon classes & toolbar class itself)
#include "drawable.h"

////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
//Base class for all toolbar icons 
class toolbarIcon :public drawable
{
public:
	toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void onClick()=0;   //The action that should be taken when this icon is clicked
};

////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
class iconAddNormalBrick :public toolbarIcon
{
public:
	iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////

class iconAddHardBrick :public toolbarIcon
{
public:
	iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};


////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////

class iconAddRockBrick :public toolbarIcon
{
public:
	iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconAddPowerUpBrick   //////////////////////////////////////////////

class iconAddPwrUpBrick :public toolbarIcon
{
public:
	iconAddPwrUpBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconAddPowerDownBrick   //////////////////////////////////////////////

class iconAddPwrDwnBrick :public toolbarIcon
{
public:
	iconAddPwrDwnBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};


////////////////////////////////////////////////////  class iconDesignMode   //////////////////////////////////////////////
class iconDesignMode :public toolbarIcon
{

public:
	iconDesignMode(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconSave   //////////////////////////////////////////////
class iconSave :public toolbarIcon
{
public:
	iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconLoad   //////////////////////////////////////////////
class iconLoad :public toolbarIcon
{
public:
	iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconPlayMode   //////////////////////////////////////////////
class iconPlayMode :public toolbarIcon
{
public:
	iconPlayMode(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};


////////////////////////////////////////////////////  class iconPlay   //////////////////////////////////////////////
class iconPlay : public toolbarIcon
{
public:
	iconPlay(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};


////////////////////////////////////////////////////  class iconPause   //////////////////////////////////////////////
class iconPause : public toolbarIcon
{
public:

	iconPause(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};


////////////////////////////////////////////////////  class iconContinue   //////////////////////////////////////////////
class iconContinue : public toolbarIcon
{
public:
	iconContinue(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};


////////////////////////////////////////////////////  class iconStop   //////////////////////////////////////////////
class iconStop : public toolbarIcon
{
public:
	iconStop(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
class iconExit :public toolbarIcon
{
public:
	iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconDeleteBrick   //////////////////////////////////////////////

class iconDeleteBrick : public toolbarIcon

{

public:

	iconDeleteBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);

	virtual void onClick();

};

////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class toolbar:public drawable
{

	enum ICONS //The icons of the toolbar (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_ADD_NORM,		//add normal brick

		//TODO: Add more icons names here
		ICON_ADD_HARD,

		ICON_ADD_ROCK,

		ICON_ADD_PwrUp,

		ICON_ADD_PwrDwn,

		ICON_DESUGN_MODE,

		ICON_SAVE,

		ICON_LOAD,

		ICON_PLAY_MODE,  //Play mode icon

		ICON_PLAY,       //Play icon

		ICON_PAUSE,      //Pause icon

		ICON_CONTINUE,   //Continue icon

		ICON_STOP,       //Stop icon

		ICON_EXIT,		//Exit icon

		ICON_DELETE_BRICK,  //Delete brick icon

		ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

private:
    toolbarIcon** iconsList; //an array of toolbarIcon pointers
	string *iconsImages[ICON_COUNT];
	game* pGame;

public:
	toolbar(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~toolbar();
    void draw() const;
	bool handleClick(int x, int y);	//handles clicks on toolbar icons, returns true if exit is clicked
};

