/*********************
* Date of creation 30/09/2019
* Authors: Michael J O'Donnell
* Contact: mo14776@bristol.ac.uk
**************************************
* Change History
**************************************/
//
//	File to generate a triangle
//
#include <stdio.h>
#include <math.h>

#include "triangle.h"

void triangle(int maxDimensions[3],int numOfParticles,double slope,int thickness, FILE *output)
{
	int x_MAX = maxDimensions[0];
	int y_MAX = maxDimensions[1];
	int z_MAX = maxDimensions[2];
	int n = 0;
	printf("Slope = %g\n",slope);


	fprintf(output,"%d\n%d\n%d\n",x_MAX,y_MAX,z_MAX);

    for(int i=0; i<x_MAX;i++)
    {
        for(int j=0;j<y_MAX;j++)
        {
            for(int k=0; k<z_MAX;k++)
            {
                if ( (j<=i*slope && k<thickness && i<=(x_MAX)/2-1) || (j<=(x_MAX-i-1)*slope && k<thickness && i>x_MAX/2-1) )
                {

                    n++;
                }
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
				if ( (j<=i*slope && k<thickness && i<=(x_MAX)/2-1) || (j<=(x_MAX-i-1)*slope && k<thickness && i>x_MAX/2-1) )
                {

                    fprintf(output,"%d\t%d\t%d\n",i,j,k);

                }
            }
        }
    }

    fclose(output);
    printf("n=%d\n",n);
}
