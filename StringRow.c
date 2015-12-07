#include "StringRow.h"

RowString* createStringRow(void){
  return NULL;
}

void addStringRow(RowString* row,String* texto){
  if(texto != NULL){
    StringRow* novo = (StringRow*)malloc(sizeof(StringRow));
    novo->string = texto;
    novo->proximo = NULL;
    if(row == NULL){
      row = texto;
      return;
    }
    StringRow* aux = row;
    while (aux->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = nova;
  }
}

int stringRowExist(RowString* row, String* texto){
  StringRow* aux = row;
  while (aux != NULL && compareStringWithString(aux->string, texto) != 1) {
    aux = aux->proximo;
  }
  if(aux == NULL){
    return 0;
  }
  return 1;
}

void freeStringRow(RowString* row){
    StringRow* aux;
    while (row != NULL) {
      aux = row;
      row = row->proximo;
      freeString(aux->string);
      free(aux);
    }
}

char* removeStringOfRow(RowString* row){
  String* retorno = row->string;
  StringRow* aux = row;
  row = row->proximo;
  free(aux);
  return retorno;
}

int stringRowIsEmpity(RowString* row){
  return (row == NULL)
}
