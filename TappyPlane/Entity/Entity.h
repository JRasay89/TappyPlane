#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
private:
    float offsetX_;
    float offsetY_;

    //The width, height, offset x and offset y of the object on the sprite sheet
    int sourceWidth_;
    int sourceHeight_;

public:
    void setOffsetX(float offsetX);
    void setOffsetY(float offsetY);

    void setSourceWidth(int sourceWidth);
    void setSourceHeight(int sourceHeight);


    float getOffsetX();
    float getOffsetY();

    int getSourceWidth();
    int getSourceHeight();
};

#endif // ENTITY_H_

