#include <iostream>
#include <vector>
#include "arete.h"

Arete::Arete(double id, double p1, double p2, double s1, double s2 )
{
    m_id = id;
    m_p1 = p1;
    m_p2 = p2;
    m_s1 = s1;
    m_s2 = s2;
}

void Arete::afficherData()
{
    std::cout << m_id <<"  " << m_p1 << "  "<< m_p2 <<std::endl;
}

float Arete::getP1()
{
    return m_p1;
}
