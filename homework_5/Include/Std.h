#pragma once
#include <iostream>
#include "IStatistics.h"
#include <cmath>
#include <vector>

class Std : public IStatistics {
public:
	Std() : m_std{ 0 }, m_sum{ 0 }, m_count{ 0 } {}
	void update(double next) override;
	double eval() const override;
	const char* name() const override;
private:
	double m_std,
		m_mean,
		m_sum,
		m_count,
		m_std_val,
		m_disp = 0;
	void p_vect();
	std::vector<double>m_vect_dbl;
};
