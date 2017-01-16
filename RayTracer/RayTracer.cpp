// RayTracer.cpp : Defines the entry point for the console application.
//trace, render, populatescene (for now);
#include "Object.h"
#include "Sphere.h"
#include "CImg.h"
#include "Camera.h"
//#include "Vector.h"
#include <iostream>
#include <vector>

#define INFINITY 1e8 

using namespace cimg_library;

std::vector<Sphere> objectList;
Vector backgroundColor(1, 1, 1);


Vector traceRay(Vector &rayVec, Vector &eye);
float Distance(Vector& a, Vector& b);

int main()
{
	int width = 1366;
	int height = 768;
	float fov = 90;
	float angle = 0;

	CImg<float> image(width, height, 1, 3, 1);
	Camera eye (width, height, fov, angle, Vector());
	objectList.push_back(Sphere(Vector(-10, 0, -10), Vector(1, 0, 0), 0.5));
	objectList.push_back(Sphere(Vector(-5, 5, -10), Vector(0, 1, 0), 0.5));
	objectList.push_back(Sphere(Vector(0, 10, -10), Vector(0, 0, 1), 0.5));
	objectList.push_back(Sphere(Vector(5, 5, -10), Vector(1, 0, 0), 0.5));
	objectList.push_back(Sphere(Vector(10, 0, -10), Vector(0, 1, 0), 0.5));
	objectList.push_back(Sphere(Vector(5, -5, -10), Vector(0, 0, 1), 0.5));
	objectList.push_back(Sphere(Vector(0, -10, -10), Vector(0, 1, 0), 0.5));
	objectList.push_back(Sphere(Vector(-5, -5, -10), Vector(0, 0, 1), 0.5));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			float x = eye.worldX(j);
			
			float y = eye.worldY(i);
			Vector camVector(x, y, -eye.aspectRatio);
			Vector rayVector(eye.camToWorld.matmul(camVector));		
			rayVector.normalize();
			Vector color = traceRay(rayVector, eye.origin);

			image(j, i, 0) = color.x;
			image(j, i, 1) = color.y;
			image(j, i, 2) = color.z;
		}
	}
	CImgDisplay main_display(image);
	std::cin.ignore();
	return 0;
}


Vector traceRay(Vector &rayVec, Vector & eye) {
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



