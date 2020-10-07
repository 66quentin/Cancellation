#include <math.h>
#include <stdio.h>

int main (void) {
	int n=1;
	double x=1.0,h=1.0,deriv=cos(x),diffquo,error;
	
	FILE *gnuplot = popen("gnuplot -persistent", "w");	
	fprintf(gnuplot, "set title 'Erreur dérivation'\nset key autotitle columnhead\nset logscale x 10\nset logscale y 10\nset yrange[10e-10:1]\nset xrange[10e-20:1]\nplot '-'\n");
	
	while(n<=20) {
		h=h/10;
		diffquo=(sin(x+h)-sin(x))/h;
		error=fabs(deriv-diffquo);
		fprintf(gnuplot, "%5.1e %13.6e \n",h,error);
		n++;
	}
	return 0;
}
