#include "graphe.h"
#include <fstream>
#include <unordered_set>
#include <bits/stdc++.h>

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

    /// création des aretes
    size_t taille;
    int nb_criteres;
    std::vector<Arete*> arete;
    fichier >> taille;
    fichier2 >>taille >> nb_criteres;
    for(size_t i=0; i < taille; i++)
    {
        double id1, id2;
        double edge_id; /// indice arete
        double edge_id2; /// indice arete
        float p1,p2; /// poids arete
        fichier >> edge_id >> id1 >> id2;
        fichier2 >>edge_id2 >> p1 >> p2;
        if ( edge_id != edge_id2 )
            exit(17);
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
    ///std::vector<float> arete;

    std::vector<Arete*> ars;
    for(std::unordered_map<double,Arete>::iterator i=m_aretes.begin(); i != m_aretes.end(); i++){

        ars.push_back(&i->second); ///parcourir une map
    }
 ///tri des arretes par ordre croissant
    for(int r=0; r < m_aretes.size()-1; r++){
        for (int i=0;i < ars.size()-1;i++){
            if (ars[i]->getP1() > ars[i+1]->getP1())
            {
                Arete * temp = ars[i];
                ars[i] = ars[i+1];
                ars[i+1] = temp;

            }
        }
    }
    std::ofstream vec("vec.txt");
    std::ofstream poid("poid.txt");
    poid << m_sommets.size()-1 << "   2" << std::endl;
    vec << m_sommets.size() << std::endl;
    for(std::unordered_map<int,Sommet>::iterator i=m_sommets.begin(); i != m_sommets.end(); i++){
        vec << i->second.getId() << "   " << i->second.getX() << "   " << i->second.getY() << std::endl;
    }
    vec << m_sommets.size()-1 << std::endl;
    std::vector<int> cc; /// composantes connexes
    for(int a=0;a<m_sommets.size();a++){
        cc.push_back(a);
    }
    for (int k=0;k<ars.size()-1;k++){
        if (cc[ars[k]->getS2()] != cc[ars[k]->getS1()]){
            vec << ars[k]->getId() <<"   " << ars[k]->getS1() << "   " << ars[k]->getS2() << std::endl;
            poid << ars[k]->getId() <<"   " << ars[k]->getP1() << "   " << ars[k]->getP2() << std::endl;
        }
        cc[ars[k]->getS1()] = cc[ars[k]->getS2()];
    }
    vec.close();
    /*for(int j=0; j<ars.size() ; j++){
        std::cout << ars[j]->getId() <<"  "<< ars[j]->getP1() << "   " <<ars[j]->getP2() <<std::endl;
    }
*/
}

Graphe::~Graphe()
{

}
