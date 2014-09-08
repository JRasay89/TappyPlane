#include "PlayerScore.h"

namespace {
    //The width and height of the score background
    const int SCORE_BG_WIDTH = 264;
    const int SCORE_BG_HEIGHT = 264;
    //The x and y value for the location of the score background
    //in the sprite sheet
    const int SCORE_BG_SOURCE_OFFSET_X = 0;
    const int SCORE_BG_SOURCE_OFFSET_Y = 986;

    //Place the score on the middle of the screen
    const float SCORE_BG_OFFSET_X =  (800.0f/2.0f) - (264.0f/2.0f);
    const float SCORE_BG_OFFSET_Y = (480.0f/2.0f) - (264.0f/2.0f);

    //The width and height of the medal
    const int MEDAL_WIDTH = 114;
    const int MEDAL_HEIGHT = 119;
    /*
     *The bronze, silver and gold medal x and y value for the location
     * in the sprite sheet
     * 0 = bronze
     * 1 = silver
     * 2 = gold
    */
    const int MEDAL_SOURCE_OFFSET_X[3] = {0,0,0};
    const int MEDAL_SOURCE_OFFSET_Y[3] = {1400,1638,1519};
}

/*
 * Player Score Constructor
 */
PlayerScore::PlayerScore() {
    score_ = 0;
    //Get the current best score in the game which is recorded in a text file
    ifstream IscoreFile("Resource/PlayerScore/PlayerScore.txt");
    if (IscoreFile.is_open()) {
        IscoreFile >> bestScore_;
        printf("The previous best score is: %d \n", bestScore_);
        IscoreFile.close();
    }
}

//Increase the player score if the player pass the rock without touching it
void PlayerScore::updateScore(int planeOffsetX, std::vector<NorthSouthRock>& rocks) {

    //Check if rock vector is empty
    if (!rocks.empty())
    {
        for (int i = 0; i < rocks.size(); i++)
        {
            //Check the rock has not yet been passed and check if the plane has reached the rock
            //if true then increase the player score
            if (!rocks[i].isPassed() && rocks[i].isReached(planeOffsetX))
            {
                score_++;
            }
        }
    }

}

/*
 * If the current score surpasses the best score,
 * then record the new best score on the text file.
 */
void PlayerScore::updateBestScore()
{
    //If the current score is greater than the previous best score
    //overwrite the old best score with the new best score
    if (score_ > bestScore_)
    {
        ofstream OscoreFile("Resource/PlayerScore/PlayerScore.txt");
        if (OscoreFile.is_open()) {
            OscoreFile << score_ << "\n";
            OscoreFile.close();
        }
    }
}

void PlayerScore::drawScore(Graphics* graphics, OutlineFont* outlineFont)
{
    if (score_ > 0)
    {
        //Convert the int score to string
        //and display it to screen
        std::stringstream ss;
        ss << score_;
        outlineFont->drawOutlineText(ss.str(),400,0,0,0,0,graphics);
    }
}
void PlayerScore::drawFinalScore(Graphics* graphics, Image* image, OutlineFont* outlineFont)
{
    image->draw(200,20,0,835,412,78,graphics);
    //Draw the score background
    image->draw(SCORE_BG_OFFSET_X, SCORE_BG_OFFSET_Y, SCORE_BG_SOURCE_OFFSET_X, SCORE_BG_SOURCE_OFFSET_Y, SCORE_BG_WIDTH, SCORE_BG_HEIGHT, graphics);

    //Draw the score on the background
    std::stringstream ss;
    ss << score_; //convert int to string
    outlineFont->drawOutlineText("Score:", SCORE_BG_OFFSET_X + 10.0f, SCORE_BG_OFFSET_Y, 0, 0, 0, graphics);
    outlineFont->drawOutlineText(ss.str(), SCORE_BG_OFFSET_X + 200.0f, SCORE_BG_OFFSET_Y, 0, 0, 0, graphics);

    //Draw the best score on the background
    std::stringstream ssBest;
    ssBest << bestScore_; //convert int to string
    //Best Score
    outlineFont->drawOutlineText("Best:",SCORE_BG_OFFSET_X+ 10.0f, SCORE_BG_OFFSET_Y + 50.0f, 0, 0, 0,graphics);
    outlineFont->drawOutlineText(ssBest.str(), SCORE_BG_OFFSET_X + 200.0f, SCORE_BG_OFFSET_Y + 50, 0, 0, 0, graphics);

    //Draw the medal received
    //Give the player either bronze, silver or gold if the following conditions are met
    outlineFont->drawOutlineText("Medal:", SCORE_BG_OFFSET_X + 10.0f, SCORE_BG_OFFSET_Y + 100.0f, 0, 0, 0,graphics); //Draw the word medal on the score background
    //If score is less than the current best score, then give the player a bronze medal
    if ((score_ - bestScore_) < 0)
    {
        image->draw(SCORE_BG_OFFSET_X + (SCORE_BG_OFFSET_X/2.0f - (114.0f/2.0f)), SCORE_BG_OFFSET_Y + (198.0f - 60.0f) , MEDAL_SOURCE_OFFSET_X[0], MEDAL_SOURCE_OFFSET_Y[0], MEDAL_WIDTH, MEDAL_HEIGHT, graphics);

    }
    //else check the percentage difference of the current score from the best score
    else
    {
        double newScorePercent = (((double)score_ - (double)bestScore_)/(double)bestScore_) * 100;

        //std::cout << newScorePercent << " Percentage" << std::endl;
        //If the the new score is less than or equal to 25% greater than the current best score, then give the player a bronze medal
        if (newScorePercent <= 25) {
            image->draw(SCORE_BG_OFFSET_X + (SCORE_BG_OFFSET_X/2.0f - (114.0f/2.0f)), SCORE_BG_OFFSET_Y + (198.0f - 60.0f) , MEDAL_SOURCE_OFFSET_X[0], MEDAL_SOURCE_OFFSET_Y[0], MEDAL_WIDTH, MEDAL_HEIGHT, graphics);
        }
        //else if the new score is less than or equal to 50% greater than the current best score, then give the player a silver medal
        else if (newScorePercent <= 50) {
            image->draw(SCORE_BG_OFFSET_X + (SCORE_BG_OFFSET_X/2.0f - (114.0f/2.0f)), SCORE_BG_OFFSET_Y + (198.0f - 60.0f) , MEDAL_SOURCE_OFFSET_X[1], MEDAL_SOURCE_OFFSET_Y[1], MEDAL_WIDTH, MEDAL_HEIGHT, graphics);
        }
        //else if the new score is more than 50% greater than the current best score, then give the player a gold medal
        else {
            image->draw(SCORE_BG_OFFSET_X + (SCORE_BG_OFFSET_X/2.0f - (114.0f/2.0f)), SCORE_BG_OFFSET_Y + (198.0f - 60.0f) , MEDAL_SOURCE_OFFSET_X[2], MEDAL_SOURCE_OFFSET_Y[2], MEDAL_WIDTH, MEDAL_HEIGHT, graphics);
        }
    }
}
