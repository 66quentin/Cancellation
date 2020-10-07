#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>


void calc(int arr, char *mode){
	fesetround(arr);
	printf("\nMode d'arrondi: %s\n",mode);
	
	float a=1;
	int i=0;
	
	while(a!=0.0){
		i++;
		a/=2;
	}
	printf("Plus petit flottant détecté est 2^-%d\n",i-1);
	
	a=FLT_TRUE_MIN;
	while(a+1==1)
		a*=2;
	a/=2;
	printf("Plus grand flottant x tq 1=x+1: %20.18e\n",a);
	
	/*Pour décortiquer round upward:
	i=0;
	while(a!=0.0 && i<200){
		i++;
		a/=2;
		printf("Plus petit flottant détecté est %20.18e\n",a);
	}
	
	a=FLT_TRUE_MIN;
	while(1==a+1)
		a*=2;
	a/=2;
	printf("a=%20.18e\n\n",a);*/
}

int main (void){

	calc(FE_DOWNWARD, "Round downward");
	calc(FE_TONEAREST,"Round to nearest");
	calc(FE_TOWARDZERO,"Round toward zero");
	calc(FE_UPWARD,"Round upward");
	
	return 0;
}
