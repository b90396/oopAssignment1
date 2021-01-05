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


      void Setup();
      void ProcessInput(int key);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
      bool IsEnemyAtPosition(int x, int y);
      bool IsProjectileAtPosition(int x, int y);
      bool IsEnemyProjectileAtPosition(int x, int y);

      int getScore();

      string ReadFromFile(string dir);
      void WriteToFile(string fileName, string content);


      void HandlePlayerToEnemyCollisions();
      void HandlePlayerToWallCollisions();
      void HandleProjectileToProjectileCollisions();
      void HandleEnemyToPlayerCollisions();
      void HandleEnemyToWallCollisions();
};