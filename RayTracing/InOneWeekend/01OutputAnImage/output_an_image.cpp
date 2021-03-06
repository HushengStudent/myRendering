// 01OutputAnImage.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
			float _r = float(i) / float(nx);//r++;
			float _g = float(j) / float(ny);//g--;
			float _b = 0.2f;

			int r = int(255.99f*_r);
			int g = int(255.99f*_g);
			int b = int(255.99f*_b);

			file << r << " " << g << " " << b << "\n";
		}
	}
	file.close();
	return 0;
}

