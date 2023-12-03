#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int info;
    struct node* next;
};
typedef struct node Node;

Node** criaLst(void)
{
    Node** lst = (Node**)malloc(sizeof(Node*));
    if (lst == NULL)
        return NULL;
    lst = NULL;
    return lst;
}

Node** lst_insere(Node** lst, int num)
{
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL)
        return NULL;
    
    novo->info = num;
    novo->next = lst;

    return novo;
}

void lst_imprime(Node** lst)
{
    Node* aux;
    for (aux = lst; aux != NULL; aux = aux->next)
    {
        printf("%d--->", aux->info);
    }
    printf("NULL\n");
}

Node* lst_busca(Node** lst, int elemento)
{
    Node* aux;
    for (aux = lst; aux != NULL; aux = aux->next)
    {
        if (elemento == aux->info)
            return aux;
    }
    return NULL;
}

int main(void)
{
    Node** lista = criaLst();

    lista = lst_insere(lista, 23);
    if (lista == NULL)
    {
        printf("Erro de alocacao de memoria\n");
        return -1;
    }

    lista = lst_insere(lista, 45);
    if (lista == NULL)
    {
        printf("Erro de alocacao de memoria\n");
        return -1;
    }

    lista = lst_insere(lista, 7);
    if (lista == NULL)
    {
        printf("Erro de alocacao de memoria\n");
        return -1;
    }

    lista = lst_insere(lista, 80);
    if (lista == NULL)
    {
        printf("Erro de alocacao de memoria\n");
        return -1;
    }

    lst_imprime(lista);

    printf("Elemento %d esta na posicao %p da lista", 7, lst_busca(lista, 7));

    return 0;
}