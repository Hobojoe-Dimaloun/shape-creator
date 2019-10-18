#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sphere.h"
#include "triangle.h"
#include "disc.h"
int main(int argc, char *argv[])
{
   // printf("Begin\n");

    FILE *sphere1=fopen("../bin/spherepositions.txt","w");
	FILE *sphere2;
//	FILE *disc1=fopen("../bin/discpositions.txt","w");
//	FILE *disc2=fopen("../bin/discpositions2.txt","w");


	int maxDimensions[3] = {1,1,1};
    int numOfParticles=1;
    double radius=1.5;
	int distance = 30;
	double thickness = 5;
	if(argc>1)
	sphere2=fopen(argv[1],"w");
	if(argc>2)
    maxDimensions[0]=strtol(argv[2],NULL,10);
	if(argc>3)
    maxDimensions[1]=strtol(argv[3],NULL,10);
	if(argc>4)
    maxDimensions[2]=strtol(argv[4],NULL,10);
	if(argc>5)
	radius=strtod(argv[5],NULL);
	if(argc>6)
	numOfParticles=strtod(argv[6],NULL);
	if(argc>7)
	distance=strtod(argv[7],NULL);

	//void sphere(int radius, int maxDimensions[3],int distance,int numOfParticles, FILE *output, FILE *output2);
	//sphere(radius,maxDimensions,distance, numOfParticles, sphere1, sphere2);
//	disc(radius, thickness,maxDimensions,distance, numOfParticles, disc1, disc2);

	double slope=sqrt(3.0);
 	triangle(maxDimensions, numOfParticles, slope, thickness, sphere1);
    return 0;
}
