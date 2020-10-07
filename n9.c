#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main (void){
	
	int n=20,val_rand,i;
	float echantillon[n],somme;
	srand(time(NULL));
		
	for(i=0;i<n/2;i+=2){
		val_rand=rand()%9999001+1000;
		echantillon[i]=val_rand;
		echantillon[i+1]=pow(val_rand,-1);
		
		echantillon[n/2+i]=-echantillon[i];
		echantillon[n/2+i+1]=-echantillon[i+1];
	}
	
	if(n%2)
		echantillon[n-1]=0;
		
	for(i=0;i<n;i++)
		somme+=echantillon[i];
	
	printf("somme sur %d valeurs aléatoires: %20.18f\n",n,somme);
	
	return 0;
}
