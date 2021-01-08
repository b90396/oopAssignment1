#include "raylib.h"
#include "Game.h"
#include "RandomNumberGenerator.h"
#include <list>

void HandleCollisions(Game& game);

int main()
{
    InitWindow(900, 600, "OOP Assignment 1");
    SetTargetFPS(60);
    InitAudioDevice(); // Initialize audio device
    Music music = LoadMusicStream("resources/audio/thememusic.mp3");
    Music goMusic = LoadMusicStream("resources/audio/gameOver.mp3");
    Sound shot = LoadSound("resources/audio/laser.mp3");
    SetMusicVolume(music, 0.5f);
    music.loopCount = 0;
    PlayMusicStream(music);
    Game game;
    game.Setup();
    float enemyspeedincrement = 1;
    float timeDelayForEnemyMovement = 0;
    float timeDelayForPlayerProjectile = 0;
    float timeDelayForEnemyProjectile = 0;
    float timeDelayForEnemyShoot = 0;
    float playerShootCooldown = 0;
    int directionCounter = 0;
    bool pause = false;
    bool gameOver = false;
    bool resetgame = false;
    int randomNumber = 0;
    int volumeCount = 1;
    list <int> highScores;
    
    //Load images
    Texture2D texture = LoadTexture("resources/playerShip.png");
    Texture2D wall = LoadTexture("resources/brickwall2.png");
    Texture2D alien = LoadTexture("resources/alien2.png");
    Texture2D pProj = LoadTexture("resources/pBullet.png");
    Texture2D eProj = LoadTexture("resources/eBullet.png");
    Texture2D title = LoadTexture("resources/spaceInvadersTitle.png");
    Texture2D hScores = LoadTexture("resources/highScoresTable.png");
    Texture2D heart = LoadTexture("resources/heart.png");
    Texture2D emptyHeart = LoadTexture("resources/emptyHeart.png");

    int screenWidth = 800;
    int screenHeight = 800;
    title.width = 300;
    title.height = 168;
    hScores.width = 350;
    hScores.height =350;
    heart.height = 40;
    heart.width = 40;
    emptyHeart.height = 40;
    emptyHeart.width = 40;
    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(title, 610, 10, YELLOW);
        DrawText(FormatText("SCORE: %i", game.getScore()), 610, 180, 20, LIGHTGRAY);
        DrawText("LIVES: ", 610,230, 20, LIGHTGRAY);
        DrawTexture(hScores, 575, 250,WHITE);
        DrawText("PAUSE(P) MUTE(M)  EXIT(ESC)", 604, 570, 19, LIGHTGRAY);
        if (highScores.size() != 0)
        {
            DrawText("HIGHSCORE: %i" + highScores.front(), 610, 550, 20, LIGHTGRAY);

        }

        

        if (game.IsRunning() && !pause && !gameOver)
        {
            if (game.player.getLives() == 3){
                DrawTexture(heart, 680, 220, RED);
                DrawTexture(heart, 720, 220, RED);
                DrawTexture(heart, 760, 220, RED);
            }
            if (game.player.getLives() == 2) {
                DrawTexture(heart, 680, 220, RED);
                DrawTexture(heart, 720, 220, RED);
                DrawTexture(emptyHeart, 760, 220, RED);
            }
            if (game.player.getLives() == 1) {
                DrawTexture(heart, 680, 220, RED);
                DrawTexture(emptyHeart, 720, 220, RED);
                DrawTexture(emptyHeart, 760, 220, RED);
            }
           
            if (IsKeyPressed(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT);
            if (IsKeyPressed(KEY_LEFT))   game.ProcessInput(KEY_LEFT);

            if (IsKeyPressed(KEY_SPACE) && playerShootCooldown >= 0.5)
            {
                PlaySound(shot);
                game.ProcessInput(KEY_SPACE);
                playerShootCooldown = 0;
            }
            //if (IsKeyPressed(KEY_UP))     game.ProcessInput(KEY_UP);
            //if (IsKeyPressed(KEY_DOWN))   game.ProcessInput(KEY_DOWN);

            if (IsKeyPressed(KEY_P))
            {
                pause = true;
            }
            if (IsKeyPressed(KEY_M))
            {
                 volumeCount ++;
                 if (volumeCount % 2 == 0) 
                 {
                    SetMusicVolume(music, 0.0f);
                    SetMusicVolume(goMusic, 0.0f);
                 }
                 else 
                 {
                    SetMusicVolume(music, 1.0f);
                    SetMusicVolume(goMusic, 1.0f);
                 }
            }
            HandleCollisions(game);

            timeDelayForEnemyMovement += GetFrameTime();
            if (timeDelayForEnemyMovement - game.enemyspeed >= 0)
            {
                
                for (int i = 0; i < game.enemies.size(); i++)
                {
                    if (directionCounter < 3)
                    {
                        game.enemies[i].move('R');
                    }
                    
                    if (directionCounter >= 3 && directionCounter < 6)
                    {
                        game.enemies[i].move('L');
                    }
                    
                    if (directionCounter == 6)
                    {
                        game.enemies[i].move('D');
                    }

                    //FIX STARTING POSITION AND THEN NUMBER AFTERWARDS SO ENEMIES START AT FAR LEFT OF THE GRID
                }
                if (directionCounter == 6)
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
            playerShootCooldown += GetFrameTime();

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

            if (game.IsPlayerDead() == true || game.EnemiesAtEnd() == true) 
            {
                gameOver = true;
            }
            if (game.enemies.empty() == true)
            {
                game.BuildEnvironment();
            }
        }
        else if(gameOver)
        {
             DrawText("GAME OVER", 610, 10, 20, LIGHTGRAY);
             StopMusicStream(music);
             SetMusicVolume(goMusic, 2.0f);
             PlayMusicStream(goMusic);
             UpdateMusicStream(goMusic);
             
             DrawTexture(emptyHeart, 680, 220, RED);
             DrawTexture(emptyHeart, 720, 220, RED);
             DrawTexture(emptyHeart, 760, 220, RED);
        
              if (IsKeyPressed(KEY_ENTER))    //RESETS WHEN ENTER IS PRESSED
              {
                    gameOver = false;
                     //PauseMusicStream(goMusic);
                     PlayMusicStream(music);
                     UpdateMusicStream(music);
                     game = Game();
                     game.Setup();

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
                 texture.height = 30;
                 texture.width = 30;
                 wall.height = 30;
                 wall.width = 30;
                 alien.height = 30;
                 alien.width = 30;
                 pProj.height = 30;
                 pProj.width = 30;
                 eProj.height = 30;
                 eProj.width = 30;
                switch (grid[y][x])
                {
                    case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK); break;
                    case WALL: DrawTexture(wall, xPosition, yPosition, WHITE);    break; // DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY); break;
                    case PLAYER: DrawTexture(texture, xPosition, yPosition, WHITE);    break;
                    case ENEMY:  DrawTexture(alien, xPosition, yPosition, WHITE);    break;      break;
                    case PLAYERPROJECTILE: DrawTexture(pProj, xPosition, yPosition, WHITE);  break;
                    case ENEMYPROJECTILE: DrawTexture(eProj, xPosition, yPosition, WHITE);  break;
                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                }

                // draw lines around each tile, remove this if you don't like it!
               // DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void HandleCollisions(Game& game)
{
    game.HandlePlayerProjectileToEnemyCollisions();
    game.HandlePlayerProjectileToWallCollisions();
    game.HandleEnemyMovementToWallCollisions();
    game.HandleProjectileToProjectileCollisions();
    game.HandleEnemyProjectileToPlayerCollisions();
    game.HandleEnemyProjectileToWallCollisions();
}