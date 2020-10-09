#include <iostream>
#include <cmath>
#include <pybind11/pybind11.h>

using namespace std;

float angle(float x1, float y1, float x2, float y2)
{
	//error if zero vector length
	float vec1_norm = sqrt((x1 * x1) + (y1 * y1));
	float vec2_norm = sqrt((x2 * x2) + (y2 * y2));

	if(fabs(vec1_norm) < 0.001) return 0.0f;
	if(fabs(vec2_norm) < 0.001) return 0.0f;

	float vec1_dot_vec2 = (x1 * x2) + (y1 * y2);

	if(vec1_dot_vec2 >= 1.0f) {
		return 0.0f;
	} else if(vec1_dot_vec2 <= -1.0f) {
		return M_PI;
	} else  {
		return acos(vec1_dot_vec2 / (vec1_norm * vec2_norm));
	}
}

PYBIND11_MODULE(_vector, m) {
	m.doc() = "pybind11 example code";
	m.def("angle", &angle, "calculate angle (radian) between two vectors");
}
