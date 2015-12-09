#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct lista_inteiro
{
	int valor;
	struct lista_inteiro* proximo;
}IntegerList;

IntegerList* createIntegerList(void);

IntegerList* addNumberInIntegerList(IntegerList* list, int number);

int numberExistInIntegerList(IntegerList* list, int number);

void freeIntegerList(IntegerList* list);

IntegerList* removeNumberOfIntegerList(IntegerList* list, int number);

int IntegerListIsEmpty(IntegerList* list);
