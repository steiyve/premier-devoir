#include <stdio.h>
#include "src/chiffre.cpp"
#include "src/chiffre.h"
#include "src/input.cpp"
#include "src/input.h"

using namespace std;

int main(){

    //error handeling
    if (random(1000) != 0){
        printf("error!, relancer le code svp");
        return -1;
    }
    return 0;
}