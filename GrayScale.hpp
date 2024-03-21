#ifndef _GRAYSCALE_
#define _GRAYSCALE_

#include "CImg.h"
using namespace cimg_library;

class GrayScale {
public:
    CImg<unsigned char> grayscale(const CImg<unsigned char>& image);
};

#endif