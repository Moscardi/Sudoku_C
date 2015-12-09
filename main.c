#include "Sudoku.h"

void setSudoku(Puzzle* sudoku, Location* local){
    int i, x, y, tam = 4, n_elem = 9, elem, aux;
	srand(time(NULL));
	for(i = 0; i < (tam*n_elem); i++){
        x = rand()%n_elem;
        y = rand()%n_elem;
        if(!locationExists(local, x, y)){
            local = addLocation(local,x,y);
        }
        elem = rand()%n_elem + 1;
        aux = addNumberInPuzzle(sudoku, local, elem);
    }
    IpuzzleBoard(sudoku->puzzle);
}
int setJogada(Puzzle* sudoku, Location* local, int x, int y, int elem){
    int aux;
    if(!locationExists(local, x, y)){
            local = addLocation(local,x,y);
        }
    aux = addNumberInPuzzle(sudoku, local, elem);
    IpuzzleBoard(sudoku->puzzle);
    return aux;
}
int main(int argc, char const *argv[]) {
    int x, y, elem, jogada;
    Puzzle* sudoku = createNewPuzzle();
	Location* local = createLocation();
    setSudoku(sudoku, local);
    while(!IntegerListIsEmpty(sudoku->numLivresBloco)
          || !IntegerListIsEmpty(sudoku->numLivresColuna)
          || !IntegerListIsEmpty(sudoku->numLivresLinha)){
          if(jogada == 0)
            printf("\nNao eh possivel colocar \"%d\" na posicao %dx%d\n", elem, x, y);

          printf("\nDigite a posicao da coluna no tabuleiro: ");
          scanf("%d", &x);
          printf("\nDigite a posicao da linha no tabuleiro: ");
          scanf("%d", &y);
          printf("\nDigite o numero desejado: ");
          scanf("%d", &elem);
          jogada = setJogada(sudoku, local, x, y, elem);
    }
    printf("PARABENS, VOCE COMPLETOU O SUDOKU");
  return 0;
}
