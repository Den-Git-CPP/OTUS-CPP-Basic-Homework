#pragma once
#include <iostream>
#include "IStatistics.h"

class Mean : public IStatistics {
public:
	Mean() : m_mean{0}, m_sum{0}, m_count{1}{}
	void update(double next) override;
	double eval() const override;
	const char* name() const override;

private:
	double m_mean, m_sum, m_count;
};
