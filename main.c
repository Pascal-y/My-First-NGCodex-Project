#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_MODALITIES 20

// Fonction pour calculer la moyenne
float calculerMoyenne(int modalites[], int n) {
    int somme = 0;
    for (int i = 0; i < n; i++) {
        somme += modalites[i];
    }
    return (float)somme / n;
}

// Fonction pour calculer la variance
float calculerVariance(int modalites[], int n, float moyenne) {
    float variance = 0;
    for (int i = 0; i < n; i++) {
        variance += pow(modalites[i] - moyenne, 2);
    }
    return variance / n;
}

// Fonction pour calculer l'écart type
float calculerEcartType(float variance) {
    return sqrt(variance);
}

// Fonction pour calculer la médiane
float calculerMediane(int modalites[], int n) {
    float mediane;
    int milieu = n / 2;
    if (n % 2 == 0) {
        mediane = (modalites[milieu - 1] + modalites[milieu]) / 2.0;
    } else {
        mediane = modalites[milieu];
    }
    return mediane;
}

// Fonction pour calculer le mode
int calculerMode(int modalites[], int n) {
    int mode = modalites[0];
    int maxFrequences = 1;

    int current = modalites[0];
    int currentFrequences = 1;

    for (int i = 1; i < n; i++) {
        if (modalites[i] == current) {
            currentFrequences++;
        } else {
            if (currentFrequences > maxFrequences) {
                mode = current;
                maxFrequences = currentFrequences;
            }
            current = modalites[i];
            currentFrequences = 1;
        }
    }

    if (currentFrequences > maxFrequences) {
        mode = current;
    }

    return mode;
}

int main() {
    int modalites[MAX_MODALITES];
    int n = 0;
    int entree;

    // Saisie des modalités
    printf("Entrez les modalites (-1 pour terminer) : ");
    while (scanf("%d", &entree) == 1 && entree != -1) {
        if (n >= MAX_MODALITES) {
            printf("Nombre maximum de modalites atteint (%d)\n", MAX_MODALITES);
            return 1;
        }
        modalites[n++] = entree;
    }

    // Calcul des statistiques
    float moyenne = calculerMoyenne(modalites, n);
    float variance = calculerVariance(modalites, n, moyenne);
    float ecartType = calculerEcartType(variance);
    float mediane = calculerMediane(modalites, n);
    int mode = calculerMode(modalites, n);

    // Affichage des statistiques
    printf("\nTableau des effectifs :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", modalites[i]);
    }

    printf("\n\nMoyenne : %.2f\n", moyenne);
    printf("Variance : %.2f\n", variance);
    printf("Ecart type : %.2f\n", ecartType);
    printf("Mediane : %.2f\n", mediane);
    printf("Mode : %d\n", mode);

    return 0;
}
