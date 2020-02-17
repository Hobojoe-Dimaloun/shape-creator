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

#include "cuboid.h"

void cuboid(int maxDimensions[3], FILE *output)
{
	int x_MAX = maxDimensions[0];
	int y_MAX = maxDimensions[1];
	int z_MAX = maxDimensions[2];
	int n = 0;

	fprintf(output,"%d\n%d\n%d\n",x_MAX,y_MAX,z_MAX);

    for(int i=0; i<x_MAX;i++)
    {
        for(int j=0;j<y_MAX;j++)
        {
            for(int k=0; k<z_MAX;k++)
            {

                n++;
            }
        }
    }
     fprintf(output,"%d\n",n);

	for(int k=0; k<z_MAX;k++)
    {
        for(int j=0;j<y_MAX;j++)
        {
            for(int i=0; i<x_MAX;i++)
            {
                    fprintf(output,"%d\t%d\t%d\n",i,j,k);
            }
        }

	}
    printf("n=%d\n",n);
}
