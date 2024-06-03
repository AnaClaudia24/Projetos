#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NOTAS 3
#define MAX_ALUNOS 10

typedef struct
{
    char nome[100];
    int idade;
    float notas[3];
} aluno;

aluno adicionarAluno();
void infoAluno(aluno vetAluno);
float mediaAlunos(float somaNotas, int totalNotas);


int main()
{
    aluno vetAlunos[10];
    int n = 0;
    int numAluno = 0;
    int numAlunos = 0;
    int totalNotas = 0;
    float media = 0;
    float somaNotas = 0.0;

    do
    {
        printf("Digite 1 para adicionar um novo aluno \n");
        printf("Digite 2 para exibir os dados dos alunos cadastrados \n");
        printf("Digite 3 para calcular a media das notas de TODOS os alunos\n");
        printf("Digite 4 para SAIR do programa\n\n");
            scanf("%d", &n);

        switch (n)
        {
        case 1:
            if (numAlunos < MAX_ALUNOS){
            vetAlunos[numAlunos] = adicionarAluno();
            numAlunos++;
            } else{
                printf("MAXIMO ATINGIDO!");
            }
            
            break;
        case 2:
            printf("Qual o numero do Aluno? (1-10)\n");
                scanf("%d", &numAluno);

            infoAluno(vetAlunos[numAluno - 1]);

            break;

        case 3:
            somaNotas = 0.0;
            totalNotas = 0;

            for (int k = 0; k < numAlunos; k++){
                for (int j = 0; j < MAX_NOTAS; j++){
                    somaNotas += vetAlunos[k].notas[j];
                    totalNotas++;
                }
            }
            media = mediaAlunos(somaNotas, totalNotas);

            printf("A media de TODOS os alunos eh: %.2f\n\n", media);
            break;
        case 4:
            return 1;
            break;

        default:
            printf("Escolha uma opcao valida!\n\n");
            break;
        }
    } while (n != 4);

    return 0;
}

aluno adicionarAluno(){
    aluno novoAluno;

    printf("Digite o nome do aluno: \n");
        while(getchar()!= '\n');
        fgets(novoAluno.nome, sizeof(novoAluno), stdin);
            novoAluno.nome[strcspn(novoAluno.nome, "\n")] = 0;


    printf("Digite a idade do aluno:\n");
        scanf("%d", &novoAluno.idade);

    printf("Digite as notas do aluno:\n");
        for (int i = 0; i < 3; i++)
        {
            scanf("%f", &novoAluno.notas[i]);
        }
        
return novoAluno;
}

void infoAluno(aluno vetAluno){

    printf("Informacoes do aluno %s: \n\n", vetAluno.nome);
    printf("Idade: %d\n", vetAluno.idade);

    for (int i = 0; i < 3; i++)
    {
        printf("Nota %d: %.2f \n", i+1, vetAluno.notas[i]);
    }
    printf("\n");

}

float mediaAlunos(float somaNotas, int totalNotas){
    return somaNotas/ totalNotas;
}