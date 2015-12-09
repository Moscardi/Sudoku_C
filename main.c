#include "Interface.h"


int main(int argc, char const *argv[])
{
    int option = 0;
    Config* configaracao = createConfig();
    apresentation();

    do
    {
        option = generateInitialMenu();

        if(option == 0)
        {
            starGame(configaracao);
        }
        else if(option == 1)
        {
            generateConfigMenu(configaracao);
        }
        else if(option == 2)
        {
            break;
        }
    }
    while(option != '2');
}

void starGame(Config* configuracao)
{
    Puzzle* jogo = createNewPuzzle();
    generateSudoku(jogo,configuracao->numeroPosicoesGeradas);
    Location* atual = createLocation(0,0);
    char digito;
    do
    {
        system("clear");
        showPuzzle(jogo->puzzle, atual);
        digito = getch();
        if( (digito == 'W' || digito == 'w') && atual->posY > 0)
        {
            atual->posY = atual->posY - 1;
            continue;
        }
        else if( (digito == 'S' || digito == 's') && atual->posY < 8 )
        {
            atual->posY = atual->posY + 1;
            continue;
        }
        else if( (digito == 'A' || digito == 'a') && atual->posX > 0)
        {
            atual->posX = atual->posX -1;
            continue;
        }
        else if( (digito == 'D' || digito == 'd') && atual->posX < 8 )
        {
            atual->posX = atual->posX + 1;
            continue;
        }
        else if(digito >= '1' && digito <= '9'){
            if(addNumberInPuzzle(jogo,atual,digito - 48) == 0){
                printf("Jogada invalida, posição em conflito");
            }
        }

    }
    while( 1 == 1);
}
