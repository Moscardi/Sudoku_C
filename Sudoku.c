#include "Sudoku.h"

Puzzle* createNewPuzzle(void){
  int a,b;
  Puzzle* novo = (Puzzle*)malloc(sizeof(Puzzle));
  novo->posVazias = 9*9;
  novo->puzzle = (int**)malloc(sizeof(int*)*9);
  for ( a = 0; a < 9; a++) {
    novo->puzzle[a] = (int*)malloc(sizeof(int)*9);
  }
  novo->numLivresLinha = createIntegerList();
  novo->numLIvresColuna = createIntegerList();
  novo->numLivresBloco = createIntegerList();
  for (size_t a = 1; a < 10; a++) {
      addNumberInIntegerList(novo->numLivresLinha,a);
      addNumberInIntegerList(novo->numLIvresColuna,a);
      addNumberInIntegerList(novo->numLivresBloco,a);
  }
  for (a = 0; a < 9; a++) {
    for (size_t b = 0; b < 9; b++) {
      novo->puzzle[a][b] = 0;
    }
  }
  return novo;
}

void freePuzzle(Puzze* jogo){
  int a;
  for (size_t a = 0; a < 9; a++) {
    free(jogo->puzzle[a]);
  }
  free(jogo->puzzle);
  freeIntegerList(jogo->numLivresLinha);
  freeIntegerList(jogo->numLivresBloco);
  freeIntegerList(jogo->numLIvresColuna);
  free(jogo);
  jogo = NULL;
}

int addNumberInPuzzle(Puzze* jogo, Location* local, int number){
  if(jogo != NULL && local != NULL && number > 0 && number < 10 && local->posX >= 0 local->posX < 9 && local->posY >= 0 && local->posY < 9){
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
    if(numberExistInIntegerList(jogo->numLivresBloco[aux], number) == 1 && numberExistInIntegerList(jogo->numLivresLinha[local->posY], number) == 1 && numberExistInIntegerList(jogo->numLIvresColuna[local->posX],number) == 1){
      jogo->puzzle[local->posY][local->posX] = number;
      removeNumberOfIntegerList(jogo->numLivresLinha[local->posY], number);
      removeNumberOfIntegerList(jogo->numLIvresColuna[local->posX], number);
      removeNumberOfIntegerList(jogo->numLivresBloco[aux], number);
      return 1;
    }
  }
  return 0;
}

int removeNumberOfPuzzle(Puzze* jogo, Location* local){
  if(jogo != NULL && local != NULL && number > 0 && number < 10 && local->posX >= 0 local->posX < 9 && local->posY >= 0 && local->posY < 9){
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
    if(numberExistInIntegerList(jogo->numLivresBloco[aux], number) == 0 && numberExistInIntegerList(jogo->numLivresLinha[local->posY], number) == 0 && numberExistInIntegerList(jogo->numLIvresColuna[local->posX],number) == 0){
      jogo->puzzle[local->posY][local->posX] = 0;
      addNumberInIntegerList(jogo->numLivresLinha[local->posY], number);
      addNumberInIntegerList(jogo->numLIvresColuna[local->posX], number);
      addNumberInIntegerList(jogo->numLivresBloco[aux], number);
      return 1;
    }
  }
  return 0;
}
