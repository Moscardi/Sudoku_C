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
        printf("1 - Iniciar jogo\n");
        printf("2 - configurações\n");
        printf("3 - sair\n");
        __fpurge(stdin);
        digito = getch();

        if(digito == '1' )
        {
            return 0;
        }
        else if(digito == '2')
        {
            return 1;
        }
        else if(digito == '3')
        {
            return 2;
        }
    }
    while(digito != '1' && digito != '2' && digito != '3');

}

void generateConfigMenu(Config* conf)
{
    int select = 0;
    char digito;
    do
    {
        system("clear");
        logo();
        if(select == 0)
        {
            printf(">\t");
        }
        else
        {
            printf("\t");
        }
        printf("Número de posições geradas no começo do jogo: < %d >\n", conf->numeroPosicoesGeradas);
        if(select == 1)
        {
            printf(">\t");
        }
        else
        {
            printf("\t");
        }
        printf("Mostrar quando quantas posições faltam: < ");
        if(conf->mostrarQuantoFalta == 1)
        {
            printf("ligado >\n");
        }
        else
        {
            printf("desligado >\n");
        }
        if(select == 2)
        {
            printf(">\t");
        }
        else
        {
            printf("\t");
        }
        printf("Permitir a remoção de jogadas: < ");
        if(conf->removerJogada == 1)
        {
            printf("ligado >\n");
        }
        else
        {
            printf("desligado >\n");
        }
        if(select == 3)
        {
            printf(">\t");
        }
        else
        {
            printf("\t");
        }
        printf("Mostrar possibilidades da posição atual: < ");
        if(conf->mostrarPossibilidades == 1)
        {
            printf("ligado >\n");
        }
        else
        {
            printf("desligado >\n");
        }
        digito = getch();
        if(digito == 'A' || digito == 'a')
        {
            if(select == 0 && conf->numeroPosicoesGeradas > 10)
            {
                conf->numeroPosicoesGeradas = conf->numeroPosicoesGeradas -1;
            }
            else if(select == 1 && conf->mostrarQuantoFalta == 1)
            {
                conf->mostrarQuantoFalta = 0;
            }
            else if(select == 2 && conf->removerJogada == 1)
            {
                conf->removerJogada = 0;
            }
            else if (select == 3 && conf->mostrarPossibilidades == 1)
            {
                conf->mostrarPossibilidades = 0;
            }
        }
        else if(digito == 'D' || digito == 'd')
        {
            if(select == 0 && conf->numeroPosicoesGeradas < 60)
            {
                conf->numeroPosicoesGeradas = conf->numeroPosicoesGeradas +1;
            }
            else if(select == 1 && conf->mostrarQuantoFalta == 0)
            {
                conf->mostrarQuantoFalta = 1;
            }
            else if(select == 2 && conf->removerJogada == 0)
            {
                conf->removerJogada = 1;
            }
            else if (select == 3 && conf->mostrarPossibilidades == 0)
            {
                conf->mostrarPossibilidades = 1;
            }
        }
        else if( (digito == 'W' || digito == 'w') && select > 0)
        {
            select--;
        }
        else if( (digito == 'S' || digito == 's') && select < 3 )
        {
            select++;
        }
    }
    while(digito == 'W' || digito == 'w' ||digito == 'A' ||digito == 'a' ||digito == 'S' ||digito == 's' ||digito == 'D' ||digito == 'd');

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
                printf("* * ");
            }
            else if(i == local->posX + 1 || i%3 == 0 && i > 0)
            {
                printf("* - ");
            }
            else
            {
                printf("- - ");
            }
        }
        else if(i%3 == 0 && i > 0)
        {
            printf("* - ");
        }
        else
        {
            printf("- - ");
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
            if(local->posY == i && local->posX == j)
            {
                printf("* %d ",puzzle[i][j]);
            }
            else if(local->posY == i && local->posX + 1 == j || j%3 == 0 && j>0)
            {
                printf("* %d ",puzzle[i][j]);
            }
            else
            {
                printf("| %d ",puzzle[i][j]);
            }
        }
        if(local->posY == i && local->posX == tam - 1)
        {
            printf("*\n");
        }
        else
        {
            printf("|\n");
        }
        for(j = 0; j < tam; j++)
        {
            if(local->posY == i || local->posY -1 == i )
            {
                if(local->posX == j || (i + 1)%3 == 0 && i > 0 && i < 8)
                {
                    printf("* * ");
                }
                else if(local->posX + 1 == j || j%3 == 0 && j > 0)
                {
                    printf("* - ");
                }
                else
                {
                    printf("- - ");
                }
            }
            else if((i + 1)%3 == 0 && i > 0 && i < 8)
            {
                printf("* * ");
            }
            else if(j%3 == 0 && j > 0)
            {
                printf("* - ");
            }
            else
            {
                printf("- - ");
            }
        }
        if(local->posY == i && local->posX == tam -1 || local->posY - 1 == i && local->posX == tam -1)
        {
            printf("*\n");
        }
        else
        {
            printf("-\n");
        }
    }

}
