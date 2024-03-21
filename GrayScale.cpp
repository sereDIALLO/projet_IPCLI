

#include "GrayScale.hpp"
#include "CImg.h"

CImg<unsigned char> GrayScale::grayscale(const CImg<unsigned char> &image)
{
    CImg<unsigned char> resultat(image.width(), image.height(), 1, 3, 0);

    cimg_forXY(image, x, y) 
    {
        unsigned char value = (image(x, y, 0) + image(x, y, 1) + image(x, y, 2)) / 3;
        resultat(x, y, 0) = value;
        resultat(x, y, 1) = value;
        resultat(x, y, 2) = value;
    }

    return resultat;
}