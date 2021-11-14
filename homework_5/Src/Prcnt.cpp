#include "Prcnt.h"

void Prcnt::p_vect(){
	sort(m_vect.begin(), m_vect.end());
	double min2 = m_vect.at(0);
	double max2 = m_vect.at(m_vect.size() - 1);
	m_result = ((max2 - min2) * (m_percnt / 100)) + min2;
}

void Prcnt::update(double next){
	m_vect.push_back(double(next));
	p_vect();
}

double Prcnt::eval() const{
	return m_result;
}
const char* Prcnt::name() const{
	return "Prcnt";
}
