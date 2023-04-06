#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <bits/stdc++.h>

using namespace std;
using region = map<string, tuple<size_t, int, int>>;

constexpr int codeASCIIde_a = 97;
constexpr int codeASCIIde_A = 65;
constexpr int nombreDeLettres = 26;
constexpr int tailleMinNomVille = 4;
constexpr int tailleMaxNomVille = 12;
constexpr int grainePourLeRand = 1;
constexpr int nombreDeVilles = 4;
constexpr int nombreCombinaisons = 24;
constexpr int tailleCoteCarte = 100;
vector<vector<string>> tournees;

using mat2D = double[nombreDeVilles][nombreDeVilles];
using allTournees = vector<pair<vector<string>, double>>;

/// \name allPermutationWithSTL.cpp
/// \version 1.1 (2020.2021)
/// \brief Algorithme combinatoire récursif
void toutesLesPermutations(vector<string> &villes, int debut, int fin);
region genererVilles();
void genererMatriceDistance(region &villes, mat2D &matrice);

double calculeDistanceTournee(region const &villes, vector<string> const &tournee, mat2D const &matrice);
allTournees calculeDistanceToutesLesTournees(region const &villes, mat2D const &matrice);
pair<vector<string>, double> calculeDistanceTourneeGlouton(region const &villes, mat2D const &matrice);

ostream &operator<<(ostream &os, const region &reg)
{
    for (auto &[ville, pos] : reg)
    {
        auto &[id, x, y] = pos;
        os << ville << "(" << id << ") : " << x << ", " << y << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const mat2D &mat)
{
    // print a nice formated matrix with each column aligned
    for (size_t i = 0; i < nombreDeVilles; i++)
    {
        for (size_t j = 0; j < nombreDeVilles; j++)
        {
            os << setw(7) << mat[i][j] << " | ";
        }
        os << endl
           << "----------------------------------------" << endl;
    }
    return os;
}

template <typename TK, typename TV>
std::vector<TK> extract_keys(std::map<TK, TV> const &input_map)
{
    std::vector<TK> retval;
    for (auto const &element : input_map)
    {
        retval.push_back(element.first);
    }
    return retval;
}

ostream &operator<<(ostream &os, const allTournees &tournees)
{
    for (auto &[tournee, distance] : tournees)
    {
        os << "Tournee : ";
        for (auto &ville : tournee)
        {
            os << ville << " ";
        }
        os << "| Distance : " << distance << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const pair<vector<string>, double> &tournee)
{
    os << "Tournee : ";
    for (auto &ville : tournee.first)
    {
        os << ville << " ";
    }
    os << "| Distance : " << tournee.second << endl;
    return os;
}

int main()
{
    region villes = genererVilles();
    cout << villes << endl;
    auto villes_vect = extract_keys(villes);
    // toutesLesPermutations(villes_vect, 0, nombreDeVilles - 1);
    mat2D matrice;
    genererMatriceDistance(villes, matrice);
    toutesLesPermutations(villes_vect, 0, nombreDeVilles - 1);
    auto tournees = calculeDistanceToutesLesTournees(villes, matrice);
    // cout << tournees << endl;
    sort(tournees.begin(), tournees.end(), [](pair<vector<string>, double> const &a, pair<vector<string>, double> const &b)
         { return a.second < b.second; });
    cout << "Top 10 Meilleure tournee : " << endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout << tournees.at(i) << endl;
    }

    cout << "On obtient toujours deux fois la meme meilleure tournee, car on a deux fois la meme dans un sens et dans l'autre." << endl;

    cout << "Tournee Glouton : " << endl;
    auto tourneeGlouton = calculeDistanceTourneeGlouton(villes, matrice);
    cout << tourneeGlouton << endl;
    return 0;
}

/// \brief Methode recursive generant l ensemble des mots possibles
/// avec les caractères du mot villes donne en parametre.
void toutesLesPermutations(vector<string> &villes, int debut, int fin)
{
    if (debut == fin)
    {
        vector<string> tournee;
        for (int i = 0; i < villes.size(); i++)
        {
            tournee.push_back(villes.at(i));
            // cout << villes.at(i) << " ";
        }
        // cout << endl;
        tournees.push_back(tournee);
    }
    else
    {
        // Permutations made
        for (int i = debut; i <= fin; i++)
        {
            // echange des deux lettres
            swap(villes[debut], villes[i]);
            // Appel Recursif
            toutesLesPermutations(villes, debut + 1, fin);
            // On revient à la situation précédente
            swap(villes[debut], villes[i]);
        }
    }
}

/// \brief Methode generant un ensemble de villes
/// \return un ensemble de villes²
region genererVilles()
{
    region villes;
    srand(grainePourLeRand);
    for (size_t ville = 0; ville < nombreDeVilles; ville++)
    {
        size_t word_size = tailleMinNomVille + rand() % (tailleMaxNomVille - tailleMinNomVille + 1);
        string nom;
        nom += (rand() % nombreDeLettres) + codeASCIIde_A;
        for (size_t lettre = 0; lettre < word_size; lettre++)
        {
            nom += (rand() % nombreDeLettres) + codeASCIIde_a;
        }
        // insert a tuple
        villes.insert({nom, make_tuple(ville, rand() % tailleCoteCarte, rand() % tailleCoteCarte)});
        // villes.insert(nom, {ville, rand() % tailleCoteCarte, rand() % tailleCoteCarte});
    }
    return villes;
}

/// \brief Methode generant une matrice de distance entre les villes
/// \param villes un ensemble de villes
/// \param matrice une matrice de distance
void genererMatriceDistance(region &villes, mat2D &matrice)
{
    for (auto &[ville, pos] : villes)
    {
        auto &[id, x, y] = pos;
        for (auto &[ville2, pos2] : villes)
        {
            auto &[id2, x2, y2] = pos2;
            matrice[id][id2] = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
        }
    }
    cout << matrice << endl;
}

double calculeDistanceTournee(region const &villes, vector<string> const &tournee, mat2D const &matrice)
{
    double distance = 0;
    for (size_t i = 0; i < tournee.size() - 1; i++)
    {
        auto &[id, x, y] = villes.at(tournee.at(i));
        auto &[id2, x2, y2] = villes.at(tournee.at(i + 1));
        distance += matrice[id][id2];
    }
    return distance;
}

allTournees calculeDistanceToutesLesTournees(region const &villes, mat2D const &matrice)
{
    allTournees distances;
    for (auto &tournee : tournees)
    {
        distances.push_back({tournee, calculeDistanceTournee(villes, tournee, matrice)});
    }
    return distances;
}

pair<vector<string>, double> calculeDistanceTourneeGlouton(region const &villes, mat2D const &matrice)
{
    vector<string> tournee;
    double distance = 0;
    auto villes_vect = extract_keys(villes);
    auto ville_depart = villes_vect.at(0);
    tournee.push_back(ville_depart);
    villes_vect.erase(villes_vect.begin());
    while (!villes_vect.empty())
    {
        auto ville_courante = tournee.back();
        auto &[id, x, y] = villes.at(ville_courante);
        double distance_min = numeric_limits<double>::max();
        string ville_plus_proche;
        for (auto &ville : villes_vect)
        {
            auto &[id2, x2, y2] = villes.at(ville);
            double distance = matrice[id][id2];
            if (distance < distance_min)
            {
                distance_min = distance;
                ville_plus_proche = ville;
            }
        }
        tournee.push_back(ville_plus_proche);
        villes_vect.erase(find(villes_vect.begin(), villes_vect.end(), ville_plus_proche));
    }
    tournee.push_back(ville_depart);
    distance = calculeDistanceTournee(villes, tournee, matrice);
    return {tournee, distance};
}