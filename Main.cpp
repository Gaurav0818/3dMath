#include <iostream>

#include "3dMath.h"


int main()
{
	vec3 a(1, 2, 0);
	vec3 b(-3, 5, 0);

	vec3 c = a + b;

	std::cout << a.length() << " ||  "<< b.length() << " || " << c.length();

	return 0;
}