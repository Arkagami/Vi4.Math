#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <Windows.h>

FILE *f = fopen("Out.mxn", "w");

float integral1(int n) {
	float ret;
	if (n > 0)
	{
		ret = 1.0 - n * integral1(n - 1);
	}
	else
	{
		ret = 1.0 - (1.0 / M_E);
	}
	fprintf(f,"I%-2d = %.5f\n", n, ret);
	return ret;
}

long double integral1_2(int n) {
	long double ret;
	if (n > 0) 
	{
		ret = 1.0 - n * integral1_2(n - 1);
	}
	else
	{ 
		ret = 1.0 - (1.0 / M_E); 
	}
	fprintf(f,"I%-2d = %.16lf\n", n, ret);
	return ret;
}

long double integrals(int n, int max) {
	if (n > 20)
	{
		if (n < (max - 2))
		{
			return ((1.0 - integrals(n + 1, max)) / (n + 1));
		}
		else
		{
			return (1.0 / (n + 1));
		}
	}
	fprintf(f, "I%-2d = %.16lf\n", n, ((1.0 - integrals(n + 1, max)) / (n + 1)));
	return 1.0;
}

int main()
{
	integral1(20);
	fprintf(f,"------------------------\n");
	integral1_2(20);
	fprintf(f, "------------------------\n");
	integrals(20, 2017);
	fclose(f);
	system("Out.mxn");
    return 0;
}

