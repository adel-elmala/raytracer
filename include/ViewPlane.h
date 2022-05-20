#ifndef VIEWPLANE_H
#define VIEWPLANE_H
#include <vector>
#include "RGBColor.h"

typedef RGBColor Pixel;
class ViewPlane
{
public:
    float distance;
    unsigned int nRows;
    unsigned int nCols;
    unsigned int channelsPerPixel;
    float pixelSize;
    unsigned int nSamplesPerPixel;
    // std::vector<Pixel> pixelsArray;
    unsigned char *pImgData;

    ViewPlane(void);
    ~ViewPlane();
    void drawPixel(Pixel p, unsigned int row, unsigned int col);
    void drawImg(void);
};

#endif