#ifndef ROCKMANAGER_H_
#define ROCKMANAGER_H_

//Entity
#include "NorthSouthRock.h"

#include <vector>
class RockManager
{
private:
    std::vector<NorthSouthRock> rocks_;
    int elapsedTime_;
    int type_;
public:
    RockManager();
    void init(int type);
    void update(int deltaTime);
    void draw(Graphics* graphics, Image* image);
    std::vector<NorthSouthRock>& getRocks();
    void clearRocks();
};
#endif // ROCKMANAGER_H_

