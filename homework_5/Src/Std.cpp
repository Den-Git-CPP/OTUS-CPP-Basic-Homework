#include "Std.h"

void Std::p_vect(){
	m_sum = 0;
	m_mean = 0;
	m_disp = 0;
	m_std_val = 0;
	for (int i = 0; i < m_count; ++i){
		m_sum += m_vect_dbl.at(i);
	}
	m_mean = m_sum / m_count;
	for (int i = 0; i < m_count; ++i){
		m_disp += pow(m_vect_dbl.at(i) - m_mean, 2);
	}
	m_std_val = sqrt(m_disp / m_count);
}

void Std::update(double next){
	m_vect_dbl.push_back(next);
	m_count++;
	p_vect();
}

double Std::eval() const{
	return m_std_val;
}
const char* Std::name() const{
	return "Std";
}