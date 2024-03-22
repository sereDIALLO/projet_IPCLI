#ifndef _SOBEL_
#define _SOBEL_ 
#include "CImg.h"
using namespace cimg_library;
class GradSobel
{
    public:
    CImg<unsigned char> gradsobel(const CImg<unsigned char>& image);

};


#endif