#include "Sommet.h"
#include <iostream>
#include <vector>

Sommet::Sommet(int id, int x, int y):
    m_id(id), m_x(x), m_y(y)
{

}

Sommet::~Sommet()
{

}

void Sommet::ajoutVoisin(Sommet& voisin)
{
    m_voisins.push_back(&voisin);
}

void Sommet::afficherData()
{
    std::cout << "    " << m_id << " : (x,y)=(" << m_x << "," << m_y << ")\n";
}

void Sommet::afficherVoisins()
{
    std::cout << "   voisins :\n";
    for(Sommet* voisin : m_voisins)
        voisin->afficherData();
}

std::vector<int> Sommet::idVoisins() const
{
    std::vector<int> ids;
    for(Sommet* voisin : m_voisins)
        ids.push_back(voisin->id());

    return ids;
}
