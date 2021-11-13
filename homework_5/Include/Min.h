#pragma once
#include <iostream>
#include "IStatistics.h"
#include <limits>


class Min : public IStatistics {
public:
	Min() : m_min{ std::numeric_limits<double>::min() } {}

	void update(double next) override;
	double eval() const override;
	const char* name() const override;

private:
	double m_min;
};