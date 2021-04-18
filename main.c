#include <stdio.h>
#include <stdlib.h>
#include "arvores-binarias.h"

int main()
{
    PONT raiz = inicializa();
    raiz = criaNovoNo(20);

    PONT no = inicializa();
    no = criaNovoNo(13);

    PONT no1 = inicializa();
    no1 = criaNovoNo(12);

    adiciona(raiz,no);
    adiciona(raiz,no1);


    PONT p = contem(12,raiz);

    printf("Numero de elementos antes da remocao: %d\n", numeroNos(raiz));
    printf("Arvore antes da remocao: ");
    exibeArvore(raiz);

    removeNo(raiz, 13);
    printf("\nNumero de elementos depois da remocao: %d", numeroNos(raiz));
    printf("\nArvore apos remocao: ");

    exibeArvore(raiz);

    return 0;
}
