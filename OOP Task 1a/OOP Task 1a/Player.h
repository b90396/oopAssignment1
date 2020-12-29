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
        int getScore();
        int getLives();


        // mutators
        void Move(int key);
        void resetScore();
        void incrementScore();
        void setLives();
        void decreaseLives();
        char symbol;
        int  x, y;
        void Shoot();
        //Removed the x for testing purposes

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