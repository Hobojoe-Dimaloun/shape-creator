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

void sphere(double radius, int maxDimensions[3],int distance,int numOfParticles, FILE *output, FILE *output2)
{
	int x_MAX = maxDimensions[0];
	int y_MAX = maxDimensions[1];
	int z_MAX = maxDimensions[2];
	int n = 0;

	fprintf(output,"%d\n%d\n%d\n",x_MAX+0*(numOfParticles-1),y_MAX+0*(numOfParticles-1),z_MAX+distance*(numOfParticles-1));
	fprintf(output2,"%d\n%d\n%d\n",x_MAX,y_MAX,z_MAX);

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
     fprintf(output,"%d\n",n*numOfParticles);
	 fprintf(output2,"%d\n",n);
	 fprintf(output2,"%d\n",numOfParticles);

	 for(int z = 0; z < numOfParticles; z++)
	 {
	    for(int k=0; k<maxDimensions[0];k++)
	    {
	        for(int j=0;j<maxDimensions[1];j++)
	        {
	            for(int i=0; i<maxDimensions[2];i++)
	            {
	                if((pow(i-x_MAX/2,2)+pow(j-y_MAX/2,2)+pow(k-z_MAX/2,2))<=(radius*radius))
	                {
	                    fprintf(output,"%d\t%d\t%d\n",i+z*0,j+z*0,k+z*distance);
						if(z==0)
						{
							fprintf(output2,"%d\t%d\t%d\n",i+z*0,j+z*0,k+z*distance);

						}
	                }
	            }
	        }
	    }
	}
    fclose(output);
    printf("n=%d\n",n);
}
