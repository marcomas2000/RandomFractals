#include "stdafx.h"
#include "BrownianMotion.h"

std::vector<double> BrownianMotion::m_bm;

std::vector<double>& BrownianMotion::brownianMotionWN(std::vector<double> ng)
{
    m_bm.resize(m_vsize);
    m_bm[0]= 0;
    for(int i=1; i < m_vsize; i++)
    {
        m_bm[i] = m_bm[i-1] + ng[i]/(m_vsize - 1);
    }
	return m_bm;
}

void BrownianMotion::init(int vsize)
{
    m_vsize = vsize;
}

/*************************
std::vector<double>& BrownianMotion::brownianMotionMDD(std::vector<double> ng, int maxlevel, double sigma)
{
	int arraysize = 0;
	for (int i= 0; i <= maxlevel; i++)
	{
		arraysize *= 2;
	}

	for (int i= 1; i <= maxlevel; i++)
	{
		m_delta[i] = sigma * pow(0.5, (i+1)/2);
	}
	
    m_bm.resize(arraysize+1);
	m_bm[0] = 0;
	m_bm[arraysize] = sigma * ng[arraysize];

	return m_bm;
}
**************************/
