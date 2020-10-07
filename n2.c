#include <stdio.h>
#include <float.h>

int main (void){
	float a=FLT_TRUE_MIN;
	while(a+1==1)
		a*=2;
	a/=2;
	printf("Plus grand flottant x tq 1=x+1: %e\n",a);
	
	double b=DBL_TRUE_MIN;
	while(b+1==1)
		b*=2;
	b/=2;
	printf("Plus grand double x tq 1=x+1: %e\n",b);
	
	printf("\nVérification: autre côté de la borne:\n");
	
	a=1;
	while(a+1!=1)
		a/=2;
	a*=2;
	printf("Plus petit flottant x tq 1!=x+1: %e\n",a);
	
	b=1;
	while(b+1!=1)
		b/=2;
	b*=2;
	printf("Plus petit double x tq 1!=x+1: %e\n",b);
	
	return 0;
}
