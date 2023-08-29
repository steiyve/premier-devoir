#include <stdio.h>
#include <iostream>

using namespace std;


//
// la fonction pose les question a l'utilisateur
// retour:
//  - code derreur (erro, int)
//  - reussi (result, bool)
//
int input(){
    // variable de fonction
    int reponse;
    cout << "choisissez un chiffre en 0 et 1000: ";
    cin >> reponse;

    return reponse;                     // chiffre que lutilisateur a choisi 
    return 0;                           // si le code ne recontre pas derreur il retourne 0
}