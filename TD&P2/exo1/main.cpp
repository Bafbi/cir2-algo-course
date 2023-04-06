#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <ctime>
#include <chrono>

/*
Algorithme RechercheDichotomique(
    Entrées : vecteur, valeurRecherchee, tailleVecteur ;
    Sortie : index de l’élément trouvé, -1 sinon.)

    min = 1;
    max = tailleVecteur;
    Tant Que min < max Faire
        mid = (min + max) / 2;
        Si vecteur[mid] < valeurRecherchee Alors
            min = mid + 1;
            Sinon
            max = mid;
        Fin Si
    Fin Tant Que
    Si vecteur[min] == valeurRecherchee Alors
        Retourner min;
        Sinon
        Retourner -1;
    Fin Si
Fin Algorithme RechercheDichotomique
*/

int rechercheDichotomique(int vecteur[], int valeurRecherchee, int tailleVecteur)
{
    int min = 0;
    int max = tailleVecteur - 1;
    int mid;

    while (min < max)
    {
        mid = (min + max) / 2;
        if (vecteur[mid] < valeurRecherchee)
        {
            min = mid + 1;
        }
        else
        {
            max = mid;
        }
    }

    if (vecteur[min] == valeurRecherchee)
    {
        return min;
    }
    else
    {
        return -1;
    }
}

template <typename T>
int rechercheDichotomiqueAdvanced(const std::vector<T> &vecteur, const T valeurRecherchee)
{
    auto min = vecteur.begin();
    auto max = vecteur.end() - 1;
    auto mid = vecteur.begin() + std::distance(vecteur.begin(), vecteur.end()) / 2;
    while (min < max)
    {
        if (*mid < valeurRecherchee)
        {
            min = std::next(mid);
        }

        else
        {
            max = mid;
        }
        mid = min + std::distance(min, max) / 2;
    }

    if (*min == valeurRecherchee)
    {
        return std::distance(vecteur.begin(), min);
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    std::srand(std::time(nullptr));

    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds, mean;
    const size_t loop = 1000, size = 1000000;

    int valeurRecherchee = 50;
    

    int vecteur[size];

    for (size_t i = 0; i < loop; i++)
    {
        for (int i = 0; i < size; i++)
        {
            vecteur[i] = std::rand() % 500;
        }
        std::sort(vecteur, vecteur + 1000);

        // time the function
        start = std::chrono::system_clock::now();
        int index = rechercheDichotomique(vecteur, valeurRecherchee, size);
        end = std::chrono::system_clock::now();

        elapsed_seconds = end - start;
        mean += elapsed_seconds;
    }

    std::cout << "Time elapsed: " << mean / loop << std::endl;
    


    // std::vector<int> vecteur2;

    // for (size_t i = 0; i < loop; i++)
    // {
    //     vecteur2.clear();
    //     for (int i = 0; i < 10000; i++)
    //     {
    //         vecteur2.push_back(std::rand() % 500);
    //     }
    //     std::sort(vecteur2.begin(), vecteur2.end());

    //     // time the function
    //     start = std::chrono::system_clock::now();
    //     int index2 = rechercheDichotomiqueAdvanced(vecteur2, valeurRecherchee);
    //     end = std::chrono::system_clock::now();

    //     elapsed_seconds = end - start;
    //     mean += elapsed_seconds;
    // }
    
    // std::cout << "Time elapsed: " << mean / loop << std::endl;


    return 0;
}
