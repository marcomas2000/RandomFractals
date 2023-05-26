#ifndef BROWNIANMOTION_H
#define BROWNIANMOTION_H

#include <math.h>
#include <vector>

class BrownianMotion
{
public:
    BrownianMotion();
	std::vector<double>& brownianMotionWN(std::vector<double> ng);
	//std::vector<double>& brownianMotionMDD(std::vector<double> ng, int maxlevel, double sigma);
    void init(int nrand);
private:
	static std::vector<double> m_bm;
	int m_vsize;
	std::vector<double> m_delta;
};

#endif // BROWNIANMOTION_H
