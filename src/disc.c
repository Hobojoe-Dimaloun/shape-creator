/*********************
* Date of creation 25/01/2019
* Authors: Michael J O'Donnell
* Contact: mo14776@bristol.ac.uk
**************************************
* Change History
**************************************/
//
//	File to generate a disc of radius R in a cube of dimensions xMax, yMax,
//	zMax.
//	disc Will attempt to maximise the space in it's plane.
//
//	   xxxxxx
//	   xxxxxx
//
#include <stdio.h>
#include <math.h>

#include "disc.h"

void disc(int maxDimensions[3],double radius, FILE *output)
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
                if( (pow(i-x_MAX/2 ,2)+pow(j-y_MAX/2 ,2))<=(radius*radius) && k < z_MAX)
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
				if( (pow(i-x_MAX/2 ,2)+pow(j-y_MAX/2 ,2))<=(radius*radius) && k < z_MAX)
				{
                    fprintf(output,"%d\t%d\t%d\n",i,j,k);
                }
            }
        }
    }

	printf("n=%d\n",n);
}
