#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <iostream>
#include <unordered_map>
#include <string>
#include "Sommet.h"
#include "arete.h"

class Graphe
{
public :

    Graphe(std::string file_name, std::string file_weights);

    void afficher();
    void kruskal();
    ~Graphe();
private :
     //std::unordered_map<int,Sommet> m_sommets;
     std::unordered_map<int, Sommet> m_sommets;
     std::unordered_map<double,Arete> m_aretes;

};

#endif // GRAPHE_H_INCLUDED
