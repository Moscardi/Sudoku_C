#include "String.h"
#include <string.h>

typedef struct no_row_string
{
	String* string;
	struct no_row_string* proximo;
}NodeStringRow;

typedef struct row_string{
	NodeStringRow* atual;
	NodeStringRow* inicial;
}StringRow;


StringRow* createStringRow(void);

void addStringRow(StringRow* row,String* texto);

int stringRowExist(StringRow* row, String* texto);

void freeStringRow(StringRow* row);

String* removeStringOfRow(StringRow* row);

int stringRowIsEmpity(StringRow* row);

void restartStringRow(StringRow* row);

String* returnAtualStringOfRow(StringRow* row);

int atualStringRowIsEmpity(StringRow* row);

int contStringRow(StringRow* row);
