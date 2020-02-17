#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sphere.h"
#include "triangle.h"
#include "disc.h"
#include "chevron.h"
#include "cuboid.h"

void mosh_dda_io_cmd_read_in(int argc, char *argv[], char **outputFileName, char** shape, int **dimensions, double *externalSlope,double *internalSlope, double *radius,double *offset);
int call_shape_function(FILE *outputFile, char* shape, int *dimensions, double externalSlope, double internalSlope,  double radius,double offset);
int *get_dimensions(int dims[3]);


int main(int argc, char *argv[])
{

	int *dimensions=NULL;
    double radius=1.5;
	double externalSlope=sqrt(3.0);
	double internalSlope=sqrt(3.0);
	double offset=0;
	char *outputFileName=NULL;
	char *shape=NULL;

	printf("Reading inputs\n");
 	mosh_dda_io_cmd_read_in(argc, argv, &outputFileName,&shape, &dimensions, &externalSlope,&internalSlope, &radius,&offset);
	printf("Critical values\n");
	printf("Dimensions: %d %d %d\n",dimensions[0],dimensions[1],dimensions[2]);
	printf("Radius: %g\n",radius);
	printf("External Slope: %g\n",externalSlope);
	printf("Internal Slope: %g\n",internalSlope);
	printf("offset: %g\n",offset);


	printf("Opening file %s\n",outputFileName);
	FILE *outputFile = fopen(outputFileName,"w");
	if(outputFile==NULL)
	return EXIT_FAILURE;

	printf("Finding shape...");
	if(call_shape_function(outputFile, shape, dimensions, externalSlope,internalSlope,  radius,offset) != 0)
	printf("no shape name recognised\nshape provided: %s\n",shape);
	else
	printf("Shape complete\n");
	fflush(outputFile);
	fclose(outputFile);

    return 0;
}


void mosh_dda_io_cmd_read_in(int argc, char *argv[], char **outputFileName, char** shape, int **dimensions, double *externalSlope,double *internalSlope, double *radius,double *offset)
{
	int dims[3];

	for(int i = 1; i <argc; i ++)
	{
		char *input = NULL;
		if((input =strstr(argv[i],"--outputfile="))!=NULL)
		{
			input=strtok(input,"=");
			input=strtok(NULL,"=");
			*outputFileName = input;
		}
		else if((input =strstr(argv[i],"-shape"))!=NULL)
		{
			i++;
			if(i!=argc)
			*shape=argv[i];
		}
		else if((input =strstr(argv[i],"-dimensions"))!=NULL)
		{
			for(int j=0;j<3;j++)
			{
				i++;
				if(i==argc)
				break;

				dims[j]=(int)strtol(argv[i],NULL,10);
			}
		}
		else if((input =strstr(argv[i],"-externalslope"))!=NULL)
		{
			i++;
			if(i!=argc)
			*externalSlope=strtod(argv[i],NULL);
		}
		else if((input =strstr(argv[i],"-internalslope"))!=NULL)
		{
			i++;
			if(i!=argc)
			*internalSlope=strtod(argv[i],NULL);
		}
		else if((input =strstr(argv[i],"-radius"))!=NULL)
		{
			i++;
			if(i!=argc)
			*radius=strtod(argv[i],NULL);
		}
		else if((input =strstr(argv[i],"-offset"))!=NULL)
		{
			i++;
			if(i!=argc)
			*offset=strtod(argv[i],NULL);
		}
	}
	*dimensions = get_dimensions(dims);
}

int call_shape_function(FILE *outputFile, char* shape, int *dimensions, double externalSlope,double internalSlope,  double radius, double offset)
{
	if(strcmp(shape,"sphere") == 0)
	{
		printf("found sphere\n");
		sphere(dimensions,radius,outputFile);
		return 0;
	}
	else if(strcmp(shape,"triangle") == 0)
	{
		printf("found triangle\n");
		triangle(dimensions, externalSlope, outputFile);
		return 0;
	}
	else if(strcmp(shape,"disc") == 0)
	{
		printf("found disc\n");
		disc(dimensions, radius, outputFile);
		return 0;
	}
	else if(strcmp(shape,"chevron") == 0)
	{
		printf("found chevron\n");
		chevron(dimensions, externalSlope,internalSlope,offset, outputFile);
		return 0;
	}
	else if(strcmp(shape,"cuboid") == 0)
	{
		printf("found cuboid\n");
		cuboid(dimensions, outputFile);
		return 0;
	}
	else
	{
		return 1;
	}
}

int *get_dimensions(int dims[3])
{
	int *dimensions = calloc(3,sizeof(*dimensions));
	for(int i=0;i<3;i++)
	dimensions[i]=dims[i];

	return dimensions;
}
