#include "stdafx.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "randomfractals.h"


void initGauss(int nrand)
{
    srand((unsigned)time( NULL ));
    Nrand = nrand;
    gaussAdd = sqrt(3.0 * Nrand);
    gaussFac = 2 * gaussAdd / (Nrand * RAND_MAX);
}

double getGaussNumber()
{
    int i;
    double sum = 0;

    for(i=0; i < Nrand; i++)
    {
        sum = sum + rand();
    }
    //printf("%f-%f\n", gaussAdd, gaussFac);
    return((gaussFac * sum) - gaussAdd);
}

void brownianMotionWN(std::vector<double> ng)
{
    bm[0]= 0;
    for(int i=1; i < Npoints; i++)
    {
        bm[i] = bm[i-1] + ng[i]/(Npoints - 1);
    }
}


void brownianMotionMDD(int maxlevel, double sigma)
{

	int arraysize = 1;
	if (maxlevel > 0)
	{
		for (int i= 1; i <= maxlevel; i++)
		{
			arraysize *= 2;
		}
	}

	delta.resize(maxlevel + 1);

	for (int i= 1; i <= maxlevel; i++)
	{
		delta[i] = sigma * pow(0.5, (i+1)/2);
	    //printf("delta[i] = %f\n", delta[i]);
	}
	
    bm.resize(arraysize + 1);
	bm[0] = 0;
	bm[arraysize] = sigma * getGaussNumber();
	brownianMotionMDDRec(0, arraysize, 1, maxlevel);
}

void brownianMotionMDDRec(int index0, int index2, int level, int maxlevel)
{
	int index1;
	index1 = (index0 + index2) / 2;
	bm[index1] = 0.5 * (bm[index0] + bm[index2]) + delta[level] * getGaussNumber();
    //printf("Level: %d index0: %d index2: %d index1: %d bm[index1] = %f\n", level, index0, index2, index1);
	if (level < maxlevel)
	{
		brownianMotionMDDRec(index0, index1, level+1, maxlevel);
		brownianMotionMDDRec(index1, index2, level+1, maxlevel);
	}
}

