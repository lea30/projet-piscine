#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

#include <iostream>
#include <vector>

class Arete
{
public :
    Arete(double m_id, double m_p1, double m_p2, double m_s1, double m_s2 );
    void afficherData();
    float getP1();

private :
    double m_id;
    double m_p1; /// poid 1 de l'arete
    double m_p2; /// poid 2 de l'arete
    double m_s1, m_s2; /// extremites de l'arrete

};

#endif // ARETE_H_INCLUDED
