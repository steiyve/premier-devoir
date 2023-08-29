#include <stdio.h>
#include "src\chiffre.cpp"
#include "src\chiffre.h"
#include "src\input.cpp"
#include "src\input.h"
#include "src\best_score_save.cpp"
#include "src\get_best_score.h"
#include "src\get_best_score.cpp"


using namespace std;

int main(){

    // variable general
    int scrore = 0;
    int best_score = 0;

    // aller cherchez le meilleur score
    // gestion d'erreur
    if (openAndGet() != 0){
        printf("Erreur pendant la lecture du fichier\n");
        return -1;
    }
    else{
        best_score = bestScore;
    }


    bool run = true;
    while(run){
        // appeler les fonction
        random(1000);
        input();

        // verification pour voir qui a gagne
        if (reponse == returnNum){
            printf("bravo tu a gagne un point\n");
            scrore++;
        }

        // quiter la boucle
        if (reponse == 1001){
            run = false;
        }

        // mauvaise reponse
        else{
            printf("mauvaise reponse vous avez pas de point pour le tour\n");
        }

        // verifier si score > bestScore
        if (scrore >= best_score){
            best_score = scrore;
        }
    }

    // gestion des erreur de la sauvegarde de fichier
    if (save(best_score) != 0){
        printf("Erreur pendant l'ecriture du fichier\n");
        return -1;
    }

    return 0;
}