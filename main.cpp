#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

using namespace std;


struct Vertice {
    int nome;
    int caminho;
    int peso;
    Vertice *prox;
};

struct ListaV{
    Vertice *inicio, *fim;
    int tam;
};

void InicializarV(ListaV *lista){

    lista->inicio = (Vertice*) malloc(sizeof(Vertice));
    lista->inicio->caminho = NULL;
    lista->inicio->nome = NULL;

    lista->fim = lista->inicio;

    lista->tam = 0;
}


void imprimeLista(ListaV *lista){
    Vertice *verticeAtual = lista->inicio->prox;
    for (int i = 0; i < lista->tam; i++){
        printf("\n nome: %i peso: %i", verticeAtual->nome, verticeAtual->peso);
        verticeAtual = verticeAtual->prox;
    }


}

void addVertice(int nome, int caminho, int peso, ListaV *lista){

    Vertice *temp = (Vertice*) malloc(sizeof(Vertice));
    temp->peso = peso;
    temp->caminho = caminho;
    temp->nome = nome;
    temp->prox = NULL;

    lista->fim->prox = temp;
    lista->fim = temp;

    lista->tam++;

}

void imprimeMatriz(int matriz[][5]){
    cout << "\n\n";
    for(int i=0; i < 4; i++){
        for(int j=0; j < 4; j++){
            if(matriz[i][j] >= 0){
                printf("Vertice: %i aponta para o vértice %i com peso %i \n", i, j, matriz[i][j]);
            }
        }
    }
}

//teste: utilizando uma lista encadeada para uma adição mais dinâmica, mas ainda precisa ser mais trabalhada
void abordagem1(){
    Vertice *vertice;
    ListaV grafo;
    InicializarV(&grafo);
    addVertice(1, 1, 0, &grafo);
    addVertice(2, 1, 0, &grafo);
    addVertice(2, 2, 0, &grafo);
    addVertice(2, 3, 0, &grafo);

    imprimeLista(&grafo);
}

//teste: utilizando uma matriz de 5X5
void abordagem2(){
    int matriz[5][5];
    //inicializando a matriz
    for(int i=0; i < 4; i++){
        for(int j=0; j < 4; j++){
            matriz[i][j] = -2;
        }
    }

    matriz[1][1] = 0;
    matriz[1][2] = 2;
    matriz[2][1] = 0;
    matriz[2][2] = 0;
    matriz[2][3] = 0;
    imprimeMatriz(matriz);
}

int main()
{
    abordagem1();
    abordagem2();
    return 0;
}

