#include "StringRow.h"

typedef struct lista_inteiro
{
	int valor;
	struct lista_inteiro* proximo;
}IntegerList;

IntegerList* createIntegerList(void);

void addNumberInIntegerList(IntegerList* list, int number);

int numberExistInIntegerList(IntegerList* list, int number);

void freeIntegerList(IntegerList* list);

int removeNumberOfIntegerList(IntegerList* list, int number);

int IntegerListIsEmpity(IntegerList* list);
