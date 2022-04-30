#include "ViewPlane.h"
#include "cstdlib"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

ViewPlane::ViewPlane(void)
{
    distance = 250;
    nCols = 721;
    nRows = 481;
    // nRows = 7;
    // nCols = 7;
    pixelSize = 1.0f;
    nSamplesPerPixel = 1.0; // no anti-aliasing for now
    channelsPerPixel = 3;
    pImgData = (unsigned char *)malloc(sizeof(char) * nRows * nCols * channelsPerPixel);
}

ViewPlane::~ViewPlane()
{
    // free(pImgData);
    // pImgData = NULL;
}

void ViewPlane::drawPixel(Pixel p, unsigned int row, unsigned int col)
{
    // RGBA
    unsigned int red = (unsigned int)(255 * p.r);
    unsigned int green = (unsigned int)(255 * p.g);
    unsigned int blue = (unsigned int)(255 * p.b);
    unsigned int alpha = (unsigned int)(255 * p.a);
    unsigned int color = (blue << 16) | (green << 8) | (red) ;
    *(unsigned int *)((unsigned char *)pImgData + (((row * nCols) + col) * channelsPerPixel)) = color;
}

void ViewPlane::drawImg(void)
{
    char const *filename = "Sphere.png";
    // memset((void*)pImgData,0x00,481*721*3*sizeof(unsigned char));
    stbi_write_png(filename, nCols, nRows, channelsPerPixel, (const void *)pImgData, (unsigned int)sizeof(unsigned char) * channelsPerPixel * nCols);
}
