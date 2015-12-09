#include "String.h"

void ScreateString(void){
    return NULL;
}

void addCaracterOfString(String* texto, char letra){
  if(letra != '\0'){
    String* nova = (String*)malloc(sizeof(String));
    nova->proximo = NULL;
    nova->caracter = letra;
    if(texto == NULL){
      texto = nova;
      return 1;
    }
    String* aux = texto;
    while (aux != NULL) {
      if(aux->proximo == NULL){
        aux->proximo = nova;
        return 1;
      }
      aux = aux->proximo;
    }
    return 0;
  }
}

void printString(String* texto){
  String* aux;
  for (aux = texto;aux != NULL;aux = aux->proximo ) {
    printf("%c", aux->caracter);
  }
}

int stringIsEmpity(String* texto){
  return (texto == NULL);
}

int deleteLastCaracterOfString(String* texto){
  if(texto != NULL){
    String* aux = texto;
    if(aux->proximo == NULL){
      free(texto);
      texto = NULL;
      return 1;
    }
    while (aux->proximo->proximo != NULL) {
      aux = aux->proximo;
    }
    free(aux->proximo);
    aux->proximo = NULL;
    return 1;
  }
  return 0;
}

int deleteCaracterOfString(String* texto, char letra){
  if(texto != NULL){
    String* aux = texto;
    if(texto->caracter == letra){
      texto = texto->proximo;
      free(aux);
      return 1;
    }
    String* atual = texto->proximo;
    while (atual != NULL) {
      if(atual->caracter = letra){
        aux->proximo = atual->proximo;
        free(atual);
        return 1;
      }
      aux = atual;
      atual = atual->proximo;
    }
  }
  return 0;
}

void freeString(String* texto){
  if (texto != NULL) {
    String* aux = texto;
    do{
      texto = texto->proximo;
      free(aux);
      aux = texto;
    }while (aux != NULL);
    texto = NULL;
  }
}

int compareStringWithString(String* texto1, String* texto2){
  String* aux1 = texto1;
  String* aux2 = texto2;
  while(aux1 != NULL && aux2 != NULL){
    if(aux1->caracter != aux2->caracter){
      return 0;
    }
    aux1 = aux1->proximo;
    aux2 = aux2->proximo;
  }
  if(aux1 == NULL && aux2 == NULL){
    return 1;
  }
  return 0;
}
