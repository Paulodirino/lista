#include<stdio.h>

struct No {

    int valor;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No *inicio, *fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return inicio == NULL;
    }

    void inserirFinal(int valor) { // O(1)

        n++;
        No *novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;

    }

    void imprimir(int maior) { // O(n)

        No *aux = inicio;

        while (aux != NULL) {
            if(aux->valor==maior){
                aux = aux->prox;
                printf("%d ", aux->valor);
            }
            aux = aux->prox;
        }

        printf("\n");

    }
};

int main() {
int t,i=1,v,cod,nota,maior,inicio,x=1;
    Lista l;

do{

    scanf("%d", &t);
    while( i <= t ){
        if(t==0){
             return 0;
        }
        scanf("%d", &cod);
        scanf("%d", &nota);
        l.inserirFinal(nota);
        l.inserirFinal(cod);
        if(nota > maior){
        maior = nota;
        }
        i++;
    }
        if(t>=1){
             printf("Turma %d \n", x);
             l.imprimir(maior);
        }

    x++;

    i=1;
    }while(t>=1);

    return 0;
}

