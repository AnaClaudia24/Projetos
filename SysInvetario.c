#include <stdio.h>
#include <string.h>
#define MAX_PRODUTO 100


typedef struct{
    char nome[120];
    int codigo;
    float preco;
    int quantidade;
} produto;

produto adicionaProduto();
void exibirProduto(produto *vetor, int codigo, int numProdutos);
void listaProduto(produto *armazem, int numProdutos);
float calculaInventario(produto *armazem, int numProdutos);

int main(){

produto armazem[100];
int numProdutos = 0;
int aProduto = 0;
int codProduto =0;
int n = 0;
float totalInventario = 0;

    do{
        printf("1- Adicionar novo produto\n");
        printf("2- Exbir produto\n");
        printf("3- Exibir lista de produtos\n");
        printf("4- Valor total do inventario\n\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
                if (numProdutos < MAX_PRODUTO)
                {
                    armazem[aProduto] = adicionaProduto();
                    numProdutos++;
                    aProduto++;
                } 

            break;
        case 2:
                printf("Digite o codigo do produto:\n");
                    scanf("%d", &codProduto);
                
                exibirProduto(armazem, codProduto, numProdutos);
                printf("\n\n");
                
            break;
        case 3:
            listaProduto(armazem, numProdutos);

            break;
        case 4:
            totalInventario = calculaInventario(armazem, numProdutos);

            printf("Valor total dos produtos contidos no armazem: %.2f\n\n", totalInventario);
            break;
        }

        if (n > 4 || n < 1)
        {
            printf("VALOR INVALIDO!\n\n");
        }

    } while (n != 5);

    return 0;
}

produto adicionaProduto(){

    produto novoProduto;
        printf("Digite o nome do produto:\n");
        while(getchar()!= '\n');
            fgets(novoProduto.nome, sizeof(novoProduto.nome), stdin);
                novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0;

        printf("Digite o codigo do produto:\n");
            scanf("%d", &novoProduto.codigo);
        printf("Digite o preco do produto:\n");
            scanf("%f", &novoProduto.preco);
        printf("Digite a quantidade de produtos em estoque:\n");
            scanf("%d", &novoProduto.quantidade);

    return novoProduto;
}

void exibirProduto(produto *vetor, int codigo, int numProdutos){
        
        for (int i = 0; i < numProdutos; i++)
        {
            if (codigo == vetor[i].codigo)
            {
                printf("Nome: %s\n", vetor[i].nome);
                printf("Codigo: %d\n", codigo);
                printf("Preco: %.2f\n", vetor[i].preco);
                printf("Quantidade em estoque: %d\n\n", vetor[i].quantidade);
                return;
            }
        }
        printf("PRODUTO NAO ENCONTRADO!");
}

void listaProduto(produto *armazem, int numProdutos){

    for (int i = 0; i < numProdutos; i++){
        printf("Nome: %s\n", armazem[i].nome);
        printf("Codigo: %d\n", armazem[i].codigo);
        printf("Preco: %.2f\n",armazem[i].preco);
        printf("Quantidade: %d\n\n", armazem[i].quantidade);
    }
    
}

float calculaInventario(produto *armazem, int numProdutos){
    float totalInventario = 0;

    for (int i = 0; i < numProdutos; i++){
        totalInventario += armazem[i].preco*armazem[i].quantidade; 
    }
     
    return totalInventario;
}