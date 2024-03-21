#include "FilterBlue.hpp"

CImg<unsigned char> FilterBlue::filterblue(const CImg<unsigned char>& image)
{
    CImg<unsigned char> resultat(image.width(), image.height(), 1, 3, 0);
    cimg_forXY(image, x, y)
    {
        unsigned char valueB = image(x,y,2);
        resultat(x,y,0) = 0;
        resultat(x,y,1) = 0;
        resultat(x,y,2) = valueB;
    }
    return resultat;
}