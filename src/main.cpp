#include "raylib.h"
#include "game.h"

double lastUpdatedTime = 0;

bool EventTriggered(double interval){
    double currentTime = GetTime();

    if(currentTime - lastUpdatedTime >= interval){
        lastUpdatedTime = currentTime;
        return true;
    }

    return false;
}

int main(void)
{
    InitWindow(300, 600, "Tetris"); // This will initialize the window
    SetTargetFPS(60);               // This will set how fast the game should run
    Color DarkBlue = {44, 44, 127, 255};

    Game game = Game();

    while (!WindowShouldClose()) // WindowShouldClose function used to check whether the program stops or not
    { 
        game.HandleInput();

        if(EventTriggered(0.5)) game.MoveBlockDown();

        BeginDrawing(); // This function used to start the drawing
        ClearBackground(DarkBlue);
        game.Draw();
        EndDrawing(); // This function used to end the drawing
    }

    CloseWindow();
}