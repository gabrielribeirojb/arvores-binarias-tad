#ifndef ARVORES-BINARIAS_H_INCLUDED
#define ARVORES-BINARIAS_H_INCLUDED
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    struct aux *esq, *dir;
} NO;

typedef NO* PONT;

PONT inicializa();
PONT adiciona(PONT raiz, PONT no);
PONT criaNovoNo(TIPOCHAVE ch);
PONT contem(TIPOCHAVE ch, PONT raiz);
int numeroNos(PONT raiz);
void exibeArvore(PONT raiz);
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai);
PONT removeNo(PONT raiz, TIPOCHAVE ch);



#endif // ARVORES-BINARIAS_H_INCLUDED
