#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Enemy.h"

using namespace std;

class Game
{
   public:
      Player player;
      vector<Wall> walls;
      vector<Enemy> enemies;
      void Setup();
      void ProcessInput(int key);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
      bool IsEnemyAtPosition(int x, int y);
};