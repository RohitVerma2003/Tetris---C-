#include "grid.h"
#include <iostream>
#include "colors.h"
using namespace std;

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialze();
    colors = GetCellColors();
}

void Grid::Initialze()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::Print()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Grid ::Draw()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
        return false;
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
        return true;
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;

    for(int row = numRows - 1 ; row >= 0 ; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        }else if(completed > 0){
            MoveRowDown(row , completed);
        }
    }

    return completed;
}

bool Grid::IsRowFull(int row)
{
    for (int i = 0; i < numCols; i++)
    {
        if (grid[row][i] == 0)
            return false;
    }

    return true;
}

void Grid::ClearRow(int row)
{
    for (int i = 0; i < numCols; i++)
    {
        grid[row][i] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int i = 0; i < numCols; i++)
    {
        grid[row + numRows][i] = grid[row][i];
        grid[row][i] = 0;
    }
}
