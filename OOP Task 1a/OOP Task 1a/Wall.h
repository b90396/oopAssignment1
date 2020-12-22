#pragma once

#include <assert.h>
#include "constants.h"

using namespace std;

class Wall
{
    private:
        // Attributes...
        char symbol;
        int x, y;
    public:
        // constructors
        Wall();
        Wall(int x, int y);
        ~Wall() {};

        // Mutator Methods...
        bool IsAtPosition(int x, int y);

        // Accessor methods...
        int GetX() const;
        int GetY() const;
        char GetSymbol() const;
};