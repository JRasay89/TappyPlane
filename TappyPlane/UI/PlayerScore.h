#ifndef PLAYERSCORE_H_
#define PLAYERSCORE_H_

#include "../Core/Image.h"
#include "../Core/Graphics.h"
#include "../Core//OutlineFont.h"

#include "../Entity/NorthSouthRock.h"

#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

class PlayerScore {

private:
    int score_;
    int bestScore_;
public:
    PlayerScore();
    void updateScore(int planeOffsetX, std::vector<NorthSouthRock>& rocks);
    void updateBestScore();
    void drawScore(Graphics* graphics, OutlineFont* outlineFont);
    void drawFinalScore(Graphics* graphics, Image* image,OutlineFont* outlineFont);
};
#endif // PLAYERSCORE_H_
