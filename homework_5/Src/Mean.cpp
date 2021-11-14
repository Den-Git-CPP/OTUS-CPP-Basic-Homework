#include"Mean.h"

void Mean::update(double next){
	m_sum += next;
	m_mean = m_sum/static_cast<double>(m_count);
	m_count++;
}

double Mean::eval() const{
	return m_mean;
}

const char* Mean::name() const{
	return "Mean";
}
