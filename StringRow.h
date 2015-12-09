#include "String.h"
#include <string.h>

typedef struct row_string
{
	String* string;
	struct row_string* proximo;
}StringRow;

StringRow* createStringRow(void);

void addStringRow(StringRow* row,String* texto);

int stringRowExist(StringRow* row, String* texto);

void freeStringRow(StringRow* row);

String* removeStringOfRow(StringRow* row);

int stringRowIsEmpty(StringRow* row);
