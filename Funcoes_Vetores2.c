#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // Lendo os tamanhos dos vetores
    scanf("%d %d", &n, &m);

    // Declarando e alocando espaço para os vetores A, B e C
    int *A = (int *)malloc(n * sizeof(int));
    int *B = (int *)malloc(m * sizeof(int));
    int *C = (int *)malloc((n + m) * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        C[index++] = A[i];
    }
    for (int i = 0; i < m; i++) {
        C[index++] = B[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    for (int i = 0; i < n + m; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    free(A);
    free(B);
    free(C);

    return 0;
}
