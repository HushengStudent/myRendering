// 01OutputAnImage.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream outfile;
	outfile.open("Image.ppm");

	int nx = 200;
	int ny = 100;
	outfile << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			float r = float(i) / float(nx);
			float g = float(j) / float(ny);
			float b = 0.2f;

			int ir = int(255.99f*r);
			int ig = int(255.99f*g);
			int ib = int(255.99f*b);
			outfile << ir << " " << ig << " " << ib << "\n";
		}
	}
	outfile.close();
	return 0;
}

