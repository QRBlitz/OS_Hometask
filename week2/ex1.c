#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	printf("Size of int = %lu\nMaximum value of int = %i\n\n", sizeof(i), i);
	printf("Size of float = %lu\nMaximum value of float = %f\n\n", sizeof(f), f);
	printf("Size of double = %lu\nMaximum value of double = %f\n\n", sizeof(d), d);
}
