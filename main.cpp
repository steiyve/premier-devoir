#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;


//variable de programe
int loaded_score;
string reponse;
string returnNum;

//
// la fonction pose les question a l'utilisateur
// retour:
//  - code derreur (erro, int)
//  - reponse (repose, string)
//
int input(){
    

    //demandage de la question
    cout << "choisissez un chiffre en 0 et 1000 (entrez 1001 pour fermer le jeu): ";
    cin >> reponse;

    return reponse;                                                                     // chiffre que lutilisateur a choisi 
    return 0;                                                                           // si le code ne recontre pas derreur il retourne 0
}

//
//fonction qui retourne un nombre aleatoir entre 0 et 1000
//param:
//  - plus haute possibilite (high, int)
//
//retour:
//  - code d'erreur (erro, int)
//  - chiffre de retour (returnNum, string)
//
int random(int high){


    //variable requise au bon fonctionement de la fonction

    int num;
    time_t t;

    // initialize le generateur de chiffre random
    srand((unsigned) time(&t));

    // storer le nombre random dans la variable returnNum
    returnNum = rand() % (high + 1);
    
    printf("%d\n", returnNum);

    returnNum = to_string(num);
    return returnNum;
    return 0;                                                                           //si le code ses bien executer on retourne 0
}



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

    cout << bestScore << "\n";

    // variable de la fonction
    string fileName = "best.txt";

    // ouverture du fichier avec fstream
    fstream monFichier;
    monFichier.open(fileName, ios::app);
    

    //sauver la valeur dans le fichier
    monFichier << bestScore;
    
    // fermer le fichier
    monFichier.close();
    
   

    return 0;                                                                           // retourne 0 si la fonction fut executer sans erreur
}



//
// fonction qui ouvre le fichier ou le bestScore et storer (best.txt)
// et l'enregistre dans la variable bestScore
// retour:
//  - meilleur score (bestScore, int)
//  - code d'erreur (erro)
//
int openAndGet(){

    // variable de fonction
    string line;

    // ouverture du fichier
    fstream f;
    f.open("best.txt", ios::in);
    
    if (f.fail()){
        cerr << "Error: " << stderr << "\n";
        cout << "erreur durant la louvetrrture du fichier\n";
        return -1;                                                                      // retourne -1 si il y a une erreur dans l'ouverture/fermeture du fichier
    }

    // lecture du fichier
    while (getline(f, line)){
        cout << line << "\n";
    }


    // fermeture du fichier
    f.close();
    

    cout << loaded_score << "\n";
    return loaded_score;
    return 0;                                                                           // retourne 0 si la fonction fut executer sans erreur
}

int main(){

    // variable general
    int scrore = 0;
    int best_score;

    // aller cherchez le meilleur score
    // gestion d'erreur
    openAndGet();
    best_score = loaded_score;
    cout << best_score << "\n";

    


    while(reponse == returnNum){
        // appeler les fonction
        random(1000);
        input();
        

        // verification pour voir qui a gagne

        if (reponse == returnNum){
            printf("bravo tu a gagne un point\n");
            scrore++;
        }


        // mauvaise reponse
        else{
            printf("mauvaise reponse vous avez pas de point pour le tour\n");
        }

        // verifier si score > bestScore
        if (scrore >= best_score){
            best_score = scrore;
            cout << best_score << "\n";
        }
    }

    cout << best_score << "\n";
    // gestion des erreur de la sauvegarde de fichier
    save(best_score);

    return 0;
}