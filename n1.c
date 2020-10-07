#include <stdio.h>
#include <float.h>

int main (void){
	float a=1;
	int i=0;
	while(a!=0.0){
		i++;
		a/=2;
	}
	printf("Plus petit flottant détecté est 2^-%d\n",i-1);
	
	double b=1;
	i=0;
	while(b!=0.0){
		i++;
		b/=2;
	}
	printf("Plus petit double détecté est 2^-%d\n",i-1);
	
	
	float c=1,d=2;
	i=0;
	while(d>1){
		c/=2;
		d=1+c;
		i++;
	}
	printf("2^-%d (pas de gradual underflow ici)\n",i);
	
	printf("FLT_TRUE_MIN: %e\n",FLT_TRUE_MIN);
	printf("DBL_TRUE_MIN: %e\n",DBL_TRUE_MIN);
	
	return 0;
}
