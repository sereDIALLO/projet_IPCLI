#include "CImg.h"
#include "FilterRed.hpp"

CImg<unsigned char> FilterRed::filterred(const CImg<unsigned char>& image)
{
    CImg<unsigned char> resultat(image.width(), image.height(), 1, 3, 0);
    cimg_forXY(image, x, y)
    {
        unsigned char valueR = image(x,y,0);
        //unsigned char valueG = image(x,y,1);
        //unsigned char valueB = image(x,y,2);
        resultat(x,y,0) = valueR;
        resultat(x,y,1) = 0;
        resultat(x,y,2) = 0;
    }

    return resultat;

}