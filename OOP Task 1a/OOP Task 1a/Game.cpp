#include "Game.h"

#include <iostream>
using namespace std;

void Game::Setup()
{
    // block one
    walls.push_back(Wall(2, 17));
    walls.push_back(Wall(3, 17));
    walls.push_back(Wall(4, 17));
    walls.push_back(Wall(5, 17));

    walls.push_back(Wall(3, 16));
    walls.push_back(Wall(4, 16));

    // block two
    walls.push_back(Wall(9, 17));
    walls.push_back(Wall(10, 17));
    walls.push_back(Wall(11, 17));
    walls.push_back(Wall(12, 17));

    walls.push_back(Wall(10, 16));
    walls.push_back(Wall(11, 16));

    // block three
    walls.push_back(Wall(16, 17));
    walls.push_back(Wall(17, 17));
    walls.push_back(Wall(18, 17));
    walls.push_back(Wall(19, 17));

    walls.push_back(Wall(17, 16));
    walls.push_back(Wall(18, 16));

    //CREATE ENEMIES HERE
    BuildEnemies();
    player.setLives();
    player.resetScore();
}

void Game::ProcessInput(int key)
{
    if (key == KEY_SPACE)
    {
        player.Shoot(playerprojectiles);
    }
    else
    {
        player.Move(key);
    }
}


void Game::BuildEnemies()
{
    for (int i = 1; i <= 17; i+= 2)
    {
        for (int j = 2; j <= 6; j += 2)
        {
            enemies.push_back(Enemy(i, j));
        }
    }
}
/// <summary>
/// This function builds up a 2D grid of characters representing the current state of the game.
/// The characters are later used to decide which colour sqaure to display, but you could display images instead.
/// </summary>
vector<vector<char>> Game::PrepareGrid()
{
    // create the 2D grid
    vector<vector<char>> grid;

    // for each row
    for (int row = 1; row <= SIZE; ++row)
    {
        // create the inner vector to add to the 2D grid
        vector<char> line;

        // for each column, work out what's in that position and add the relevant char to the 2D grid
        for (int col = 1; col <= SIZE; ++col)
        {
            if (row == player.GetY() && col == player.GetX())   // create player.
            {
                line.push_back(player.GetSymbol());
            }
            else if (IsWallAtPosition(col, row))                // create wall.
            {
                line.push_back(WALL);
            }
            else if(IsEnemyAtPosition(col, row))                // create enemy.
            {
                line.push_back(ENEMY);
            }
            else if (IsProjectileAtPosition(col, row))          // create player projectile.
            {
                line.push_back(PLAYERPROJECTILE);
            }
            else if(IsEnemyProjectileAtPosition(col,row))
            {
                line.push_back(ENEMYPROJECTILE);
            }
            else
            {
                line.push_back(FLOOR);
            }


        }
          
        // now that the row is full, add it to the 2D grid
        grid.push_back(line);
    }

    return grid;
}

bool Game::IsWallAtPosition(int x, int y)
{
    for (size_t i = 0; i < walls.size(); ++i)
    {
        if (walls[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}

bool Game::IsEnemyAtPosition(int x, int y)
{
    for (size_t i = 0; i < enemies.size(); ++i)
    {
        if (enemies[i].getXPos() == x && enemies[i].getYPos() == y)
        {
            return true;
        }
    }

        return false;
    }

bool Game::IsProjectileAtPosition(int x, int y)
{
    for (size_t i = 0; i < playerprojectiles.size(); ++i)
    {
        if (playerprojectiles[i].getXPos() == x && playerprojectiles[i].getYPos() == y)
        {
            return true;
        }
    }

    return false;
}
bool Game::IsEnemyProjectileAtPosition(int x, int y)
{
    for (size_t i = 0; i < enemyprojectiles.size(); ++i)
    {
        if (enemyprojectiles[i].getXPos() == x && enemyprojectiles[i].getYPos() == y)
        {
            return true;
        }
    }

    return false;
}
bool Game::IsRunning()
{
    // depending on your game you'll need to modify this to return false
    // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!
    return true;
}

// to-do
// remove projectiles that reach end of screen.
void Game::HandleEnemyCollisionWithWall()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        for (int j = 0; j < walls.size(); j++)
        {
            if ((enemies[i].getXPos() == walls[j].GetX()) && (enemies[i].getYPos() == walls[j].GetY()))
            {
                walls.erase(walls.begin() + j);
            }
        }
    }
}
void Game::HandlePlayerToEnemyCollisions()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        for (int j = 0; j < playerprojectiles.size(); j++)
        {
            // Player Projectile hits an Enemy...
            if ((playerprojectiles[j].getXPos() == enemies[i].getXPos()) && (playerprojectiles[j].getYPos() == enemies[i].getYPos()))
            {
                // remove Projectile.
                playerprojectiles.erase(playerprojectiles.begin() + j);

                player.incrementScore();

                // remove Enemy.
                enemies.erase(enemies.begin() + i);
                
                cout << "Hit the enemy." << endl;
            }

        }
    }
}

void Game::HandlePlayerToWallCollisions()
{
    for (int i = 0; i < walls.size(); i++)
    {
        for (int j = 0; j < playerprojectiles.size(); j++)
        {
            // Player Projectile hits an Enemy...
            if ((playerprojectiles[j].getXPos() == walls[i].GetX()) && (playerprojectiles[j].getYPos() == walls[i].GetY()))
            {
                // remove Projectile.
                playerprojectiles.erase(playerprojectiles.begin() + j);

                // remove Wall.
                walls.erase(walls.begin() + i);

                cout << "Hit the Wall." << endl;
            }
        }
    }
}

void Game::HandleEnemyToPlayerCollisions()
{
    for (int i = 0; i < enemyprojectiles.size(); i++)
    {
        // Enemy Projectile hits Player...
        if ((enemyprojectiles[i].getXPos() == player.GetX()) && (enemyprojectiles[i].getYPos() == player.GetY()))
        {
            enemyprojectiles.erase(enemyprojectiles.begin() + i);
            player.decreaseLives();
            cout << "Player Hit";
        }
    }
}

void Game::HandleEnemyToWallCollisions()
{
    for (int i = 0; i < walls.size(); i++)
    {
        for (int j = 0; j < enemyprojectiles.size(); j++)
        {
            // Player Projectile hits an Enemy...
            if ((enemyprojectiles[j].getXPos() == walls[i].GetX()) && (enemyprojectiles[j].getYPos() == walls[i].GetY()))
            {
                // remove Projectile.
                enemyprojectiles.erase(enemyprojectiles.begin() + j);

                // remove Wall.
                walls.erase(walls.begin() + i);
            }
        }
    }
}

int Game::getScore()
{
    return player.getScore();
}

int Game::getLives()
{
    return player.getLives();
}

bool Game::IsPlayerDead()
{
    if (player.getLives() <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}