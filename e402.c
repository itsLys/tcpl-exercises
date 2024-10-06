#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>


float atof(const char*);

bool issign(char c)
{
	if (c == '-')
		return 1;
	if (c == '+')
		return 1;
	return 0;
}

int atoe(const char *str)
{
	int expo = 0;
	int sign = 1;
	int i = 0;

	if (str[i] == 'e' || str[i] == 'E')
		i++;
	if (str[i] && issign(str[i]))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && isdigit(str[i]))
		expo = expo * 10 + (str[i++] - '0');

	return expo * sign;


}

int main()
{
	printf("%.8f\n", atof("  +-3.1413333333"));
	printf("%f\n", 123.45e-6);
	printf("%f\n", atof("123.45e-6"));
	printf("%f\n", 123.45e+6);
	printf("%f\n", atof("123.45e+6"));
}


float atof(const char *str)
{
	int i = 0;
	float f = 0.0f;
	double p = 1.0;
	int sign = 1;
	int	exponent;
	double pow(double, double);

	while (str[i] && isspace(str[i]))
		i++;
	while (str[i] && issign(str[i]))
		if (str[i++] == '-')
			sign = -sign;
	while (str[i] && isdigit(str[i]))
		f = (f * 10) + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i] && isdigit(str[i]))
		f = f + (str[i++] - '0') / pow(10.0, (double) p++);
	exponent = atoe(str + i);
	return (f * (float) sign) * pow(10.0, exponent);
}
// ascii to float
// takes a string, return the coresponding float
// while (string is not ended)
// 	convert the decimal part to a float
// 	when a point is reached
// 	while string is not finished
// 		convert the fractional part
//
// 		"3.14" => 3.14
// 		3.1 = 3.0 * 1/10^0
// 		3.00
// 		1
// TODO:
//	Handle sign
//	skip spaces
//	handle sientific notation
//	test limits of float
