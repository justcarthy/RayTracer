// RayTracer.cpp : Defines the entry point for the console application.
//trace, render, populatescene (for now);
#include "Object.h"
#include "Sphere.h"
#include "CImg.h"
//#include "Vector.h"
#include <iostream>
#include <vector>

#define INFINITY 1e8 

using namespace cimg_library;

std::vector<Sphere> objectList;
Vector backgroundColor(0, 0, 0);


Vector traceRay(Vector &rayVec);
float Distance(Vector& a, Vector& b);

int main()
{
	int width = 1366;
	int height = 768;
	float widthFix = 1 / float(width), heightFix = 1 / float(height);
	float fov = 30, aspect = width / float(height);
	
	//TODO angle;
	Vector topLeft(-width/2, height/2, 0);
	Vector bottomRight(width/2, -height/2, 0);
	Vector backgroundColor(255, 255, 255);
	CImg<unsigned char> image(width, height, 1, 3, 1);
	objectList.push_back(Sphere(Vector(0, 0, 0), Vector(255, 0, 0), 100));
	objectList.push_back(Sphere(Vector(500, 0, 400), Vector(0, 255, 0), 100));
	objectList.push_back(Sphere(Vector(-500, 0, 300), Vector(100, 10, 0), 100));

	for (int i = topLeft.x; i <= bottomRight.x; i++) {
		for (int j = topLeft.y; j >= bottomRight.y; j--) {
			Vector rayVector(i, j, 0);
			rayVector = (rayVector - eye);
			rayVector.normalize();
			Vector color = traceRay(rayVector);

			image(i + (width / 2), j - height/2, 1, 0) = color.x;
			image(i + (width / 2), j - height/2, 1, 1) = color.y;
			image(i + (width / 2), j - height/2, 1, 2) = color.z;
		}
	}
	CImgDisplay main_display(image);
	std::cin.ignore();
	return 0;
}


Vector traceRay(Vector &rayVec) {
	float traceClose = INFINITY;
	float tempDist;
	Sphere *hitObject;
	Vector *hitPoint;
	for (Sphere & obj : objectList) {
		if (obj.isHit(rayVec, eye)) {
			hitPoint = &obj.intersectPoint(rayVec, eye);
			tempDist = Distance(*hitPoint, eye);
			if (tempDist < traceClose) {
				hitObject = &obj;
				traceClose = tempDist;
			}
		}
	}
	if (traceClose < INFINITY)
		return hitObject->color;
	else return backgroundColor;
}

float Distance(Vector& a, Vector& b) {
	Vector temp = b - a;
	return (sqrtf(powf(temp.x, 2) + powf(temp.y, 2) + powf(temp.z, 2)));
}

void render();

