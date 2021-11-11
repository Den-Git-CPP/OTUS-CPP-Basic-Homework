
#include "Std.h"

void Std::update(double next)
{
		m_sum += next;
		m_mean = m_sum / m_count;
		m_disp += pow((next - m_mean), 2) / m_count;		 
		m_std_val = sqrt(m_disp);							 
		m_count++;

	}

double Std::eval() const
{
	return m_std_val;
}

const char* Std::name() const
{
	return "Std";
}


