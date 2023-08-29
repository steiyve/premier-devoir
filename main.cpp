#include <stdio.h>
#include "src/chiffre.cpp"
#include "src/chiffre.h"
#include "src/input.cpp"
#include "src/input.h"

using namespace std;

int main(){

    //variable general
    int scrore = 0;

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
        else{
            printf("mauvaise reponse vous avez pas de point pour le tour\n");
        }
    }

    return 0;
}