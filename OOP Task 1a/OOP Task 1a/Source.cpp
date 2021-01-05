#include "raylib.h"
#include "Game.h"
#include "RandomNumberGenerator.h"
int main()
{
    InitWindow(900, 600, "OOP Assignment 1");
    SetTargetFPS(60);

    Game game;
    game.Setup();
    float timeDelayForEnemyMovement = 0;
    float timeDelayForPlayerProjectile = 0;
    float timeDelayForEnemyProjectile = 0;
    float timeDelayForEnemyShoot = 0;
    int directionCounter = 0;
    bool pause = false;
    int randomNumber = 0;
    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        DrawText(FormatText("SCORE: %i", game.getScore()), 610, 30, 20, LIGHTGRAY);
        DrawText(FormatText("LIVES: %i", game.getLives()), 610, 50, 20, LIGHTGRAY);
        

        if (game.IsRunning() && !pause)
        {
            if (IsKeyPressed(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT);
            if (IsKeyPressed(KEY_LEFT))   game.ProcessInput(KEY_LEFT);
            if (IsKeyPressed(KEY_SPACE)) game.ProcessInput(KEY_SPACE);
            //if (IsKeyPressed(KEY_UP))     game.ProcessInput(KEY_UP);
            //if (IsKeyPressed(KEY_DOWN))   game.ProcessInput(KEY_DOWN);

            if (IsKeyPressed(KEY_P))
            {
                pause = true;
            }
          
            game.HandlePlayerToEnemyCollisions();
            game.HandlePlayerToWallCollisions();
            game.HandleEnemyToWallCollisions();
            game.HandleEnemyToPlayerCollisions();
            

            timeDelayForEnemyMovement += GetFrameTime();
            if (timeDelayForEnemyMovement - 1 >= 0)
            {
                
                for (int i = 0; i < game.enemies.size(); i++)
                {
                    if (directionCounter < 9)
                    {
                        game.enemies[i].move('R');
                    }
                    
                    if (directionCounter >= 9 && directionCounter < 18)
                    {
                        game.enemies[i].move('L');
                    }
                    
                    if (directionCounter == 18)
                    {
                        game.enemies[i].move('D');
                        
                    }

                    
                    //FIX STARTING POSITION AND THEN NUMBER AFTERWARDS SO ENEMIES START AT FAR LEFT OF THE GRID

                    
                }
                if (directionCounter == 18)
                {
                    directionCounter = 0;

                }
                else
                {
                    directionCounter++;
                }
                
                
                timeDelayForEnemyMovement = 0;
            }

            timeDelayForEnemyMovement += GetFrameTime();
            timeDelayForEnemyShoot += GetFrameTime();

            if(timeDelayForEnemyShoot-1>=0)
            {
                randomNumber = GetRandomValue(0, game.enemies.size());

                for (int i = 0; i < game.enemies.size(); i++)
                {
                    if (randomNumber == i)
                    {
                        game.enemies[i].Shoot(game.enemyprojectiles);
                    }
                }
                timeDelayForEnemyShoot = 0;
            }
            timeDelayForEnemyProjectile += GetFrameTime();

            if (timeDelayForEnemyProjectile - 0.1 >= 0)
            {
                for (int i = 0; i < game.enemyprojectiles.size(); i++)
                {
                    game.enemyprojectiles[i].move();
                }
                timeDelayForEnemyProjectile = 0;
            }

            timeDelayForPlayerProjectile += GetFrameTime();
            if (timeDelayForPlayerProjectile - 0.05 >= 0)
            {
                for (int i = 0; i < game.playerprojectiles.size(); i++)
                {
                    game.playerprojectiles[i].movePlayerProjectile();
                }
                timeDelayForPlayerProjectile = 0;
            }
        }
        else
        {
            DrawText("PAUSED", 610, 10, 20, LIGHTGRAY);

            if (IsKeyPressed(KEY_P))
            {
                pause = false;
            }

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
                    case ENEMYPROJECTILE: DrawRectangle(xPosition, yPosition, cellSize, cellSize, PINK); break;
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