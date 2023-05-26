// rfa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

extern int Nrand;
extern double gaussAdd;
extern double gaussFac;
extern void initGauss(int nrand);
extern std::vector<double> bm;
extern std::vector<double> ng;
extern double getGaussNumber();
extern void brownianMotionWN(std::vector<double> ng);
extern void brownianMotionMDD(int maxlevel, double sigma);
extern void brownianMotionMDDRec(int index0, int index2, int level, int maxlevel);

extern int Npoints;

int _tmain(int argc, _TCHAR* argv[])
{
	FILE * fd;

    
	/******* Brownian Motion from White Noise ********************
	Npoints = 1200;

	fopen_s(&fd, "GaussNumbers.csv", "w");

    initGauss(4);
    ng.resize(Npoints);

    for(int i=0; i < Npoints; i++)
    {
        ng[i] = getGaussNumber();
        fprintf(fd, "%f", ng[i]);
        if (i < Npoints -1)
        {
	        fprintf(fd, ",");
        }
    }

    fclose(fd);

	fopen_s(&fd,"BrownianMotionWN.csv", "w");

	bm.resize(Npoints);
	brownianMotionWN(ng);

	fprintf(fd, "%f", bm[0]);
    for(int i=1; i < Npoints; i++)
    {
        fprintf(fd, "%f", bm[i]);
        if (i < Npoints -1)
        {
	        fprintf(fd, ",");
        }
    }
    fclose(fd);
	*********************************************************/

    initGauss(4);
	brownianMotionMDD(10, 0.7);

	fopen_s(&fd,"BrownianMotionMDD.csv", "w");

	std::vector<double>::iterator it;

	for (it = bm.begin(); it != bm.end(); it++)
	{
		fprintf(fd, "%f", *it);
		if (std::next(it) != bm.end())
		{
			fprintf(fd, ",");
		}
		printf("%f\n", *it);
	}
	/**********************
	fprintf(fd, "%f", bm[0]);
    for(int i=1; i < 17; i++)
    {
        fprintf(fd, "%f", bm[i]);
        if (i < 17)
        {
	        fprintf(fd, ",");
        }
    }
	**************************/
	fclose(fd);
	printf("Task completed.\n");
	return 0;
}
