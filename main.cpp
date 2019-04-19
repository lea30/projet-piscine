#include <iostream>
#include <unordered_map>
#include <string>
#include "Sommet.h"
#include "arete.h"
#include "graphe.h"

using namespace std;

int main()
{
    Graphe g{"broadway.txt", "broadway_weights_0.txt"};
    g.afficher();
    g.kruskal();
    return 0;

}
