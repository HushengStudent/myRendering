// 04Sphere.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "ray.h"

using namespace std;

bool hit_sphere(const vec3& center, float radius, const ray& r)
{
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0f*dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discrimiant = b * b - 4.0f*a*c;
	return (discrimiant > 0.0f);
}

vec3 Color(const ray& r)
{
	if (hit_sphere(vec3(0.0f, 0.0f, -1.0f), 0.5f, r))
	{
		return vec3(1.0f, 0.0f, 0.0f);
	}
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5f*(unit_direction.y() + 1.0f);
	return (1.0f - t)*vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main()
{
	ofstream file;
	file.open("Image.ppm");

	int nx = 200;
	int ny = 100;
	file << "P3\n" << nx << " " << ny << "\n255\n";

	vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
	vec3 horizontal(4.0f, 0.0f, 0.0f);
	vec3 vertical(0.0f, 2.0f, 0.0f);
	vec3 origin(0.0f, 0.0f, 0.0f);

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);

			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			vec3 col = Color(r);

			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);
			file << ir << " " << ig << " " << ib << "\n";
		}
	}
	file.close();
	return 0;
}