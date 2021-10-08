//
//  annexe.c
//  Pendu_Thomas
//
//  Created by thomas_khmielnitzky on 07/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "annexe.h"


int lettreDansMot(char motSecret[], char lettre){
    char lettreMotSecret = 0;
    int len = strlen(motSecret);
    for (int i = 0; i<len; i++) {
        if(motSecret[i] == lettre){
            return 1;
        }
    }
    return 0;
}

/*
int* GenererBoolMot(int longueurMot){
    int motVierge[longueurMot];
    for (int i = 0; i < longueurMot; i++) {
        motVierge[i] = 0;
    }
    return motVierge;
}
*/

void GenererBoolMot(char* motVierge, int longueurMot){
    //int motVierge[longueurMot];
    for (int i = 0; i < longueurMot; i++) {
        // motVierge[i] = 0;
        *(motVierge+i) = 0;
    }
    printBool(motVierge, longueurMot);
    // return motVierge;
}

/*
void LettresPresentes(int *boolMot, char motSecret[], char lettre){
    
}
*/

void completerBoolMot(char* motSecret,char* lettreTrouvee,char lettre){
    int longueur = strlen(motSecret);
    for (int i = 0; i < longueur; i++) {
        if (*(motSecret + i) == lettre){
            *(lettreTrouvee + i) = 1;
        }
    }
    printBool(lettreTrouvee, longueur);
}

int sommeTableau(char* boolTab, int longueur){
    int somme = 0;
    printBool(boolTab, longueur);
    for (int i = 0; i < longueur; i++) {
        printf("verification %d\n",*(boolTab + i));
        if (*(boolTab + i)){
            somme++;
        }
    }
    return somme;
}

void printBool(char* motVierge, int longueurMot){
    for (int i = 0 ; i < longueurMot ; i++){
        printf("%d", *(motVierge+i));
    }
    printf("\n");
}
