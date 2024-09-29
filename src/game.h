#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>
using namespace std;

class Game
{
public:
    Game();
    Grid grid;
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    void Draw();
    bool gameOver;

private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};