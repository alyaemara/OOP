#include "grid.h"
#include "game.h"
#include "gameConfig.h"

grid::grid(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{

	rows = height / config.brickHeight;
	cols = width / config.brickWidth;

	brickMatrix = new brick * *[rows];
	for (int i = 0; i < rows; i++)
		brickMatrix[i] = new brick * [cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			brickMatrix[i][j] = nullptr;
}

grid::~grid()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				delete brickMatrix[i][j];	//delete all allocated bricks

	for (int i = 0; i < rows; i++)
		delete brickMatrix[i];

	delete brickMatrix;

}

void grid::draw() const
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(config.gridLinesColor, 1);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y + rows * config.brickHeight);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw();	//draw exisiting bricks


}

int grid::addBrick(BrickType brkType, point clickedPoint)
{
	//TODO:
	// 1- Check that the clickedPoint is within grid range (and return -1)
	// 2- Check that the clickedPoint doesnot overlap with an exisiting brick (return 0)

	//Here we assume that the above checks are passed

	//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y + gridCellRowIndex * config.brickHeight;

	switch (brkType)
	{
	case BRK_NRM:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_HRD:	//The new brick to add is Hard Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_ROCK:	//The new brick to add is Hard Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new RockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_PwrUp:	//The new brick to add is Hard Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new PwrUpBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_PwrDwn:	//The new brick to add is Hard Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new PwrDwnBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
		//TODO: 
		// handle more types
	}
	return 1;
}


void grid::deleteBrick(point clickedPoint)

{

	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;

	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	if (gridCellRowIndex >= 0 && gridCellRowIndex < rows && gridCellColIndex >= 0 && gridCellColIndex < cols)

	{

		if (brickMatrix[gridCellRowIndex][gridCellColIndex])

		{

			pGame->getWind()->SetBrush(config.bkGrndColor);

			pGame->getWind()->SetPen(WHITE, 1);

			int borderWidth = 1;

			pGame->getWind()->DrawRectangle(gridCellColIndex * config.brickWidth - borderWidth, uprLft.y + gridCellRowIndex * config.brickHeight - borderWidth, (gridCellColIndex + 1) * config.brickWidth + borderWidth, uprLft.y + (gridCellRowIndex + 1) * config.brickHeight + borderWidth);

			delete brickMatrix[gridCellRowIndex][gridCellColIndex];

			brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;

		}

	}

}

bool grid::areAllBricksDestroyed()
{
	int remainingBricks = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j] != nullptr)
				remainingBricks++;
	return remainingBricks;
}