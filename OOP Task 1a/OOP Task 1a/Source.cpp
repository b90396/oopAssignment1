#include "raylib.h"
#include "Game.h"
#include "RandomNumberGenerator.h"
#include <list>

void HandleCollisions(Game& game);

int main()
{
    InitWindow(900, 600, "Space Race");
    SetTargetFPS(60);
    InitAudioDevice(); // Initialize audio device
    Music music = LoadMusicStream("resources/audio/thememusic1.mp3");
    Music goMusic = LoadMusicStream("resources/audio/gameOver1.mp3");
    Sound shot = LoadSound("resources/audio/laser.mp3");
    SetMusicVolume(music, 0.5f);
    music.loopCount = 0;
    PlayMusicStream(music);
    Game game;
    game.Setup();
    float timeDelayForEnemyMovement = 0;
    float timeDelayForPlayerProjectile = 0;
    float timeDelayForEnemyProjectile = 0;
    float timeDelayForEnemyShoot = 0;
    float playerShootCooldown = 0;
    char enemyDirection = 'R';
    bool movedDown = true;
    bool pause = false;
    bool gameOver = false;
    bool resetgame = false;
    int randomNumber = 0;
    int volumeCount = 1;
    list <int> highScores;
    
    //Load images
    Texture2D texture = LoadTexture("resources/playerShip.png");
    Texture2D wall = LoadTexture("resources/bwAnimate.png");
    Texture2D alien = LoadTexture("resources/alienAnimation.png");
    Texture2D eProj = LoadTexture("resources/lbaV2.png");
    Texture2D pProj = LoadTexture("resources/rAnimate.png");
    Texture2D title = LoadTexture("resources/spaceInvadersTitlee.png");
    Texture2D hScores = LoadTexture("resources/highScoresTable.png");
    Texture2D heart = LoadTexture("resources/heart.png");
    Texture2D emptyHeart = LoadTexture("resources/emptyHeart.png");
    
    
    int screenWidth = 800;
    int screenHeight = 800;
    title.width = 300;
    title.height = 150;
    hScores.width = 350;
    hScores.height = 350;
    heart.height = 40;
    heart.width = 40;
    emptyHeart.height = 40;
    emptyHeart.width = 40;
    texture.height = 30;
    texture.width = 30;
    wall.height = 30;
    wall.width = 120;
    alien.height = 30;
    alien.width = 90;
    pProj.height = 30;
    pProj.width = 60;
    eProj.height = 30;
    eProj.width = 60;
    
    
    
    float alienFrameWidth = (float)(alien.width / 3);
    int maxAlienFrames = (int)(alien.width / (int)alienFrameWidth);

    float eProjFrameWidth = (float)(eProj.width / 2);
    int maxEpFrames = (int)(eProj.width / (int)eProjFrameWidth);

    float wallFrameWidth = (float)(wall.width / 4);
    int maxWallFrames = (int)(wall.width / (int)wallFrameWidth);

    float rFrameWidth = (float)(pProj.width / 2);
    int maxRFrames = (int)(pProj.width / (int)rFrameWidth);

    float timer = 0.0f;
    int Aframe = 0;
    int Wframe = 0;
    int EPframe = 0;
    int PPframe = 0;
    
    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(title, 595, 20, YELLOW);
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
                    SetSoundVolume(shot, 0.0f);
                 }
                 else 
                 {
                    SetMusicVolume(music, 0.5f);
                    SetSoundVolume(shot, 1.0f);
                 }
            }
            HandleCollisions(game);

            

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

            timeDelayForEnemyMovement += GetFrameTime();
            if (timeDelayForEnemyMovement - 1 >= 0)
            {


                for (int i = 0; i < game.enemies.size(); i++)
                {

                    if (game.enemies[i].getXPos() == 1 && movedDown)
                    {
                        enemyDirection = 'R';
                        movedDown = false;
                        break;
                    }

                    if (game.enemies[i].getXPos() == 1 && !movedDown)
                    {
                        enemyDirection = 'D';
                        movedDown = true;
                        break;

                    }
                    
                    if (game.enemies[i].getXPos() == 20 && movedDown)
                    {
                        enemyDirection = 'L';
                        movedDown = false;
                        break;
                    }

                    if (game.enemies[i].getXPos() == 20 && !movedDown)
                    {
                        enemyDirection = 'D';
                        movedDown = true;
                        break;
                    }
                    
                }


                timeDelayForEnemyMovement = 0;

                for (int ii = 0; ii < game.enemies.size(); ii++)
                {
                    game.enemies[ii].move(enemyDirection);
                }
            }

            


        }
        else if(gameOver)
        {
             DrawText("GAME OVER", 610, 10, 20, LIGHTGRAY);
             StopMusicStream(music);
             PlayMusicStream(goMusic);
             UpdateMusicStream(goMusic);
            if(volumeCount % 2 ==0)
             {
                SetMusicVolume(goMusic, 0.0f);
             }
             if (volumeCount % 2 != 0)
             {
                 SetMusicVolume(goMusic, 1.0f);
             }
             DrawText("PRESS (ENTER) TO RESTART", 610, 530, 19, LIGHTGRAY);
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

        timer += GetFrameTime();
        Aframe = Aframe % maxAlienFrames;
        EPframe = EPframe % maxEpFrames;
        Wframe = Wframe % maxWallFrames;
        PPframe = PPframe % maxRFrames;
        
        if (timer >= 0.2f) {
            timer = 0.0f;
            Aframe += 1;
            EPframe += 1;
            Wframe += 1;
            PPframe += 1;
        }
        
        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE; y++)
            {
               int xPosition = x * cellSize;
                int yPosition = y * cellSize;
                float xpos = xPosition;
                float ypos = yPosition;
                switch (grid[y][x])
                {
                     case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK); break;

                    case WALL: DrawTextureRec(wall, Rectangle{ wallFrameWidth * Wframe,0,wallFrameWidth,(float)wall.height }, Vector2{ xpos,ypos }, WHITE);    break;

                    case PLAYER: DrawTexture(texture, xPosition, yPosition, WHITE);    break;
      
                    case ENEMY:  DrawTextureRec(alien, Rectangle{ alienFrameWidth *Aframe,0,alienFrameWidth,(float)alien.height },Vector2{xpos,ypos},WHITE);    break;  

                    case PLAYERPROJECTILE: DrawTextureRec(pProj, Rectangle{ rFrameWidth * PPframe,0,rFrameWidth,(float)pProj.height }, Vector2{ xpos,ypos }, WHITE);  break;

                    case ENEMYPROJECTILE: DrawTextureRec(eProj, Rectangle{ eProjFrameWidth *EPframe,0,eProjFrameWidth,(float)eProj.height }, Vector2{ xpos,ypos }, WHITE);  break;
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
