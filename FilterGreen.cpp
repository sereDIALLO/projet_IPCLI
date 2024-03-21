#include "CImg.h"
#include "FilterGreen.hpp"

CImg<unsigned char> FilterGreen::filtergreen(const CImg<unsigned char>& image)
{
    CImg<unsigned char> resultat(image.width(), image.height(), 1, 3, 0);
    cimg_forXY(image, x, y)
    {
        unsigned char valueG = image(x,y,1);
        resultat(x,y,0) = 0;
        resultat(x,y,1) = valueG;
        resultat(x,y,2) = 0;
    }
   
    return resultat;
}