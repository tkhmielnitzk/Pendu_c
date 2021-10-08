//
//  main.c
//  Pendu_Thomas
//
//  Created by thomas_khmielnitzky on 07/10/2021.
//

// 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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "annexe.h"

int main(int argc, const char * argv[]) {

    printf("Bonjour, tu es au jeu du pendu\n");
    printf("Choisis combien tu veux avoir d'essais:\n");
    
    int essais = 0;
    scanf(" %d", &essais);
    printf("Tu as %d essais\n",essais);
    
    char motSecret[] = "ELEMENT";
    int longueur = strlen(motSecret);
    
    printf("Commençons dès à présent\n");
    char lettre = 0;
    // int* motVierge = GenererBoolMot(strlen(motSecret));
    char lettreTrouvee[longueur];
    GenererBoolMot(lettreTrouvee,longueur);
    
    int boolFini = 0;
    
    while (essais>0 && boolFini == 0) {
        
        printf("Choisis une lettre\n");
        scanf(" %c", &lettre);
        printf("voilà la lettre: %c!\n",lettre);
        
        if (!lettreDansMot(motSecret, lettre))
            essais--;
        
        else{
            completerBoolMot(motSecret,lettreTrouvee,lettre);
            int somme = sommeTableau(lettreTrouvee, longueur);
            printf("Somme des lettres correctes = %d\n",somme);
            if (somme == longueur){
                boolFini = 1;
                printf("Vous avez gagné !");
            }
        }
        
        printf("Voilà le résultat actuel:\n");
        printBool(lettreTrouvee, longueur);
        for (int j = 0; j < longueur; j++) {
            // if (*(lettreTrouvee+j) == 1){
            // printf("valeur de bool: %d\n",*(lettreTrouvee+j));
            if (*(lettreTrouvee+j)){
                // printf("index lettre: %d \n",i);
                printf("%c",*(motSecret+j));
            }
            else{
                printf("*");
            }
        }
        printf("\n");

        printf("plus que %d essais\n",essais);
    }

    return 0;
}
