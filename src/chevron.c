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

#include "chevron.h"

void chevron(int maxDimensions[3],double externalSlope,double internalSlope, double offset, FILE *output)
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
                if ( ( (j<=i*externalSlope && k<z_MAX && i<=(x_MAX)/2-1) && (j>=(i-offset)*internalSlope) )|| ( (j<=(x_MAX-i-1)*externalSlope && k<z_MAX && i>x_MAX/2-1) && (j>=(x_MAX-i-1-offset)*internalSlope) ) )
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
				if ( ( (j<=i*externalSlope && k<z_MAX && i<=(x_MAX)/2-1) && (j>=(i-offset)*internalSlope) )|| ( (j<=(x_MAX-i-1)*externalSlope && k<z_MAX && i>x_MAX/2-1) && (j>=(x_MAX-i-1-offset)*internalSlope) ) )
                {

                    fprintf(output,"%d\t%d\t%d\n",i,j,k);

                }
            }
        }
    }

    printf("n=%d\n",n);
}
