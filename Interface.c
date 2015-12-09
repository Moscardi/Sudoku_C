#include "getch.h"
#include "Sudoku.h"


void apresentation(void)
{
    system("clear");
    printf("*   *    * ****     **    ****   *     *  ***  **** ****    **\n");
    printf("*   *    * *       *  *    *     **   ** *   *  *   *      *  *\n");
    printf("*   *    * *      ******    *    * * * * *   *   *  *     ****** \n" );
    printf("***  ****  ****  *      * ****   *  *  *  ***  **** **** *      *\n");
    printf("\n                       Produções\n" );
    int i =0;
    for (i = 0; i < 999999999; i++);
}

void logo(void)
{
    printf("***** *    * **     ***  *   ** *    *\n");
    printf("*     *    * * **  *   * * **   *    *\n");
    printf("***** *    * *   * *   * ***    *    *\n");
    printf("    * *    * * **  *   * *  **  *    *\n");
    printf("*****  ****  **     ***  *    ** ****\n");
}

int generateInitialMenu(void)
{
    printf("retardado\n" );
    char digito = 'a';
    do
    {
        system("clear");
        logo();
        printf("A - Iniciar jogo\n");
        printf("B - configurações\n");
        printf("C - sair\n");
        digito = getch();
        printf("%c",digito);

        if(digito == 'A' || digito == 'a')
        {
            return 0;
        }
        else if(digito == 'B' || digito == 'b')
        {
            return 1;
        }
        else if(digito == 'C' || digito == 'c')
        {
            return 2;
        }
    }
    while(digito != 'A' && digito != 'B' && digito != 'C' && digito != 'a' && digito != 'b' && digito != 'c');

}

void generateConfigMenu()
{

}

void showPuzzle(int** puzzle, Location* local)
{
    int i, j, tam = 9;

    for(i =0; i < tam; i++)
    {
        if(local->posY == 0)
        {
            if(i == local->posX )
            {
                printf("**");
            }
            else if(i == local->posX + 1)
            {
                printf("*-");
            }
            else
            {
                printf("--");
            }
        }
        else
        {
            printf("--");
        }
    }

    if(local->posY == 0)
    {
        if(tam-1 == local->posX )
        {
            printf("*\n");
        }
        else
        {
            printf("-\n");
        }
    }
    else
    {
        printf("-\n");
    }

    for(i =0; i < tam; i++)
    {
        for(j =0 ; j < tam; j++)
        {
            if(1 == 1)
            {
            }
        }
    }

}
