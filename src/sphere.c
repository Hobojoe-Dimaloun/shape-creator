/*********************
* Date of creation 25/01/2019
* Authors: Michael J O'Donnell
* Contact: mo14776@bristol.ac.uk
**************************************
* Change History
**************************************/
//
//	File to generate a sphere of radius R in a cube of dimensions xMax, yMax,
//	zMax.
//	sphere Will attempt to maximise the space.
//
//		xx
//	   xxxx
//	   xxxx
//		xx
//
#include <stdio.h>
#include <math.h>

#include "sphere.h"

void sphere(int maxDimensions[3],double radius, FILE *output)
{
	int x_MAX = maxDimensions[0];
	int y_MAX = maxDimensions[1];
	int z_MAX = maxDimensions[2];
	int n = 0;

	fprintf(output,"%d\n%d\n%d\n",x_MAX,y_MAX,z_MAX);

    for(int i=0; i<maxDimensions[0];i++)
    {
        for(int j=0;j<maxDimensions[1];j++)
        {
            for(int k=0; k<maxDimensions[2];k++)
            {
                 if((pow(i-x_MAX/2 ,2)+pow(j-y_MAX/2 ,2)+pow(k-z_MAX/2,2))<=(radius*radius))
                {

                    n++;
                }
            }
        }
    }
     fprintf(output,"%d\n",n);

	for(int k=0; k<maxDimensions[0];k++)
    {
        for(int j=0;j<maxDimensions[1];j++)
        {
            for(int i=0; i<maxDimensions[2];i++)
            {
                if((pow(i-x_MAX/2,2)+pow(j-y_MAX/2,2)+pow(k-z_MAX/2,2))<=(radius*radius))
                {
                    fprintf(output,"%d\t%d\t%d\n",i,j,k);
                }
            }
        }

	}
    printf("n=%d\n",n);
}
