#include "GenerateMenuStrings.h"

StringRow* generateStringsOfInitialMenu(void)
{
    StringRow* menu = createStringRow();
    String* opcao = createString();
    addCaracterOfString(opcao,'I');
    addCaracterOfString(opcao,'n');
    addCaracterOfString(opcao,'c');
    addCaracterOfString(opcao,'i');
    addCaracterOfString(opcao,'a');
    addCaracterOfString(opcao,'r');
    addCaracterOfString(opcao,' ');
    addCaracterOfString(opcao,'j');
    addCaracterOfString(opcao,'o');
    addCaracterOfString(opcao,'g');
    addCaracterOfString(opcao,'o');
    printf("%c",opcao->caracter);
    addStringRow(menu,opcao);
    if(menu->inicial == NULL){
        printf("Nesse momento não deve estar vazia");
    }
    opcao = createString();
    if(menu->inicial == NULL){
        printf("Nesse momento pode ser que esteja vazia");
    }
    addCaracterOfString(opcao,'C');
    addCaracterOfString(opcao,'o');
    addCaracterOfString(opcao,'n');
    addCaracterOfString(opcao,'f');
    addCaracterOfString(opcao,'i');
    addCaracterOfString(opcao,'g');
    addCaracterOfString(opcao,'u');
    addCaracterOfString(opcao,'r');
    addCaracterOfString(opcao,'a');
    addCaracterOfString(opcao,'c');
    addCaracterOfString(opcao,'a');
    addCaracterOfString(opcao,'o');
    addStringRow(menu, opcao);
    opcao = createString();
    addCaracterOfString(opcao, 'S');
    addCaracterOfString(opcao, 'a');
    addCaracterOfString(opcao, 'i');
    addCaracterOfString(opcao, 'r');

    return menu;
}
