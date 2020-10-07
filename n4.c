#include <stdio.h>
#include <math.h>

int main (void){
	float a=0.1;
	int i=0,b;
	printf("a=%e\n",a);
	while(isnormal(a)){
		a/=2;
		i++;
	}
	printf("i=%d et a=%e\n",i,a);
	
	b=(149-i)/2;
	for(int j=0;j<b;j++){
		a/=2;
		i++;
	}
	
	while(i>0){
		a*=2;
		i--;
	}
	printf("i=%d et a=%e\n",i,a);
	
	return 0;
}
