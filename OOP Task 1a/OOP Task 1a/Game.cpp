#include "Game.h"

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

    enemies.push_back(Enemy(1, 2));
    enemies.push_back(Enemy(3, 2));
    enemies.push_back(Enemy(5, 2));
    enemies.push_back(Enemy(7, 2));
    enemies.push_back(Enemy(9, 2));
    enemies.push_back(Enemy(11, 2));

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
            else if (IsProjectileAtPosition(col, row))
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
    for (size_t i = 0; i < enemyprojectile.size(); ++i)
    {
        if (enemyprojectile[i].getXPos() == x && enemyprojectile[i].getYPos() == y)
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

void Game::HandlePlayerProjectiles()
{
    for (int i = 0; i < playerprojectiles.size(); i++)
    {
        for (int j = 0; j < enemies.size(); j++)
        {
            for (int k = 0; k < walls.size(); k++)
            {
                // Player Projectile hits an Enemy...
                if ((playerprojectiles[i].getXPos() == enemies[j].getXPos()) && (playerprojectiles[i].getYPos() == enemies[j].getXPos()))
                {
                    // remove Projectile.
                    playerprojectiles.erase(playerprojectiles.begin() + i);

                    // remove Enemy.
                    enemies.erase(enemies.begin() + j);
                }

                // Player Projectile hits a Wall piece...
                if ((playerprojectiles[i].getXPos() == walls[k].GetX()) && (playerprojectiles[i].getYPos() == walls[k].GetY()))
                {
                    // remove Projectile.
                    playerprojectiles.erase(playerprojectiles.begin() + i);

                    // remove Wall piece.
                    walls.erase(walls.begin() + k);
                }

                // Player Projectile reaches end of screen...
                if (playerprojectiles[i].getYPos() < 0)
                {
                    // remove Projectile.
                    playerprojectiles.erase(playerprojectiles.begin() + i); 
                }
            }
        }
    }
}

void Game::HandleEnemyProjectiles()
{
    
    for (int i = 0; i < enemyprojectiles.size(); i++)
    {
        for (int j = 0; j < walls.size(); i++)
        {
             //Enemy Projectile hits Player...
            if ((enemyprojectiles[i].getXPos() == player.GetX()) && (enemyprojectiles[i].getYPos() == player.GetX()))
            {
                if (player.getLives() < 0)
                {
                     //Player lost...
                }
                else
               {
                     //Player lost a life...
                    player.decreaseLives();
                }
            }

             //Enemy Projectile hits Wall piece...
            if ((enemyprojectiles[i].getXPos() == walls[j].GetX()) && (enemyprojectiles[i].getYPos() == walls[j].GetY()))
            {
                //remove Projectile.
                enemyprojectiles.erase(enemyprojectiles.begin() + i);

                // remove Wall piece.
                walls.erase(walls.begin() + j);
            }

             //Enemy Projectile reaches end of screen...
            if (enemyprojectiles[i].getYPos() > 600 )
            {
                 //remove Projectile.
                enemyprojectiles.erase(enemyprojectiles.begin() + i); 
            }
        }
    }
}

int Game::getScore()
{
    return player.getScore();
}