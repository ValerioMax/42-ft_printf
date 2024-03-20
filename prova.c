#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include <limits.h>
#include <math.h>

unsigned int cast(int num) {
    unsigned int max_value = UINT_MAX;  // Maximum unsigned int value
    return (num & max_value) + (max_value + 1);
}

int main()
{
	int y = -3;
	printf("%ld\n", LONG_MAX);
	printf("%ld\n", UINT_MAX);
	printf("%f\n", pow(2, 32));
	printf("%d\n", cast(-3));
	printf("%u\n", cast(-3));

	return 0;
}