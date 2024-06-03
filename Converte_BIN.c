#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    int bits[N];
    for (int i = 0; i < N; i++) {
        scanf("%1d", &bits[i]);
    }

    int decimal = 0;
    for (int i = 0; i < N; i++) {
        decimal += bits[i] * pow(2, N - i - 1);
    }

    printf("%d\n", decimal);

    return 0;
}
