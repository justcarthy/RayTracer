// RayTracer.cpp : Defines the entry point for the console application.
//trace, render, populatescene (for now);
#include "Object.h"
#include "Sphere.h"
#include "Plane.h"
#include "CImg.h"
#include "Camera.h"
#include "Triangle.h"
#include "Light.h"
#include <iostream>
#include <vector>

#define INFINITY 1e8 

using namespace cimg_library;

std::vector<Object*> objectList;
std::vector<Light*> lightList;

Vector backgroundColor(0, 0, 0);
Vector ambientLight(0.1, 0.1, 0.1);


Vector traceRay(Vector &rayVec, Vector &eye);
Vector shade(Object* obj, Vector* point, Vector* Normal);

int main()
{
	int width = 640;
	int height = 480;
	float fov = 65;
	float angle = 0;

	CImg<float> image(width, height, 1, 3, 1);
	Camera eye (width, height, fov, angle, Vector(0,0,1));
	lightList.push_back(new Light(Vector(0, 10, 0), Vector(1, 1, 1)));
	objectList.push_back(new Sphere(Vector(5, 0, -15), 0.5, Vector(0.7, 0.2, 0.5), 0, DIFFUSED));
	objectList.push_back(new Triangle(Vector(0, 5, -11), Vector(-5, 0, -11), Vector(5, 0, -11), Vector(0, 0, 1), Vector(1, 0, 0), 0, DIFFUSED));
	objectList.push_back(new Plane(Vector(0, 0, -20), Vector(0, 0, 1), Vector(1, 1, 0), 0, DIFFUSED));
	objectList.push_back(new Plane(Vector(0, -7, 0), Vector(0, 1, 0), Vector(0, 1, 0), 0, DIFFUSED));
	objectList.push_back(new Plane(Vector(0, 7, 0), Vector(0, -1, 0), Vector(0, 1, 1), 0, DIFFUSED));
	objectList.push_back(new Plane(Vector(-7, 0, 0), Vector(1, 0, 0), Vector(1, 0, 0), 0, DIFFUSED));
	objectList.push_back(new Plane(Vector(7, 0, 0), Vector(-1, 0, 0), Vector(0, 0, 1), 0, DIFFUSED));
	

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			float x = eye.worldX(j);
			float y = eye.worldY(i);
			Vector camVector(x, y, -1);
			Vector rayVector  = eye.camToWorld.matmul(camVector);		
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
	Object *hitObject;
	Vector *tempPoint, *hitPoint, *hitNormal;
	for (Object* obj : objectList) {
		if (obj->isHit(rayVec, eye)) {
			tempPoint = &obj->intersectPoints(rayVec, eye);
			tempDist = tempPoint->Distance(eye);
			if (tempDist < traceClose) {
				hitObject = obj;
				hitPoint = tempPoint;
				hitNormal = &hitObject->normalPoint(*hitPoint);
				traceClose = tempDist;
			}
		}
	}
	if (traceClose < INFINITY)
		return shade(hitObject, hitPoint, hitNormal);
	else return backgroundColor;
}



Vector shade(Object* obj, Vector* point, Vector* Normal) {
	return ambientLight
}



