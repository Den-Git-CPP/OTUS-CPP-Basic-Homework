#pragma once
#include"IStatistics.h"

#include <iostream>
#include <vector>
#include <algorithm>


class Prcnt : public IStatistics {
public:
	Prcnt(double a) :m_percnt{ a } {};
	
	void update(double next) override;
	double eval() const override;
	const char* name() const override;
private:

	double m_percnt;
	double m_result;
	void p_vect();
	std::vector<double>m_vect;
};