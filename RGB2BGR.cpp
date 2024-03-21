#include "RGB2BGR.hpp"
#include "CImg.h"

CImg<unsigned char> RGB2BGR::rgb2bgr(const CImg<unsigned char>& image)
{
    CImg<unsigned char> resultat(image.width(), image.height(), 1, 3, 0);
    cimg_forXY(image, x,y)
    {
        unsigned char valueR = image(x,y,0);
        unsigned char valueG = image(x,y,1);
        unsigned char valueB = image(x,y,2);
        resultat(x,y,0) = valueB;
        resultat(x,y,1) = valueG;
        resultat(x,y,2) = valueR;
    }
    return resultat;

}