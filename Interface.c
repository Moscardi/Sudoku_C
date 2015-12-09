#include "Interface.h"
#include "StringRow.h"

void Iapresentation(void){
  system("clear");
  printf("*   *   * ****     **    ****   *     *  ***  **** ****    **\n");
  printf("*   *   * *       *  *    *     **   ** *   *  *   *      *  *\n");
  printf("*   *   * *      ******    *    * * * * *   *   *  *     ****** \n" );
  printf("***  ***  ****  *      * ****   *  *  *  ***  **** **** *      *\n");
  printf("\n                       Produções\n" );
  int i =0;
  for (i = 0; i < 1000; i++);
}
void Ilogo(void){
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");

}
void IpuzzleBoard(int** puzzle){
  int i, j, tam = 9;
  system("cls");
  printf("    0   1   2   3   4   5   6   7   8 \n");
  printf("  -------------------------------------\n");
  for(i = 0; i < tam; i ++){
        printf("%d |", i);
    for(j = 0; j < tam; j++){
        if(puzzle[i][j] != 0){
            printf(" %d ", puzzle[i][j]);
        }
        else{
            printf("   ");
        }
        if((j+1)%3 == 0 && j != tam-1){
            printf("*");
        }
        else{
            printf("|");
        }
    }
    if((i+1)%3 == 0 && i != tam-1){
        printf("\n  *************************************\n");
    }
    else if(i != tam-1){
        printf("\n  ------------*-----------*------------\n");
    }
    else{
        printf("\n  -------------------------------------\n");
    }
  }
}
