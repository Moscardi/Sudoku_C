#include "Sudoku.h"

Puzzle* createNewPuzzle(void)
{
    int a,b;
    Puzzle* novo = (Puzzle*)malloc(sizeof(Puzzle));
    novo->posVazias = 9*9;
    novo->puzzle = (int**)malloc(sizeof(int*)*9);
    for ( a = 0; a < 9; a++)
    {
        novo->puzzle[a] = (int*)malloc(sizeof(int)*9);
        novo->puzzle[a][0] = 0;
        novo->puzzle[a][1] = 0;
        novo->puzzle[a][2] = 0;
        novo->puzzle[a][3] = 0;
        novo->puzzle[a][4] = 0;
        novo->puzzle[a][5] = 0;
        novo->puzzle[a][6] = 0;
        novo->puzzle[a][7] = 0;
        novo->puzzle[a][8] = 0;
    }
    novo->numLivresLinha = createIntegerList();
    novo->numLivresColuna = createIntegerList();
    novo->numLivresBloco = createIntegerList();
    for ( a = 1; a < 10; a++)
    {
        novo->numLivresLinha = addNumberInIntegerList(novo->numLivresLinha,a);
        novo->numLivresColuna = addNumberInIntegerList(novo->numLivresColuna,a);
        novo->numLivresBloco = addNumberInIntegerList(novo->numLivresBloco,a);
    }
    for (a = 0; a < 9; a++)
    {
        for ( b = 0; b < 9; b++)
        {
            novo->puzzle[a][b] = 0;
        }
    }
    return novo;
}

void freePuzzle(Puzzle* jogo)
{
    int a;
    for ( a = 0; a < 9; a++)
    {
        free(jogo->puzzle[a]);
    }
    free(jogo->puzzle);
    freeIntegerList(jogo->numLivresLinha);
    freeIntegerList(jogo->numLivresBloco);
    freeIntegerList(jogo->numLivresColuna);
    free(jogo);
    jogo = NULL;
}

int addNumberInPuzzle(Puzzle* jogo, Location* local, int number)
{
    if(jogo != NULL && local != NULL && number > 0 && number < 10 && local->posX >= 0 && local->posX < 9 && local->posY >= 0 && local->posY < 9)
    {
        int aux;
        if(local->posY <= 2 && local->posX <= 2)
        {
            aux = 0;
        }
        else if(local->posY <=2 && local->posX <= 5)
        {
            aux = 1;
        }
        else if (local->posY <=2 && local->posX <= 8)
        {
            aux = 2;
        }
        else if (local->posY <=5 && local->posX <= 2)
        {
            aux = 3;
        }
        else if (local->posY <=5 && local->posX <= 5)
        {
            aux = 4;
        }
        else if (local->posY <=5 && local->posX <= 8)
        {
            aux = 5;
        }
        else if (local->posY <=8 && local->posX <= 2)
        {
            aux = 6;
        }
        else if (local->posY <=8 && local->posX <= 5)
        {
            aux = 7;
        }
        else if (local->posY <=8 && local->posX <= 8)
        {
            aux = 8;
        }
        if(numberExistInIntegerList(jogo->numLivresBloco, number) == 1 && numberExistInIntegerList(jogo->numLivresLinha, number) == 1 && numberExistInIntegerList(jogo->numLivresColuna,number) == 1)
        {
            jogo->puzzle[local->posY][local->posX] = number;
            jogo->numLivresLinha = removeNumberOfIntegerList(jogo->numLivresLinha, number);
            jogo->numLivresColuna = removeNumberOfIntegerList(jogo->numLivresColuna, number);
            jogo->numLivresBloco = removeNumberOfIntegerList(jogo->numLivresBloco, number);
            return 1;
        }
    }
    return 0;
}

int removeNumberOfPuzzle(Puzzle* jogo, Location* local, int number)
{
    if(jogo != NULL && local != NULL && number > 0 && number < 10 && local->posX >= 0 && local->posX < 9 && local->posY >= 0 && local->posY < 9)
    {
        int aux;
        if(local->posY <= 2 && local->posX <= 2)
        {
            aux = 0;
        }
        else if(local->posY <=2 && local->posX <= 5)
        {
            aux = 1;
        }
        else if (local->posY <=2 && local->posX <= 8)
        {
            aux = 2;
        }
        else if (local->posY <=5 && local->posX <= 2)
        {
            aux = 3;
        }
        else if (local->posY <=5 && local->posX <= 5)
        {
            aux = 4;
        }
        else if (local->posY <=5 && local->posX <= 8)
        {
            aux = 5;
        }
        else if (local->posY <=8 && local->posX <= 2)
        {
            aux = 6;
        }
        else if (local->posY <=8 && local->posX <= 5)
        {
            aux = 7;
        }
        else if (local->posY <=8 && local->posX <= 8)
        {
            aux = 8;
        }
        if(numberExistInIntegerList(jogo->numLivresBloco, number) == 0 && numberExistInIntegerList(jogo->numLivresLinha, number) == 0 && numberExistInIntegerList(jogo->numLivresColuna,number) == 0)
        {
            jogo->puzzle[local->posY][local->posX] = 0;
            jogo->numLivresLinha = addNumberInIntegerList(jogo->numLivresLinha, number);
            jogo->numLivresColuna = addNumberInIntegerList(jogo->numLivresColuna, number);
            jogo->numLivresBloco = addNumberInIntegerList(jogo->numLivresBloco, number);
            return 1;
        }
    }
    return 0;
}

Config* createConfig(void)
{
    Config* novo = (Config*)malloc(sizeof(Config));
    novo->mostrarPossibilidades = 0;
    novo->mostrarQuantoFalta = 1;
    novo->removerJogada = 0;
    novo->numeroPosicoesGeradas = 10;
    return novo;
}

void generateSudoku(Puzzle* sudoku, int num){
    int i, x, y, tam = 4, n_elem = 9, elem, aux;
	srand(time(NULL));
	Location* local;
	int* possivel;
	for(i = 0; i < num; i++){
        x = rand()%n_elem;
        y = rand()%n_elem;

        if(sudoku->puzzle[y][x] == 0){
            elem = rand()%n_elem + 1;
            local = createLocation(x,y);
            possivel = returnPossibilityesOfPosition(sudoku, &tam, local);

            aux = addNumberInPuzzle(sudoku, local, elem);
            if(aux == 0){
                freeLocation(local);
            }
        }else{
            i--;
        }

    }
}

int* returnPossibilityesOfPosition(Puzzle* jogo, int* tam, Location* local){
    *tam = 0;
    int * possibilidades = (int*)malloc(9*sizeof(int));
    int  aux  ;
    for(aux = 1; aux <=9; aux++){
        if(numberExistInIntegerList(jogo->numLivresBloco, aux) == 1 && numberExistInIntegerList(jogo->numLivresLinha, aux) == 1 && numberExistInIntegerList(jogo->numLivresColuna,aux) == 1){
            possibilidades[*tam] = aux;
            *tam = *tam + 1;
        }
    }
    if(*tam == 0){
        free(possibilidades);
        return possibilidades;
    }
    realloc(possibilidades, *tam);
    return possibilidades;
}
