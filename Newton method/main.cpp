#include "newton.h"
#include <stdio.h>
#include <math.h>
#include <conio.h>
double function(double x){          //notation of x^2 - 4 = 0 equation
	return pow(x, 2) - 4;
}
int main(){
	printf("%f", solve(function, 8, true));
}