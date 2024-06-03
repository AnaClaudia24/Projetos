#include <stdio.h>

float maior(float vet[], int n);
float menor(float vet[], int n);

int main(){
    
    int n = 0;
    scanf("%d", &n);
// Fase 1
    float vet1[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%f", &vet1[i]);
        }
//Fase 2
    
    float media = 0, soma = 0;
        for (int i = 0; i < n; i++)
        {
            soma += vet1[i];
        }
    
    media = soma/n;
    float maior1= maior(vet1, n);
    float menor1= menor(vet1, n);

        printf("%.1f %.1f %.1f", maior1, menor1, media);
return 0;
}

// Definindo as func

float maior(float vet[], int n){
    float grande = vet[0];
        for (int i = 0; i < n; i++)
        {
            if (vet[i] > grande)
            {
                grande = vet[i];
            }
        }
        return grande;
}

float menor(float vet[], int n){
    float pequeno = vet[0];
        for (int i = 0; i < n; i++)
        {
            if (vet[i] < pequeno)
            {
                pequeno = vet[i];
            }
        }
        return pequeno;
}