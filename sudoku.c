#include "Sudoku.h"

Puzzle* createNewPuzzle(void){
  int a,b;
  Puzzle* novo = (Puzzle*)malloc(sizeof(Puzzle));
  novo->posVazias = 9*9;
  novo->puzzle = (int**)malloc(sizeof(int*)*9);
  for ( a = 0; a < 9; a++) {
    novo->puzzle[a] = (int*)malloc(sizeof(int)*9);
  }
    novo->numLivresLinha = (IntegerList*)malloc(9*sizeof(IntegerList));
    novo->numLivresColuna = (IntegerList*)malloc(9*sizeof(IntegerList));
    novo->numLivresBloco = (IntegerList*)malloc(9*sizeof(IntegerList));
  for (a = 0; a < 9; a++) {
    novo->numLivresLinha[a] = createIntegerList();
    novo->numLivresColuna[a] = createIntegerList();
    novo->numLivresBloco[a] = createIntegerList();
  }
  for ( a = 0; a < 9; a++) {
        for ( b = 1; b < 10; b++) {
            novo->numLivresLinha[a] = addNumberInIntegerList(novo->numLivresLinha[a],b);
            novo->numLivresColuna[a] = addNumberInIntegerList(novo->numLivresColuna[a],b);
            novo->numLivresBloco[a] = addNumberInIntegerList(novo->numLivresBloco[a],b);
        }
  }
  for (a = 0; a < 9; a++) {
    for ( b = 0; b < 9; b++) {
      novo->puzzle[a][b] = 0;
    }
  }
  return novo;
}

void freePuzzle(Puzzle* jogo){
  int a;
  for ( a = 0; a < 9; a++) {
    free(jogo->puzzle[a]);
  }
  free(jogo->puzzle);
  for ( a = 0; a < 9; a++) {
    freeIntegerList(jogo->numLivresLinha[a]);
    freeIntegerList(jogo->numLivresBloco[a]);
    freeIntegerList(jogo->numLivresColuna[a]);
  }
  free(jogo);
  jogo = NULL;
}

int addNumberInPuzzle(Puzzle* jogo, Location* local, int number){
  if(jogo != NULL && local != NULL && number > 0 && number < 10 && local->posX >= 0 && local->posX < 9 && local->posY >= 0 && local->posY < 9){
    int aux;
    if(local->posY <= 2 && local->posX <= 2){
      aux = 0;
    }else if(local->posY <=2 && local->posX <= 5){
      aux = 1;
    }else if (local->posY <=2 && local->posX <= 8) {
      aux = 2;
    }else if (local->posY <=5 && local->posX <= 2) {
      aux = 3;
    } else if (local->posY <=5 && local->posX <= 5) {
      aux = 4;
    }else if (local->posY <=5 && local->posX <= 8) {
      aux = 5;
    } else if (local->posY <=8 && local->posX <= 2) {
      aux = 6;
    }else if (local->posY <=8 && local->posX <= 5) {
      aux = 7;
    } else if (local->posY <=8 && local->posX <= 8) {
      aux = 8;
    }
    if(numberExistInIntegerList(jogo->numLivresBloco[aux], number) == 1 && numberExistInIntegerList(jogo->numLivresLinha[local->posY], number) == 1 && numberExistInIntegerList(jogo->numLivresColuna[local->posX],number) == 1){
      jogo->puzzle[local->posY][local->posX] = number;
      jogo->posVazias--;
      jogo->numLivresLinha[local->posY] = removeNumberOfIntegerList(jogo->numLivresLinha[local->posY], number);
      jogo->numLivresColuna[local->posX] = removeNumberOfIntegerList(jogo->numLivresColuna[local->posX], number);
      jogo->numLivresBloco[aux] = removeNumberOfIntegerList(jogo->numLivresBloco[aux], number);
      return 1;
    }
  }
  return 0;
}

int removeNumberOfPuzzle(Puzzle* jogo, Location* local, int number){
  if(jogo != NULL && local != NULL && number > 0 && number < 10 && local->posX >= 0 && local->posX < 9 && local->posY >= 0 && local->posY < 9){
    int aux;
    if(local->posY <= 2 && local->posX <= 2){
      aux = 0;
    }else if(local->posY <=2 && local->posX <= 5){
      aux = 1;
    }else if (local->posY <=2 && local->posX <= 8) {
      aux = 2;
    }else if (local->posY <=5 && local->posX <= 2) {
      aux = 3;
    } else if (local->posY <=5 && local->posX <= 5) {
      aux = 4;
    }else if (local->posY <=5 && local->posX <= 8) {
      aux = 5;
    } else if (local->posY <=8 && local->posX <= 2) {
      aux = 6;
    }else if (local->posY <=8 && local->posX <= 5) {
      aux = 7;
    } else if (local->posY <=8 && local->posX <= 8) {
      aux = 8;
    }
    if(numberExistInIntegerList(jogo->numLivresBloco[aux], number) == 0 && numberExistInIntegerList(jogo->numLivresLinha[local->posY], number) == 0 && numberExistInIntegerList(jogo->numLivresColuna[local->posX],number) == 0){
      jogo->puzzle[local->posY][local->posX] = 0;
      jogo->posVazias++;
      jogo->numLivresLinha[local->posY] = addNumberInIntegerList(jogo->numLivresLinha[local->posY], number);
      jogo->numLivresColuna[local->posX] = addNumberInIntegerList(jogo->numLivresColuna[local->posX], number);
      jogo->numLivresBloco[aux] = addNumberInIntegerList(jogo->numLivresBloco[aux], number);
      return 1;
    }
  }
  return 0;
}
