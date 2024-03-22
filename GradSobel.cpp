#include "GradSobel.hpp"
#include <vector>

CImg<unsigned char> GradSobel::gradsobel(const CImg<unsigned char>& image)
{
    // Déclaration de l'image de sortie
    CImg<unsigned char> result(image.width(), image.height(), 1, 1, 0);

    // Déclaration des masques Sobel en x et y
    std::vector<std::vector<int>> sobelX = {{-1, 0, 1},
                                             {-2, 0, 2},
                                             {-1, 0, 1}};
    std::vector<std::vector<int>> sobelY = {{-1, -2, -1},
                                             { 0,  0,  0},
                                             { 1,  2,  1}};

    // Taille du voisinage des pixels à considérer
    int w = 1; // À ajuster selon vos besoins
    int seuil = 75;
    // Parcourir chaque pixel de l'image (à l'exception des bords)
    for (int i = w; i < image.width() - w; ++i)
    {
        for (int j = w; j < image.height() - w; ++j)
        {
            int sumGx = 0;
            int sumGy = 0;

            // Appliquer le masque de Sobel en x et y sur le voisinage du pixel
            for (int u = -w; u <= w; ++u)
            {
                for (int v = -w; v <= w; ++v)
                {
                    sumGx += sobelX[u + w][v + w] * image(i + u, j + v);
                    sumGy += sobelY[u + w][v + w] * image(i + u, j + v);
                }
            }

            // Calculer la magnitude du gradient
            int magnitude = sqrt(sumGx * sumGx + sumGy * sumGy);

            // Limiter la valeur de la magnitude à 255 pour éviter le dépassement
            magnitude = std::min(255, std::max(0, magnitude));
            //seuiller l'image de gradient pour obtenir l'image de contour
            if(magnitude > seuil)
                result(i,j) = 255;
            else
                result(i,j) = 0;
            // Assigner la magnitude à l'image de sortie
            //result(i, j) = magnitude;
        }
    }

    return result;
}