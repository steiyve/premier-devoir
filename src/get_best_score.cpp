#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

//
// fonction qui ouvre le fichier ou le bestScore et storer (best.txt)
// et l'enregistre dans la variable bestScore
// retour:
//  - meilleur score (bestScore, int)
//  - code d'erreur (erro)
//
int openAndGet(){

    // variable de fonction
    int bestScore;
    string fileName = "../bin/best.txt";
    string line;

    // ouverture du fichier
    ifstream f;
    f.open(fileName, ios::in);
    
    // lecture du fichier
    while (getline(f, line)){
        bestScore = stoi(line);
    }

    // fermeture du fichier
    f.close();
    
    // error handeling
    if (f.fail()){
        cerr << "Error: " << strerror(errno) << "\n";
        return -1;                                                                      // retourne -1 si il y a une erreur dans l'ouverture/fermeture du fichier
    }


    return bestScore;
    return 0;                                                                           // retourne 0 si la fonction fut executer sans erreur
}