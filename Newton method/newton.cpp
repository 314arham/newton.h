#include "newton.h"
namespace solverOpts{
    /*Solver Options namespace.
      h:        absolute tolerance
      dx:       derivative tolerance
      lim:      limit, used for multiple iterating
      maxIter:  maximum iteration*/
	double h = 1e-6, dx = 1e-9;
	int iter = 0, lim = 1, maxIter = 100;
}
double solve(double (*function)(double), double initialGuess, bool reprot = false){
	using namespace solverOpts;
	double diff, x = initialGuess;
	char c;
	do{
		iter++;
		diff = (function(x + 0.5*dx) - function(x - 0.5*dx))/dx;        //calculating derivative
		if(report){                                                     //if report was ture, prints each iteration
			printf("\niteration: %d\t%f", iter, x);
		}
		x -= function(x)/diff;
		if (iter == lim*maxIter){
			printf("\nmaxIter reached. press y for %d more...", maxIter);
			c = getch();
			c == 'y' ? lim++ : printf("\nNot Converged");
		}
	} while(iter <= maxIter*lim && abs(function(x)/diff) >= h);         //stop condition: reaching maxIter or absTol
	return x;
}