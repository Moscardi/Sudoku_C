#include "String.h"
#include <string.h>

typedef struct row_string
{
	String* string;
	struct row_string* proximo;
}RowString;

RowString* createStringRow(void);

void addStringRow(RowString* row,String* texto);

int stringRowExist(RowString* row, String* texto);

void freeStringRow(RowString* row);

String* removeStringOfRow(RowString* row);

int stringRowIsEmpity(RowString* row);
