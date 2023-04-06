#include <iostream>
#include <vector>

/*
uint count = 0
for i = N - 1; i > 0; i++ do
	for j = i - 1; j >= 0, j++ do
		if M[i][j] == 1 then
			count += M[j][i]
		end 
	end
end
			
*/

size_t countMatch(const std::vector<std::vector<bool>> &matrice)
{
    size_t count = 0;
    for (size_t i = matrice.size() - 1; i > 0; i--)
    {
        for (size_t j = i + 1; j > 0; j--)
        {
            // std::cout << "Test for pos" << i << " " << j - 1 << std::endl;
            if (matrice[i][j -1] == 1)
            {
                count += !matrice[j-1][i];
            }
        }
    }
    return count;
}

/*
fn phrase_counter(in string phrase, in int taille, out int[] nblettre_mot, out int nbmot)
    i = 0
    j = 0
    while i < taille do
        if phrase[i] == '_' then
            nbmot += 1
            nblettre_mot.push_back(i - j)
            j = i + 1
        end
        i += 1
    end
    nbmot += 1
    nblettre_mot.push_back(i - j)
end
*/

void phrase_counter(const std::string &phrase, size_t taille, std::vector<size_t> &nblettre_mot, size_t &nbmot)
{
    size_t i = 0, j = 0;
    while (i < taille)
    {
        if (phrase[i] == '_')
        {
            nbmot += 1;
            nblettre_mot.push_back(i - j);
            j = i + 1;
        }
        i += 1;
    }
    nbmot += 1;
    nblettre_mot.push_back(i - j);
}


/*
fn phrase_counter_no_taille(in string phrase, out int[] nblettre_mot, out int nbmot)
    i = 0
    j = 0
    while phrase[i] != '.' do
        if phrase[i] == '_' then
            nbmot += 1
            nblettre_mot.push_back(i - j)
            j = i + 1
        end
        i += 1
    end
    nbmot += 1
    nblettre_mot.push_back(i - j)
end
*/

void phrase_counter_no_taille(const std::string &phrase, std::vector<size_t> &nblettre_mot, size_t &nbmot)
{
    size_t i = 0, j = 0;
    while (phrase[i] != '.')
    {
        if (phrase[i] == '_')
        {
            nbmot += 1;
            nblettre_mot.push_back(i - j);
            j = i + 1;
        }
        i += 1;
    }
    nbmot += 1;
    nblettre_mot.push_back(i - j);
}

int main()
{
    // std::vector<std::vector<bool>> matrice = {
    //     {0, 1, 1, 1, 0},
    //     {1, 0, 1, 0, 0},
    //     {0, 1, 0, 0, 0},
    //     {1, 0, 1, 0, 1},
    //     {0, 1, 0, 1, 0}};
    // std::cout << countMatch(matrice) << std::endl;

    std::string phrase = "bonjour_comment_ca_va";
    size_t taille = phrase.size();
    std::vector<size_t> nblettre_mot;
    size_t nbmot;

    phrase_counter(phrase, taille, nblettre_mot, nbmot);

    std::cout << "nbmot: " << nbmot << std::endl;
    for (size_t i = 0; i < nblettre_mot.size(); i++)
    {
        std::cout << "Mot n " << i + 1 << " : " << nblettre_mot[i] << ", ";
    }
    std::cout << std::endl;


    phrase = "bonjour_comment_ca_va.";
    nblettre_mot.clear();
    nbmot = 0;

    phrase_counter_no_taille(phrase, nblettre_mot, nbmot);

    std::cout << "nbmot: " << nbmot << std::endl;
    for (size_t i = 0; i < nblettre_mot.size(); i++)
    {
        std::cout << "Mot n " << i + 1 << " : " << nblettre_mot[i] << ", ";
    }
    std::cout << std::endl;


    return 0;
}
    
