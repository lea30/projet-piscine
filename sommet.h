#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <iostream>
#include <vector>

class Sommet
{
public:
    Sommet(int id, int x, int y);
    ~Sommet();

    /// ajoute un voisin dans le vecteur m_voisins
    void ajoutVoisin(Sommet& voisin);
    /// affiche les données propres au sommet
    void afficherData();
    /// affiche les donnes des sommets voisins
    void afficherVoisins();
    /// retourne l'id du sommet
    int id() const {return m_id;}
    /// retourne l'id de ses voisins
    std::vector<int> idVoisins() const;
    /// retourne le degré du sommet
    int getDegre() {return m_voisins.size();}
    int getId();
    int getX();
    int getY();

private:
    /// contient la liste de voisins
    std::vector<Sommet*> m_voisins;
    /// données du sommet
    int m_id;
    int m_x;
    int m_y;
};

#endif // SOMMET_H_INCLUDED
