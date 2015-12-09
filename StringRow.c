#include "StringRow.h"

StringRow* createStringRow(void){
  StringRow* novo = (StringRow*)malloc(sizeof(StringRow));
  novo->atual = NULL;
  novo->inicial = NULL;
  return novo;
}

void addStringRow(StringRow* row,String* texto){
  if(texto != NULL){
    printf("dig sin");
    NodeStringRow* novo = (NodeStringRow*)malloc(sizeof(NodeStringRow));
    novo->string = texto;
    novo->proximo = NULL;
    if(row->inicial == NULL){
      row->inicial = novo;
      row->atual = novo;
      return;
    }
    NodeStringRow* aux = row->inicial;
    while (aux->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = novo;
  }
}

int stringRowExist(StringRow* row, String* texto){
  NodeStringRow* aux = row->inicial;
  while (aux != NULL && compareStringWithString(aux->string, texto) != 1) {
    aux = aux->proximo;
  }
  if(aux == NULL){
    return 0;
  }
  return 1;
}

void freeStringRow(StringRow* row){
    NodeStringRow* aux;
    while (row->inicial != NULL) {
      aux = row->inicial;
      row->inicial = aux->proximo;
      freeString(aux->string);
      free(aux);
    }
    free(row);
}

String* removeStringOfRow(StringRow* row){
  String* retorno = row->inicial->string;
  NodeStringRow* aux = row->inicial;
  if(row->inicial == row->atual){
    row->atual = aux->proximo;
  }
  row->inicial = aux->proximo;
  free(aux);
  return retorno;
}

int stringRowIsEmpity(StringRow* row){
  return (row->inicial == NULL);
}

void restartStringRow(StringRow* row){
  row->atual = row->inicial;
}

String* returnAtualStringOfRow(StringRow* row){
  if(row->inicial != NULL && row->atual != NULL){
    String* retorno = row->atual->string;
    row->atual = row->atual->proximo;
    return retorno;
  }
    return NULL;
}

int atualStringRowIsEmpity(StringRow* row){
  return (row->atual == NULL);
}

int contStringRow(StringRow* row){
  if(row != NULL && row->inicial != NULL){
    NodeStringRow* aux = row->inicial;
    int contador = 0;
    while (aux != NULL) {
      aux = aux->proximo;
      contador++;
    }
    contador --;
    return contador;
  }
  return 0;
}
