// #include <cstdio>
#include "Vector3.h"
#include "Point3.h"
#include "Point2.h"
#include "Normal3.h"
#include "Ray.h"

#include "Sphere.h"
#include "Plane.h"
#include "Camera.h"
#include "Light.h"
#include "ShadeRec.h"

#include "World.h"

const double PI = 3.14159265359;
#define MAX(n, m) (n >= m ? n : m)

void buildScene(World &w);
RGBColor shade(World &w, ShadeRec &rec, Ray &r);

int main(int argc, const char *argv[])
{

    // camera
    Camera cam;
    cam.eye = Point3(0.0, 0.0, 50.0);
    cam.lookAt = Point3(0.0, 0.0, -30.0);
    cam.vp->distance = 500;
    cam.setup_uvw();

    // build World
    World w;
    buildScene(w);
    w.backGroundColor = RGBColor(0.2f, 0.2f, 0.2f);
    w.camera = cam;

    for (int y = 0; y < (cam.vp->nRows); ++y) // loop on  rows
    {
        for (int x = 0; x < (cam.vp->nCols); ++x) // loop on  cols
        {
            Ray r;
            float xPix = cam.vp->pixelSize * (x - (((cam.vp->nCols)) / 2.0) + 0.5);
            float yPix = cam.vp->pixelSize * (y - (((cam.vp->nRows)) / 2.0) + 0.5);

            // --------Orthographic camera--------
            // r.origin = cam.eye + Vector3(xPix, yPix, -(cam.vp->distance));
            // r.direction = Vector3(0.0,0.0,-1.0);

            // --------Prespective camera--------
            r.origin = cam.eye;
            // r.direction = Point3(xPix, yPix, -(cam.vp->distance)) - cam.eye;
            r.direction = xPix * (w.camera.u) + yPix * (w.camera.v) - ((cam.vp->distance) * (w.camera.w));
            double tmin = DBL_MAX;
            bool hit = false;
            ShadeRec rec;
            for (int i = 0; i < w.objects.size(); ++i)
            {
                if (w.objects[i]->hit(r, tmin, rec))
                {
                    hit = true;
                    rec.objectIndex = i;
                    // cam.vp->drawPixel(w.objects[i]->color, y, x);

                    // cam.vp->drawPixel((w.objects[i]->color)), y, x);
                }
            }
            if (hit)
            {
                Pixel p = shade(w, rec, r);
                cam.vp->drawPixel(p, y, x);
            }
            if (!hit)
                cam.vp->drawPixel(w.backGroundColor, y, x);
        }
    }
    cam.vp->drawImg();

    return 0;
}

void buildScene(World &w)
{
    // sample points on a circle
    double nSamples = 10.0;
    double radius = 10; // ++
    double z = -30;     // --
    for (int i = 1; i <= nSamples; ++i)
    {
        double theta = double(360 * i) / nSamples;
        double x = radius * cos(theta * (PI / 180));
        double y = radius * sin(theta * (PI / 180));
        Sphere *p = new Sphere;
        p->center = Point3(x, y, z - i * 5);
        // p->center = Point3(x, y, z );
        radius += 5;
        z -= 5;
        p->radius = 10;
        p->color = RGBColor((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
        w.objects.push_back(p);
    }
    Plane *plane = new Plane;

    w.objects.push_back(plane);
    Sphere *p = new Sphere;
    p->radius = 1.0f;
    p->center = w.light.pos + Vector3(0.0, 0.0, -2.0);
    p->color = RGBColor(1.0f, 1.0f, 1.0f);
    w.objects.push_back(p);
}

RGBColor shade(World &w, ShadeRec &rec, Ray &r)
{
    Vector3 lightDir = (w.light.pos - rec.hitPoint).hat();
    Vector3 viewDir = -((r.direction).hat());
    Vector3 h = (lightDir + viewDir).hat();
    double cosAlpha = (rec.n * h);
    cosAlpha = MAX(0, cosAlpha);
    cosAlpha = pow(cosAlpha, rec.phongExponent);
    double cosTheta = (rec.n * lightDir);
    cosTheta = MAX(0, cosTheta);

    // with ambient-light
    double pixR = ((rec.diffuseColor.r) * (w.light.AmbientRedIntensity));
    double pixG = ((rec.diffuseColor.g) * (w.light.AmbientGreenIntensity));
    double pixB = ((rec.diffuseColor.b) * (w.light.AmbientBlueIntensity));

    // shadowRay
    Ray sr = Ray(rec.hitPoint + (KEpsilon * w.light.dir), w.light.dir);
    for (int i = w.objects.size() - 1; i > 0; --i)
    {
        double t = DBL_MAX;
        ShadeRec srec;
        if ((i != rec.objectIndex) && w.objects[i]->hit(sr, t, srec))

            return RGBColor(pixR, pixG, pixB);
    }
    pixR += ((rec.diffuseColor.r) * (w.light.RedIntensity) * cosTheta) + ((rec.specularColor.r) * (w.light.RedIntensity) * cosAlpha);
    pixG += ((rec.diffuseColor.g) * (w.light.GreenIntensity) * cosTheta) + ((rec.specularColor.g) * (w.light.GreenIntensity) * cosAlpha);
    pixB += ((rec.diffuseColor.b) * (w.light.BlueIntensity) * cosTheta) + ((rec.specularColor.b) * (w.light.BlueIntensity) * cosAlpha);
    // no ambient-light
    // double pixR = ((rec.diffuseColor.r) * (w.light.RedIntensity) * cosTheta) + ((rec.specularColor.r) * (w.light.RedIntensity) * cosAlpha);
    // double pixG = ((rec.diffuseColor.g) * (w.light.GreenIntensity) * cosTheta) + ((rec.specularColor.g) * (w.light.GreenIntensity) * cosAlpha);
    // double pixB = ((rec.diffuseColor.b) * (w.light.BlueIntensity) * cosTheta) + ((rec.specularColor.b) * (w.light.BlueIntensity) * cosAlpha);

    return RGBColor(pixR, pixG, pixB);
}