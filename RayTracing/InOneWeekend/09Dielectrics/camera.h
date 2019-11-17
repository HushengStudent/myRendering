#ifndef CAMERAH
#define CAMERAH
//==================================================================================================
// Written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is distributed
// without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication along
// with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==================================================================================================

#include "ray.h"
#include "random.h"

# define M_PI           3.14159265358979323846  /* pi */

class camera {
public:
	camera()
	{
		lower_left_corner = vec3(-2.0f, -1.0f, -1.0f);
		horizontal = vec3(4.0f, 0.0f, 0.0f);
		vertical = vec3(0.0f, 2.0f, 0.0f);
		origin = vec3(0.0f, 0.0f, 0.0f);
	}

	ray getray(float u, float v)
	{
		return ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
	}

	vec3 origin;
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
};

#endif
