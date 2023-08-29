#include <stdio.h>
#include "src/chiffre.cpp"

using namespace std;

int main(){

    //error handeling
    if (random(1000) != 0){
        printf("error!, relancer le code svp");
        return -1;
    }

    return 0;
}