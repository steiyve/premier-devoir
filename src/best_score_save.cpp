#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

//
// fonction qui sauvegarde le meilleur score
// dans un fichier appeler best.txt
// param:
//  - score a sauver (bestScore, int)
//
// retour:
//  - code d'erruer (erro, int)
//
int save(int bestScore){

    // variable de la fonction
    string fileName = "../bin/best.txt";

    // ouverture du fichier avec fstream
    ifstream monFichier;
    monFichier.open(fileName, ios::app);
    
    // error handling
    if (monFichier.fail()){
        cerr << "Error: " << strerror(errno) << "\n";
        return -1;                                                                      // retourne -1 si il y a une erreur dans l'ouverture du fichier
    }

    //sauver la valeur dans le fichier
    monFichier >> bestScore;
    
    // fermer le fichier
    monFichier.close();
    
    // error handling
    if (monFichier.fail()){
        cerr << "Error: " << strerror(errno) << "\n";
        return -2;                                                                      // retourne -2 si il y a une erreur dans la fermeture du fichier
    }

    return 0;                                                                           // retourne 0 si la fonction fut executer sans erreur
}