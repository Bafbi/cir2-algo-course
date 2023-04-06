#include <iostream>
#include <vector>
#include <string>
#include <climits>

const int TAILLEDUGRAPHE = 6;
const int INFINI = INT_MAX;

std::vector<std::string> vecSommets;
int arcs[TAILLEDUGRAPHE][TAILLEDUGRAPHE];
int cheminCourt[TAILLEDUGRAPHE][TAILLEDUGRAPHE];
int pointChemin[TAILLEDUGRAPHE][TAILLEDUGRAPHE];

// implement << operator for int[TAILLEDUGRAPHE][TAILLEDUGRAPHE]
std::ostream &operator<<(std::ostream &os, int (&arr)[TAILLEDUGRAPHE][TAILLEDUGRAPHE])
{
    for (int i = 0; i < TAILLEDUGRAPHE; i++)
    {
        for (int j = 0; j < TAILLEDUGRAPHE; j++)
        {
            // don't show when infinite
            if (arr[i][j] == INFINI)
            {
                os << "INFINI"
                   << "\t";
            }
            else
            {
                os << arr[i][j] << "\t";
            }
        }
        os << std::endl;
    }
    return os;
}

/*
Algorithme Floyd-Warshall (Partie Principale)
Pour un sommetIntermédiaire d’indice 1 à TAILLEDUGRAPHE Faire
Pour un origine d’indice 1 à TAILLEDUGRAPHE Faire
Pour une destination d’indice 1 à TAILLEDUGRAPHE Faire
Si cheminCourt[origine][sommetIntermédiaire] +
cheminCourt[sommetIntermédiaire][destination]
< cheminCourt[origine][destination]
Alors
cheminCourt[origine][destination] =
cheminCourt[origine][sommetIntermédiaire] +
cheminCourt[sommetIntermédiaire][destination];
pointChemin[origine][destination] = sommetIntermédiaire;
Fin Si
Fin Pour
Fin Pour
Fin Pour
*/
void floydWarshall()
{
    for (int k = 0; k < TAILLEDUGRAPHE; k++)
    {
        for (int i = 0; i < TAILLEDUGRAPHE; i++)
        {
            for (int j = 0; j < TAILLEDUGRAPHE; j++)
            {
                if (arcs[i][k] != INFINI && arcs[k][j] != INFINI)
                {
                    if (arcs[i][j] > arcs[i][k] + arcs[k][j])
                    {
                        arcs[i][j] = arcs[i][k] + arcs[k][j];
                        pointChemin[i][j] = pointChemin[i][k];
                    }
                }
            }
        }
    }
}

// void afficherChemin(int sommet1, int sommet2, bool &premier)
// {
//     int suivant = pointChemin[sommet1][sommet2];
//     if (suivant == -1 || sommet1 == sommet2 || suivant == sommet1 || suivant == sommet2)
//         return;
//     afficherChemin(sommet1, suivant, premier);
//     if (premier)
//     {
//         std::cout << " \t\t par ";
//         premier = false;
//     }
//     else
//     {
//         std::cout << " et ";
//     }
//     std::cout << vecSommets[suivant];
//     afficherChemin(suivant, sommet2, premier);
// }

void afficherChemin(int sommet1, int sommet2)
{
    int suivant = pointChemin[sommet1][sommet2];
    if (suivant == -1 || sommet1 == sommet2 || suivant == sommet1 || suivant == sommet2)
        return;
    afficherChemin(sommet1, suivant);
    std::cout << vecSommets[suivant] << " ";
    afficherChemin(suivant, sommet2);
}

int main(int argc, char const *argv[])
{
    vecSommets.push_back("Lille");
    vecSommets.push_back("Lens");
    vecSommets.push_back("Paris");
    vecSommets.push_back("Bourges");
    vecSommets.push_back("Clermont-Ferrand");
    vecSommets.push_back("Montpellier");

    for (int i = 0; i < TAILLEDUGRAPHE; i++)
    {
        for (int j = 0; j < TAILLEDUGRAPHE; j++)
        {
            arcs[i][j] = INFINI;
            cheminCourt[i][j] = INFINI;
            pointChemin[i][j] = INFINI;
        }
    }

    arcs[0][1] = 40;
    arcs[0][2] = 230;
    arcs[1][2] = 200;
    arcs[2][3] = 250;
    arcs[2][4] = 425;
    arcs[3][4] = 190;
    arcs[4][5] = 300;

    for (int i = 0; i < TAILLEDUGRAPHE; i++)
    {
        for (int j = 0; j < TAILLEDUGRAPHE; j++)
        {
            if (arcs[i][j] != INFINI)
            {
                pointChemin[i][j] = j;
            }
            else
            {
                pointChemin[i][j] = -1;
            }
        }
    }

    std::cout << pointChemin << std::endl;

    floydWarshall();

    std::cout << arcs << std::endl;

    std::cout << "Chemin le plus court de Lille à Montpellier : " << std::endl;
    std::cout << vecSommets[0] << " ";
    afficherChemin(0, 5);
    std::cout << vecSommets[5] << std::endl;

    return 0;
}
