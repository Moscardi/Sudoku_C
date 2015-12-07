
typedef struct string{
  char caracter;
  struct string* proximo;
}String;

void createString(void);

void addCaracterOfString(String* texto, char letra);

int stringIsEmpity(String* texto);

void printString(String* texto);

int deleteLastCaracterOfString(String* texto);

int deleteCaracterOfString(String* texto, char letra);

void freeString(String* texto);

int compareStringWithString(String* texto1, String* texto2);
