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
TomBranch
      vector<Projectile> projectiles;
      vector<PlayerProjectile> playerprojectiles;
      vector<EnemyProjectile> enemyprojectile;


main
      void Setup();
      void ProcessInput(int key);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
      bool IsEnemyAtPosition(int x, int y);
TomBranch
      bool IsProjectileAtPosition(int x, int y);
      int getScore();

      void HandlePlayerProjectiles();
      void HandleEnemyProjectiles();
main
};