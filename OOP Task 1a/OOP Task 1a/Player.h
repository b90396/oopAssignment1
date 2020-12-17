#pragma once

#include "constants.h"

class Player
{
    public:
        // constructor
        Player();

        // assessors
        int GetX();
        int GetY();
        char GetSymbol() const;
        bool IsAtPosition(int x, int y);
        void Shoot(int xPosition);
        int getScore();
        void resetScore();
        void incrementScore();
        int getLives();
        void setLives();
        void decreaseLives();

        

        // mutators
        void Move(int key);

        char symbol;
        int  x, y;

    private:
        // data members
        bool alive;
        bool escaped;
        int dx;
        int dy;
        int score;
        int lives;
        

        // supporting functions 
        void PositionAtStartingPosition();
        void UpdatePosition(int dx, int dy);
};