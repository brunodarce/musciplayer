#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    char musica[40], cantor[40];
    float duracao;
    struct Lista *prox;
}Lista;

Lista *inicio, *fim, *aux;

void inserirMusica(){
    int c;
    Lista *novo = (struct Lista *)malloc(sizeof(struct Lista));
    printf("\nQual eh a musica? ");
    fgets(novo->musica, 39, stdin);
    printf("De quem eh a musica? ");
    fgets(novo->cantor, 39, stdin);
    printf("qual a duracao da musica? ");
    scanf("%f", &novo->duracao);
    while ((c = getchar()) != '\n' && c != EOF) {}
    novo->prox = NULL;
    if (inicio == NULL){
        inicio = fim = novo;
    }else{
         fim->prox = novo;
         fim = novo;
    }
}

void esvaziarLista(){

    char ch;
    if (inicio == NULL){
        printf("\nA fila esta vazia!\n\n");
    }else{
        printf("\nTem certeza que deseja esvaziar toda a lista?(s/n): ");
        ch = getchar();
        if (ch == 's' || ch == 'S'){
            while (inicio != NULL){
                aux = inicio;
                inicio = inicio->prox;
                free(aux); // Libera o espaco na memoria
            }
            printf("\nA lista foi esvaziada com sucesso!!\n\n");
        }else{
            printf("\nA lista nao foi esvaziada!!\n\n");
        }
    }
}

void mostrarLista(){
    aux = inicio;
    if (inicio == NULL){
        printf("\nA lista esta vazia!");
    }else{
        while (aux != NULL){
            printf("musica: %s", aux->musica);
            printf("cantor: %s", aux->cantor);
            printf("duracao: %f\n\n", aux->duracao);
            aux = aux->prox;
        }
    }
    printf("\n\n");
}

void localizarMusica(){
    aux = inicio;
    char procurada[40];
    if (inicio == NULL){
        printf("\nA lista estah vazia!");
    }else{
        char musica[40];
        printf("Digite a musica que procura: ");
        fgets(procurada, 39, stdin);
        while (aux != NULL) {
            if (strcmp(aux->musica,procurada) == 0){
                printf("\nMusica  %s localizada!\n\n", aux->musica);
                printf("musica %s", aux->musica);
                printf("cantor: %s\n\n", aux->cantor);
                return;
            }else{
                aux = aux->prox;
            }
        }
        if (aux == NULL){
            printf("\nMusica  %s nao localizada!\n", musica);
        }
    }
    printf("\n\n");
}


int main(){
    setlocale(LC_ALL, "");
    system("color 0E");
    int opt, c;

    do{
        printf("*==================================*\n");
        printf("| Simulador de Player de Musica    |\n");
        printf("*==================================*\n\n\n\n");
        printf("*===========================*\n");
        printf("| 1. Inserir Música         |\n");
        printf("| 2. Pesquisar Músicas      |\n");
        printf("| 3. listar  Músicas        |\n");
        printf("| 4. Limpar Lista do Player |\n");
        printf("| 5. Sair                   |\n");
        printf("*===========================*\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opt);
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (opt){
            case 1:
                inserirMusica();
                printf("\nMusica inserida com sucesso!!\n\n");
                system("pause");
                break;
            case 2:
                localizarMusica();
                system("pause");
                break;
            case 3:
                mostrarLista();
                system("pause");
                break;
            case 4:
                esvaziarLista();
                system("pause");
                break;
            case 5:
                printf("\nO programa foi encerrado com sucesso!!\n\n");
                system("pause");
                break;
            default:
                printf("\nEscolha Invalida!!\n\n");
                system("pause");
                break;
        }
        system("cls");
    }while (opt != 5);

    return 0;

}
