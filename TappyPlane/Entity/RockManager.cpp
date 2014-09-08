#include "RockManager.h"
namespace {

    /**
     ** 0 = Regular Rock
     ** 1 = Grass Rock
     ** 2 = Ice Rock
     ** 3 = Snow Rock
     **/
    const int SPRITE_OFFSET_NORTH_X[4] = {324,264,222,108};
    const int SPRITE_OFFSET_NORTH_Y[4] = {1489,986,1250,1757};

    const int SPRITE_OFFSET_SOUTH_X[4] = {114,0,216,324};
    const int SPRITE_OFFSET_SOUTH_Y[4] = {1400,1757,1639,1728};

}

RockManager::RockManager()
{
    elapsedTime_ = 0;

}

void RockManager::init(int type)
{
    type_ = type;
    NorthSouthRock northSouthRock;
    northSouthRock.setSourceOffsets(SPRITE_OFFSET_NORTH_X[type_], SPRITE_OFFSET_NORTH_Y[type_], SPRITE_OFFSET_SOUTH_X[type_], SPRITE_OFFSET_SOUTH_Y[type_]);
    rocks_.push_back(northSouthRock);
}
void RockManager::update(int deltaTime) {
    elapsedTime_ += deltaTime;
    if(!rocks_.empty()) {
    // printf("Size of rocks Container: %d \n", rocksContainer_.size());


        //Creating new rocks
        if (elapsedTime_ > 1200/*ms*/)
        {
            NorthSouthRock northSouthRock;
            northSouthRock.setSourceOffsets(SPRITE_OFFSET_NORTH_X[type_], SPRITE_OFFSET_NORTH_Y[type_], SPRITE_OFFSET_SOUTH_X[type_], SPRITE_OFFSET_SOUTH_Y[type_]);
            rocks_.push_back(northSouthRock);

            elapsedTime_ = 0;

        }
        //Remove rocks if the are out of bounds
        if (rocks_.front().isOutOfBounds())
        {
            rocks_.erase(rocks_.begin());
        }

        for (int i = 0; i < rocks_.size(); i++)
        {
            rocks_[i].update(deltaTime);
            //rocksContainer_[i].shiftBoxes();
        }


     }

}

void RockManager::draw(Graphics* graphics, Image* image)
{
    //printf("Size of rocks Container Drawing: %d \n", rocksContainer_.size());
    if(!rocks_.empty()) {

        for (int i = 0; i < rocks_.size(); i++) {
            rocks_[i].draw(graphics,image);

        }
    }
}

/*
 * Returns the rock container
 * @return the rock container
 */
std::vector<NorthSouthRock>& RockManager::getRocks()
{
    return rocks_;
}

/*
 * Clear the rock container
 */
void RockManager::clearRocks()
{
    if (!rocks_.empty())
    {
        rocks_.clear();
    }

}

