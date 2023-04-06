# Sujet TD n1

## exo1

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
