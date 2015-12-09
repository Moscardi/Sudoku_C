#include "Interface.h"


int main(int argc, char const *argv[]) {
		int option = 0;
		Config* configaracao = createConfig();
		apresentation();

		do {
			option = generateInitialMenu();
			printf("%d", option);
			if(option == 0){
                starGame(configaracao);
			}else if(option == 1){
			}else if(option == 2){
                system("exit");
			}
		} while(option != '2');
}

void starGame(Config* configuracao){
    Puzzle* jogo = createNewPuzzle();
    generateSudoku(jogo,configuracao->numeroPosicoesGeradas);
    Location* atual = createLocation(0,0);
    char digito;
    do{
        showPuzzle(jogo->puzzle, atual);
        digito = getch();

    }while( digito != 'W' && digito != 'w' && digito != 'A' && digito != 'a' && digito != 'S' && digito != 's' && digito != 'D' && digito != 'd' && digito >= '0' && digito <= '9');
}
