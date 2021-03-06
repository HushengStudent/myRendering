// 06Antialiasing.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <random>
#include "sphere.h"
#include "hitable_list.h"
#include "camera.h"

using namespace std;

vec3 Color(const ray& r, hitable *world)
{
	hit_record rec;
	if (world->hit(r, 0.0, FLT_MAX, rec))
	{
		return 0.5f*vec3(rec.normal.x() + 1.0f, rec.normal.y() + 1.0f, rec.normal.z() + 1.0f);
	}
	else
	{
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5f*(unit_direction.y() + 1.0f);
		return (1.0f - t)*vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
	}
}

int main()
{
	ofstream file;
	file.open("Image.ppm");

	int nx = 200;
	int ny = 100;
	int ns = 100;//采样次数;
	file << "P3\n" << nx << " " << ny << "\n255\n";

	hitable *list[2];
	list[0] = new sphere(vec3(0.0f, 0.0f, -1.0f), 0.5f, NULL);
	list[1] = new sphere(vec3(0.0f, -100.5f, -1.0f), 100.0f, NULL);
	hitable *world = new hitable_list(list, 2);

	camera cam;

	default_random_engine reng;
	uniform_real_distribution<float> uni_dist(0.0f, 1.0f);

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			vec3 col(0.0f, 0.0f, 0.0f);
			for (int s = 0; s < ns; s++)
			{
				float u = float(i + uni_dist(reng)) / float(nx);
				float v = float(j + uni_dist(reng)) / float(ny);
				ray r = cam.getray(u, v);
				col += Color(r, world);
			}
			col /= float(ns);

			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);
			file << ir << " " << ig << " " << ib << "\n";
		}
	}
	file.close();
	return 0;
}