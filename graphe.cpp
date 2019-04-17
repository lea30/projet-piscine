#include "graphe.h"
#include <fstream>
#include <unordered_set>

Graphe::Graphe(std::string nom_fichier , std::string file_weights)
{
    /// ouverture des fichier
    std::ifstream fichier(nom_fichier);
    std::ifstream fichier2(file_weights);
    /// chargement des sommets
    size_t ordre;
    fichier >> ordre;
    for(size_t i=0; i < ordre; i++)
    {
        int id, x, y;
        fichier >> id >> x >> y;
        m_sommets.emplace(id, Sommet(id, x, y));
    }

    /// création des arrêtes
    size_t taille;
    int nb_criteres;
    std::vector<Arete*> arete;
    fichier >> taille;
    fichier2 >>taille >> nb_criteres;
    for(size_t i=0; i < taille; i++)
    {
        double id1, id2;
        double edge_id; /// indice arete
        float p1,p2; /// poids arete
        fichier >> id1 >> id2;
       fichier2 >>edge_id >> p1 >> p2;
        (m_sommets.find(id1))->second.ajoutVoisin(m_sommets.find(id2)->second);
        (m_sommets.find(id2))->second.ajoutVoisin(m_sommets.find(id1)->second);
         m_aretes.emplace(edge_id, Arete(edge_id,p1,p2,id1,id2));
    }

    /// fermeture du fichier
    fichier.close();








}

void Graphe::afficher()
{
    for(std::unordered_map<double,Arete>::iterator i=m_aretes.begin(); i != m_aretes.end(); i++){
        i->second.afficherData();
    }
}

void Graphe::kruskal() ///pour p1
{
    std::vector<float> arete;
    for(std::unordered_map<double,Arete>::iterator i=m_aretes.begin(); i != m_aretes.end(); i++){

}

Graphe::~Graphe()
{

}
