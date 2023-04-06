#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <bits/stdc++.h>

using namespace std;
using region = map<string, tuple<size_t, int, int>>;
using tournee = pair<vector<string>, double>;

constexpr int codeASCIIde_a = 97;
constexpr int codeASCIIde_A = 65;
constexpr int nombreDeLettres = 26;
constexpr int tailleMinNomVille = 4;
constexpr int tailleMaxNomVille = 12;
constexpr int grainePourLeRand = 1;
constexpr int nombreDeVilles = 4;
constexpr int nombreCombinaisons = 24;
constexpr int tailleCoteCarte = 100;

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

tournee calculeDistanceTourneeGlouton(region const &villes)
{
    vector<string> tournee;
    double distance = 0;
    for (auto &[ville, pos] : villes)
    {
        auto &[id, x, y] = pos;
        for (auto &[ville2, pos2] : villes)
        {
            auto &[id, x, y] = pos;
            tournee.push_back(ville);
            distance += sqrt(x * x + y * y);
        }
        tournee.push_back(ville);
        distance += sqrt(x * x + y * y);
    }
    return {tournee, distance};
}

int main()
{
    region villes = genererVilles();
    // cout << villes << endl;
    tournee tournee = calculeDistanceTournee(villes);
    cout << "Tournee: " << endl;
    for (auto &ville : tournee.first)
    {
        cout << ville << " ";
    }
    cout << endl;
    cout << "Distance: " << tournee.second << endl;
}