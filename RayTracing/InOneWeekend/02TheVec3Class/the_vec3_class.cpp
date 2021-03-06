// 02TheVec3Class.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vec3.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream file;
	file.open("Image.ppm");

	int nx = 200;
	int ny = 100;
	file << "P3\n" << nx << " " << ny << "\n255\n";

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			vec3 temp(float(i) / float(nx), float(j) / float(ny), 0.2);
			int r = int(255.99*temp[0]);
			int g = int(255.99*temp[1]);
			int b = int(255.99*temp[2]);

			file << r << " " << g << " " << b << "\n";
		}
	}
	file.close();
	return 0;
}

