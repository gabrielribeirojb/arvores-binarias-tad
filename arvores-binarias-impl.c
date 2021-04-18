#include <stdio.h>
#include "arvores-binarias.h"

PONT inicializa(){
    return (NULL);
}

PONT adiciona(PONT raiz, PONT no){
    if(raiz == NULL)
        return (no);

    if(no-> chave < raiz -> chave)
        raiz -> esq = adiciona(raiz-> esq, no);
    else
        raiz -> dir = adiciona(raiz -> dir, no); //ignora-se chave atual

    return (raiz);
}

PONT criaNovoNo(TIPOCHAVE ch){
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return (novoNo);
}

PONT contem(TIPOCHAVE ch, PONT raiz){
    if(raiz == NULL){
        return (NULL);
    }

    if(raiz->chave == ch){
        return (raiz);
        printf("É a raiz");
    }

    if(raiz->chave > ch){
        return contem(ch, raiz->esq);
    }

    return (contem(ch, raiz->dir));
}

int numeroNos(PONT raiz){
    if(!raiz){
        return 0;
    }
    else {
         return(numeroNos(raiz->esq)
           +1
           +numeroNos(raiz->dir));
    }
}

void exibeArvore(PONT raiz){
    if(raiz != NULL){
        printf("%i", raiz->chave);
        printf("(");
        exibeArvore(raiz->esq);
        exibeArvore(raiz->dir);
        printf(")");
    }
}

//Método auxiliar que devolve o ponteiro do nó buscado
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
    PONT atual = raiz;
    *pai = NULL;

    while(atual){
        if(atual->chave == ch)
            return (atual);

        *pai = atual;

        if(ch < atual->chave)
            atual = atual->esq;
        else atual = atual->dir;
    }
     return (NULL);
}

//Para remover, precisa-se: no a ser removido, no pai desse, no substituto e pai do substituto
PONT removeNo(PONT raiz, TIPOCHAVE ch){
    PONT pai, no, p, q;
    no = buscaNo(raiz, ch, &pai);

    if(no == NULL)
        return (raiz);

    //Verifica se há 1 descendente
    if(!no->esq || !no->dir){
        if(!no->esq)
            q = no->dir;
         else
            q = no->esq;
    }
    else {
        p = no;
        q = no->esq;

        while(q->dir){
            p = q;
            q = q->dir;
        }

        if(p != no){
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }

    if(!pai){
        free(no);
        return(q);
    }

    if(ch < pai->chave)
        pai->esq = q;
     else
        pai->dir = q;

    free(no);
    return (raiz);
}
