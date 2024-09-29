#include "block.h"
#include <vector>
using namespace std;

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 3;
}

void Block::Draw()
{
    vector<Position>tiles = GetCellPositions();

    for (Position items : tiles)
    {
        DrawRectangle(items.column * cellSize + 1, items.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows , int columns){
    rowOffset += rows;
    columnOffset += columns;
}

vector<Position> Block::GetCellPositions(){
    vector<Position> tiles = cells[rotationState];
    vector<Position> movedTiles;

    for(Position items : tiles){
        Position newPos = Position(items.row + rowOffset , items.column + columnOffset);
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;

    if(rotationState == (int)cells.size()) rotationState = 0;
}

void Block::UndoRotate()
{
    rotationState--;

    if(rotationState < 0) rotationState = (int)cells.size() - 1;
}
