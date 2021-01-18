#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Enemy.h"
#include "Projectile.h"
#include "PlayerProjectile.h"
#include "EnemyProjectile.h"
#include "FileHandler.h"

using namespace std;

class Game
{
   public:
      Player player;
      vector<Wall> walls;
      vector<Enemy> enemies;
      vector<Projectile> projectiles;
      vector<PlayerProjectile> playerprojectiles;
      vector<EnemyProjectile> enemyprojectiles;
      FileHandler fh;
      float enemyspeed = 1;

      void BuildEnemies();
      void Setup();
      void ProcessInput(int key);
      vector<vector<char>> PrepareGrid();
      void BuildEnvironment();
      void IncreaseSpeed();
      void SetSpeed();
      void BuildWall1();
      void BuildWall2();
      void BuildWall3();
      bool RestartGame();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
      bool IsEnemyAtPosition(int x, int y);
      bool IsProjectileAtPosition(int x, int y);
      bool IsEnemyProjectileAtPosition(int x, int y);
      bool IsPlayerDead();
      bool EnemiesAtEnd();
      
      void SavePlayerScore();
      vector<int> GetHighScores();
      int getScore();
      int getLives();

      void HandlePlayerProjectileToEnemyCollisions();
      void HandlePlayerProjectileToWallCollisions();
      void HandleEnemyMovementToWallCollisions();
      void HandleProjectileToProjectileCollisions();
      void HandleEnemyProjectileToPlayerCollisions();
      void HandleEnemyProjectileToWallCollisions();
};