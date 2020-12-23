#include "raylib.h"
#include "Game.h"

int main()
{
    InitWindow(900, 600, "OOP Assignment 1");
    SetTargetFPS(60);

    Game game;
    game.Setup();
    float timeDelayForEnemyMovement = 0;
    int directionCounter = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        if (game.IsRunning())
        {
            if (IsKeyPressed(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT);
            if (IsKeyPressed(KEY_LEFT))   game.ProcessInput(KEY_LEFT);
            //if (IsKeyPressed(KEY_UP))     game.ProcessInput(KEY_UP);
            //if (IsKeyPressed(KEY_DOWN))   game.ProcessInput(KEY_DOWN);

            timeDelayForEnemyMovement += GetFrameTime();
            if (timeDelayForEnemyMovement - 1 >= 0)
            {
                for (int i = 0; i < game.enemies.size(); i++)
                {
                    if (directionCounter < 8)
                    {
                        game.enemies[i].move('R');
                    }
                    
                    if (directionCounter >= 8 && directionCounter < 17)
                    {
                        game.enemies[i].move('L');
                    }
                    
                    if (directionCounter == 17)
                    {
                        game.enemies[i].move('D');
                        
                    }

                    
                    //FIX STARTING POSITION AND THEN NUMBER AFTERWARDS SO ENEMIES START AT FAR LEFT OF THE GRID
                    
                }
                if (directionCounter == 17)
                {
                    directionCounter = 0;

                }
                else
                {
                    directionCounter++;
                }
                
                
                timeDelayForEnemyMovement = 0;
            }
        }
        else
        {
            DrawText("TODO: Why did the game end?", 610, 10, 20, LIGHTGRAY);
        }

        const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

        const auto grid = game.PrepareGrid();

        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE; y++)
            {
                int xPosition = x * cellSize;
                int yPosition = y * cellSize;

                switch (grid[y][x])
                {
                    case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN); break;
                    case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY); break;
                    case PLAYER: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
                    case ENEMY:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);       break;
                    case PLAYERPROJECTILE: DrawRectangle(xPosition, yPosition, cellSize, cellSize, WHITE); break;
                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                }

                // draw lines around each tile, remove this if you don't like it!
                DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}