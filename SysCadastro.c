#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FUNC 100
#define MAX_CHAR 120

typedef struct
{
    char nome[MAX_CHAR];
    int idade;
    char departamento[50];
    float salario;
} funcionario;

funcionario adicionarFuncionario();
void exibirFuncionario(funcionario *vetor, char *nome, int numFuncionarios);
void listaFuncionario(funcionario *vetor, int numFuncionarios);
float mediaSalario(funcionario *vetor, int numFuncionarios);
void procuraFuncionario(funcionario *vetor, char *departamento, int numFuncionarios);

int main()
{

    int n = 0; // Seletor do menu
    int numFuncionarios = 0; // Numero de funcionarios
    funcionario todosFuncionarios[MAX_FUNC]; // Vetor contendo todos os funcionarios da empresa
    char nomeFuncionario[MAX_CHAR]; // Variavel usada no caso 2, busca o funcionario pelo nome
    float media =0; //Variavel que recebe a funcao mediaSalario();
    char departamento[50]; // Variavel usada na funcao procurarFuncionario();

    do
    {
        printf("1- Adicionar funcionario\n");
        printf("2- Exibir funcionario\n");
        printf("3- Listar funcionarios\n");
        printf("4- Media salarial\n");
        printf("5- Procurar funcionario por departamento\n");
        printf("6- SAIR\n\n");
        scanf("%d", &n);

        switch (n){
        case 1:
            if (numFuncionarios < MAX_FUNC){
                todosFuncionarios[numFuncionarios] =  adicionarFuncionario();
                numFuncionarios++;
            }
            else{
                printf("NUMERO MAXIMO DE FUNCIONARIOS ATINGIDO!\n");
            }

            break;
        case 2:
            printf("Digite o nome do funcionario: \n");
                while (getchar() != '\n'); // Limpa o buffer
                fgets(nomeFuncionario, sizeof(nomeFuncionario), stdin);
                nomeFuncionario[strcspn(nomeFuncionario, "\n")] = '\0';

            exibirFuncionario(todosFuncionarios, nomeFuncionario, numFuncionarios);

            break;
        case 3:
            listaFuncionario(todosFuncionarios, numFuncionarios);
            break;
        case 4:

            media = mediaSalario(todosFuncionarios, numFuncionarios);
            printf("%.2f\n\n", media);

            break;
        case 5:
                printf("Qual departamento deseja consultar?\n");
                    while(getchar()!= '\n'); 
                    fgets(departamento, sizeof(departamento), stdin);
                    departamento[strcspn(departamento,"\n")] = '\0';

                    procuraFuncionario(todosFuncionarios, departamento, numFuncionarios);

            break;
        case 6: 
            printf("Saindo do programa...");
            return 1;
            break;

        default: 
            printf("OPCAO INVALIDA, ESCOLHA UMA OPCAO DE 1 a 6");
            break;
        }

      
    } while (n != 6);

    return 0;
}

funcionario adicionarFuncionario(){

    funcionario novoFuncionario;

    while (getchar() != '\n'); // Limpa o buffer

    printf("Digite o nome do funcionario:\n");
    fgets(novoFuncionario.nome, sizeof(novoFuncionario.nome), stdin);
    novoFuncionario.nome[strcspn(novoFuncionario.nome, "\n")] = '\0';

    printf("Digite a idade do funcionario:\n");
    scanf("%d", &novoFuncionario.idade);

    printf("Digite o salario desse funcionario:\n");
    scanf("%f", &novoFuncionario.salario);

    while (getchar() != '\n');

    printf("Qual o departamento desse funcionario?\n");
        fgets(novoFuncionario.departamento, sizeof(novoFuncionario.departamento), stdin);
        novoFuncionario.departamento[strcspn(novoFuncionario.departamento, "\n")] = '\0';

    return novoFuncionario;
}

void exibirFuncionario(funcionario *vetor, char *nome, int numFuncionarios){

    int encontrado = 0;
    for (int i = 0; i < numFuncionarios; i++)
    {
        if (strcmp(nome, vetor[i].nome) == 0)
        {
            printf("Nome: %s\n", vetor[i].nome);
            printf("Idade: %d\n", vetor[i].idade);
            printf("Salario: %.2f\n", vetor[i].salario);
            printf("Setor: %s\n\n", vetor[i].departamento);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado){
        printf("Funcionario %s nao encontrado!\n\n", nome);
        }
}

void listaFuncionario(funcionario *vetor, int numFuncionarios){

    printf("\n");
    printf("Lista de todos os funcionarios: \n\n");
    for (int i = 0; i < numFuncionarios; i++)
    {
        printf("Nome: %s\n", vetor[i].nome);
        printf("Idade: %d\n", vetor[i].idade);
        printf("Salario: %.2f\n", vetor[i].salario);
        printf("Setor: %s\n\n", vetor[i].departamento);
    }
}

float mediaSalario(funcionario *vetor, int numFuncionarios){
    
    float media = 0.0;
    float somasalarios;
    
    for (int i = 0; i < numFuncionarios; i++)
    {
        somasalarios += vetor[i].salario;
    }
    media = somasalarios/numFuncionarios;

    return media;
}

void procuraFuncionario(funcionario *vetor, char *departamento, int numFuncionarios){
    
    int encontrado = 0;

    printf("Funcionarios: \n");
    for (int i = 0; i < numFuncionarios; i++)
    {
        if (strcmp(departamento, vetor[i].departamento) == 0)
        {
            printf("Nome: %s\n", vetor[i].nome);
            printf("Salario: %.2f\n\n", vetor[i].salario);
            encontrado = 1;
        }
    }
     if (!encontrado) {
        printf("Nenhum funcionario encontrado no departamento '%s'.\n\n", departamento);
}
}