#ifndef _RGB2BGR_
#define _RGB2BGR_
#include "CImg.h"
using namespace cimg_library;

class RGB2BGR
{

    public:

    CImg<unsigned char> rgb2bgr(const CImg<unsigned char>& image);

};

#endif