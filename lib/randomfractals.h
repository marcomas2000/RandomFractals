#ifndef RANDOMFRACTALS_H
#define RANDOMFRACTALS_H

#include <math.h>
#include <vector>

/*
 * Samples of rand() to be tasken into getGaussNumber
 */
int Nrand;
/*
 * parameter for linear transformation in getGaussNumber
 */
double gaussAdd;
/*
 * parameter for linear transformation in getGaussNumber
 */
double gaussFac;

/*
 * array of values for Brownian Motion from white noise
 */
std::vector<double> bm;

/*
 * array of values for Gaussian numbers
 */
std::vector<double> ng;

/*
 * size of vector above
 */
int Npoints;
/*
 * array holding standard deviations
 */
std::vector<double> delta;

void initGauss(int nrand);
double getGaussNumber();
void brownianMotionWN(std::vector<double> ng);
void brownianMotionMDD(int maxlevel, double sigma);
void brownianMotionMDDRec(int index0, int index2, int level, int maxlevel);

#endif // RANDOMFRACTALS_H
