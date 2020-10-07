#include <stdio.h>
#include <math.h>
#include <fenv.h>

void calc(int arr, char *mode, float val[10]){
	fesetround(arr);
	float somme=0.0;
	
	for(int i=0;i<10;i++)
		somme+=fabs(val[i]);
	printf("somme=%20.18e pour %s\n",somme,mode);
}	

int main (void){
	
	float val[10];
	printf("Entrez 10 valeurs positives\n");
	for(int i=0;i<10;i++)
		scanf("%f",&val[i]);
		
	calc(FE_DOWNWARD, "Round downward",val);
	calc(FE_TONEAREST,"Round to nearest",val);
	calc(FE_UPWARD,"Round upward",val);
	
	return 0;
}
