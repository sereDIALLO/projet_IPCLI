#ifndef _BLUE_
#define _BLUE_
#include "CImg.h"
using namespace cimg_library;

class FilterBlue
{
    public:
    CImg<unsigned char> filterblue(const CImg<unsigned char>& image);
};

#endif