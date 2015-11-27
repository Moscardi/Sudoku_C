

typedef struct lista_inteiro
{
	int valor;
	struct lista_inteiro* proximo;	
}ListaInteiro;

typedef struct lista_string
{
	char* string;
	struct lista_string* proximo;
}ListaString;


ListaInteiro* LI_createList(void);

ListaString* LS_createList(void);

void LI_addNumber(ListaInteiro* list, int number);

void LS_addString(ListaString* list, char* string);

int LI_NumberExist(ListaInteiro* list, int number);

int LS_StringExist(ListaString* list, char* string);

void LI_free(ListaInteiro* list);

void LS_free(ListaString* list);

int LI_removeNumber(ListaInteiro* list, int number);

char* LS_removeString(ListaString* list);

int LI_isEmpity(ListaInteiro* list);

int LS_isEmpity(ListaString* list);