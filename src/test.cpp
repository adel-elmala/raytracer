// #include <cstdio>
#include "Vector3.h"
#include "Point3.h"
#include "Point2.h"
#include "Normal3.h"
#include "Ray.h"

#include "Sphere.h"
#include "Camera.h"

#include "World.h"

int main(int argc, const char *argv[])
{
    // Sphere 1 -- red
    Sphere *p1 = new Sphere;
    p1->center = Point3(0.0, 20.0, -80.0);
    p1->radius = 20.0f;
    p1->color = RGBColor(1.0f, 0.0f, 0.0f);

    // Sphere 2 -- yellow
    Sphere *p2 = new Sphere;
    p2->center = Point3(-15.0, 12.0, -40.0);
    p2->radius = 20.0f;
    p2->color = RGBColor(1.0f, 1.0f, 0.0f);
    // camera
    Camera cam;

    // build World
    World w;
    w.objects.push_back(p1);
    w.objects.push_back(p2);
    w.backGroundColor = RGBColor(0.5f, 0.5f, 0.5f);
    w.camera = cam;

    for (int x = 0; x < (cam.vp->nCols); ++x)
    {
        for (int y = 0; y < (cam.vp->nRows); ++y)
        {
            Ray r;
            float xPix = cam.vp->pixelSize * (x - (((cam.vp->nCols)) / 2.0) + 0.5);
            float yPix = cam.vp->pixelSize * (y - (((cam.vp->nRows)) / 2.0) + 0.5);
            r.origin = cam.eye + Vector3(xPix, yPix, -(cam.vp->distance));
            r.direction = Vector3(0.0, 0.0, -1.0);
            double tmin = DBL_MAX;
            bool hit = false;
            for (int i = 0; i < w.objects.size(); ++i)
            {
                if (w.objects[i]->hit(r, tmin))
                {
                    hit = true;
                    cam.vp->drawPixel(w.objects[i]->color, y, x);
                }
            }
            if (!hit)
                cam.vp->drawPixel(w.backGroundColor, y, x);
        }
    }
    cam.vp->drawImg();

    return 0;
}

void test(void)
{
    // fprintf(stdout,"hi!\n");
    Vector3 i(1.0, 0.0, 0.0);
    Vector3 j(0.0, 1.0, 0.0);
    Vector3 k = i ^ j;
    k.prettyPrint();

    Point3 p(10.0, 0.0, 0.0);
    Point3 translated = p + k;
    translated.prettyPrint();
    Point2 p2(10.0, 0.0);
    Point2 scaled = p2 * 2;
    Point2 scaled2 = 2 * p2;
    scaled2.prettyPrint();
    scaled.prettyPrint();

    Normal3 n(2.0);
    n.prettyPrint();
    Ray r(p, i);
}