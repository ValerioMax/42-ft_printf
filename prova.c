#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void print_int(int num_args, ...)
{
	int x;
	va_list args;

	va_start(args, num_args); //args e l'ultimo parametro prima dei ...
	for (int i = 0; i < num_args; i++)
	{
		x = va_arg(args, int); //prende l'argomento successivo e lo considera del tipo specificato (int)
		printf("x: %d\n", x);
	}
	va_end(args);
}

int max(int num_args, ...)
{
	int x;
	int max = 0;
	va_list args;

	va_start(args, num_args); //args e l'ultimo parametro prima dei ...
	for (int i = 0; i < num_args; i++)
	{
		x = va_arg(args, int); //prende l'argomento successivo e lo considera del tipo specificato (int)
		if (i == 0) max = x;
		else if (x > max) max = x;
	}
	va_end(args);
	return (max);
}

void print(char	*placeholders, ...)
{
	int num_args = strlen(placeholders);
	va_list args;
	
	va_start(args, placeholders);
	for (int i = 0; i < num_args; i++)
	{
		if (placeholders[i] == 'd')
		{
			int x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if (placeholders[i] == 'f')
		{
			double x = va_arg(args, double);
			printf("%f\n", x);
		}
	}
	va_end(args);
}

int main()
{
	//print_int(4, 1, 2, 3, 5);
	//printf("%d\n", max(4, 1, 2, 3, 5));
	//print("ddfdf", 2, 3, 4.4, 5, 7.6);
	int a;
	int b;
	int c;
	
	
	scanf("%i", &a);
	scanf("%i", &b);
	scanf("%i", &c);
	printf("%d, %d, %d\n", a, b, c);

	return 0;
}