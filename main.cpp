#include <iostream>
#include "GrayScale.hpp"
#include "RGB2BGR.hpp"
#include "FilterRed.hpp"
#include "FilterGreen.hpp"
#include "FilterBlue.hpp"
#include "GradSobel.hpp"
#include "CImg.h"
#include <cstring> // Pour utiliser strcmp

int main(int argc, char* argv[])
{
    // Vérifier qu'il y a suffisamment d'arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " input.jpg output.jpg filter" << std::endl;
        return 1;
    }

    // Charger l'image d'entrée
    const char* inputFileName = argv[1];
    // donner un nom à l'image de sortie avec extension de votre choix
    const char* outputFileName = argv[2];
    // filtre à appliquer 
    const char* filterName = argv[3];
    
    CImg<unsigned char> image(inputFileName);

    // Appliquer le filtre approprié
    if (std::strcmp(filterName, "GrayScale") == 0) 
    {
        GrayScale grayscaleFilter;
        image = grayscaleFilter.grayscale(image);
    }
    else if(std::strcmp(filterName, "RGB2BGR") == 0) 
    {
        RGB2BGR rgb2bgrFilter;
        image = rgb2bgrFilter.rgb2bgr(image);
    }
    else if(std::strcmp(filterName, "FilterRed") == 0)
    {
        FilterRed red;
        image = red.filterred(image); 
    }
    else if(std::strcmp(filterName, "FilterGreen") == 0)
    {
        FilterGreen green;
        image = green.filtergreen(image);
    }
    else if(strcmp(filterName, "FilterBlue") == 0)
    {
        FilterBlue blue;
        image = blue.filterblue(image);
    }
    else if(strcmp(filterName, "GradSobel") == 0)
    {
        GradSobel sobel;
        image = sobel.gradsobel(image);
    }
    else 
    {
        std::cerr << "Unknown filter: " << filterName << std::endl;
        return 1;
    }

    // Enregistrer l'image de sortie
    image.save(outputFileName);

    return 0;
}