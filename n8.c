#include <stdio.h>
#include <math.h>
#include <time.h>


int main (void){

	//Noms des fichiers
	char fichier1[64];
	time_t timer;
	struct tm* tm_info;
	timer = time(NULL);
	tm_info = localtime(&timer);
	strftime(fichier1, 37, "./data/%Y-%m-%d %H:%M:%S.dat", tm_info);
	
	//Variables dans les boucles
	float val[3],somme;
	
	FILE *f1 = fopen(fichier1, "w");
	fprintf(f1,"# exposant rounded correct\n");
	for(int i=1;i<7;i++){
		somme=0;
		val[0]=pow(10,i);
		val[1]=pow(10,-i);
		val[2]=-pow(10,i);
		for(int i=0;i<3;i++)
			somme+=val[i];
		
		fprintf(f1, "%d %20.18f %20.18lf\n",i,somme,pow(10,-i));
		
	}
	fclose(f1);
	FILE *gnuplot = popen("gnuplot -persistent", "w");
	fprintf(gnuplot, "set title 'Cancellation'\nset xrange[1:7]\nset logscale y 10\n");	
	fprintf(gnuplot, "plot '%s' using 1:2 w lp title 'rounded', \\\n'' using 1:3 title 'correct' with lp\nset xlabel 'i'\n",fichier1);
	
	
	return 0;
}
