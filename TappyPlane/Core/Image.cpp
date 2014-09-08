#include "Image.h"

/**
 ** constructor
 **/
Image::Image() {

    imageSurface_ = NULL;
}

/**
 ** Loads the file located from the given file path
 **/
bool Image::load(string fileName) {

    //Load the image
    SDL_Surface* imageLoaded = NULL;
    imageLoaded = IMG_Load(fileName.c_str());

    if (imageLoaded != NULL) {
        //Set the image surface equal to the loaded image surface
        //and use the image's display format
        imageSurface_ = SDL_DisplayFormat(imageLoaded);
        //Free the surface used to load the image
        SDL_FreeSurface(imageLoaded);

        //If image surface is not null
        //Set the alpha mask
        if (imageSurface_ != NULL) {
            Uint32 colorKey = SDL_MapRGB( imageSurface_->format, 0x00, 0x00, 0x00 );
            SDL_SetColorKey(imageSurface_, SDL_SRCCOLORKEY, colorKey );
        }
        else {
            printf("Failed to load image: %s \n", fileName.c_str());
            return false;
        }
    }
    else {
        printf("Failed to load image: %s \n", fileName.c_str());
        return false;
    }

    printf("The image file: %s loaded! \n", fileName.c_str());
    return true;
}

void Image::draw(float destinationX, float destinationY, int sourceX, int sourceY, int sourceWidth, int sourceHeight, Graphics* g) {

    //The position of the sprite on the screen
    SDL_Rect destinationRect;
    destinationRect.x = destinationX;
    destinationRect.y = destinationY;

    //The location of the frame on the sprite sheet
    SDL_Rect sourceRect;
    sourceRect.x = sourceX;
    sourceRect.y = sourceY;
    sourceRect.w = sourceWidth;
    sourceRect.h = sourceHeight;

    SDL_BlitSurface(imageSurface_, &sourceRect, g->getBackBuffer(), &destinationRect);
}

/**
 ** Free the surface being used from memory
 **/
void Image::free() {

    if (imageSurface_ != NULL) {
        SDL_FreeSurface(imageSurface_);
        imageSurface_ = NULL;
    }
}

