#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include"IStatistics.h"

class Prcnt : public IStatistics{
public:
	Prcnt(double a)	: m_percnt{a} {};
	void update(double next) override;
	double eval() const override;
	const char* name() const override;
private:
	std::vector<double>m_vect;
	double	m_percnt;
	double	m_result;
	void	p_vect();
};