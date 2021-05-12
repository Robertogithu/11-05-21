#include <stdio.h>
#include <malloc.h>

// HEAD
// TAIL

typedef struct nodo {
  int valor;
  struct nodo* prox;
} NODO;

struct fila {
  NODO* head;
  NODO* tail;
};

void iniciarFila (struct fila* f) {
  //(*f).head = NULL;
  f->head = NULL;
  //(*f).tail = NULL;
  f->tail = NULL;
}

void adicionar(struct fila* f, int valor) {  
  NODO* novo = (NODO*) malloc(sizeof(NODO));

  novo->valor = valor;
  novo->prox = NULL;

  if (f->head == NULL) f->head = novo;
  else f->tail->prox = novo;
  
  f->tail = novo;
}

void remover(struct fila* f) {
  if (f->head != NULL) {
    NODO* apagar = f->head;

    f->head = f->head->prox;
  
    free(apagar);

    if (f->head == NULL) f->tail = NULL;
  }
}

void imprimeFila(struct fila* f) {
  NODO* aux = f->head;

  printf("MINHA FILA :)\n");

  while (aux != NULL) {
    printf("|_%d_|", aux->valor);
    aux = aux->prox;
  }

  printf("\nFIM\n\n");
}

int main(void) {
  struct fila minhaFila;

  iniciarFila(&minhaFila);

  adicionar(&minhaFila, 2);
  adicionar(&minhaFila, 3);
  adicionar(&minhaFila, 4);

  //remover(&minhaFila);

  imprimeFila(&minhaFila);

  return 0;
}