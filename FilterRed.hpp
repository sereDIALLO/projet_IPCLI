#ifndef _RED_
#define _RED_ 
#include "CImg.h"
using namespace cimg_library;

class FilterRed 
{
    public:
    CImg<unsigned char> filterred(const CImg<unsigned char>& image);


};
#endif