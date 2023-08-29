#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

//
//fonction qui retourne un nombre aleatoir entre 0 et 1000
//param:
//  - plus haute possibilite (high, int)
//
//retour:
//  - code d'erreur (erro, int)
//  - chiffre de retour (returnNum, int)
//
int random(int high){


    //variable requise au bon fonctionement de la fonction
    int returnNum = 0;
    time_t t;

    // initialize le generateur de chiffre random
    srand((unsigned) time(&t));

    // storer le nombre random dans la variable returnNum
    returnNum = rand() % (high + 1);
    
    printf("%d\n", returnNum);

    return returnNum;
    return 0;                           //si le code ses bien executer on retourne 0
}

