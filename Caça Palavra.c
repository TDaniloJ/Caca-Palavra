#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void menu();
int cacaPalavras();
int graficoPalavras();

int main() {
	setlocale(LC_ALL, "portuguese");
	
	//menu();
	//graficoPalavras();
	cacaPalavras();
}

void menu() {
	int op;
	
	do {
	  printf("##################################");
	  printf("\n    -> Caça Palavras - Menu <-      ");
	  printf("\n##################################");
	
	  printf("\n\nAviso: Jogo ainda em desevolvimento v1.1 demo!");
		printf("\nAviso: Recomendamos ver como jogar antes de iniciar!");
	
	  printf("\n\n1 - Inicia Jogo");
	  printf("\n2 - Como Jogar");
	  printf("\n3 - Creditos");
	  printf("\n0 - Sair");
	
	  printf("\n\nEscolha uma das opções: ");
	  scanf("%d", &op);
	
	  system("cls");
	}while(op != 0);
}

int cacaPalavras() {
	char palavras [3][10] = {"Jogo","Time","Loja"};
	char aleatorio[25][15] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","X","Y","Z"};
	char letras[10][15];
	int l, c, linha, coluna;
	char adivinha;
	
	for(l = 0; l < 10; l++) {
		for(c = 0; c < 15; c++) {
			aleatorio[l][c] = 'A' + (char)(rand()%27);
		}
	}
	
	srand(time(NULL));
	
	graficoPalavras(aleatorio);
	
	for(linha = 0; linha < 10; linha++) {
		for(coluna = 0; coluna < 15; coluna++) {
			letras[linha][coluna] = palavras[linha][coluna];
		}
	}
	
	do {	
	printf("\nDigite uma Palavra: ");
	scanf("%c", &adivinha);
	}while(aleatorio == palavras);
	
	system("pause");

}

int graficoPalavras(char aleatorio[10][15]) {
	char palavras [10][15];
	
	printf("\n[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[0][0], aleatorio[0][1], aleatorio[0][2], aleatorio[0][3], aleatorio[0][4], aleatorio[0][5], aleatorio[0][6], aleatorio[0][7], aleatorio[0][8], aleatorio[0][9], aleatorio[0][10], aleatorio[0][11], aleatorio[0][12], aleatorio[0][13], aleatorio[0][14]);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[1][0], aleatorio[1][1], aleatorio[1][2], aleatorio[1][3], aleatorio[1][4], aleatorio[1][5], aleatorio[1][6], aleatorio[1][7], aleatorio[1][8], aleatorio[1][9], aleatorio[1][10], aleatorio[1][11], aleatorio[1][12], aleatorio[1][13], aleatorio[1][13]);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[2][0], aleatorio[2][1], aleatorio[2][2], aleatorio[2][3], aleatorio[2][4], aleatorio[2][5], aleatorio[2][6], aleatorio[2][7], aleatorio[2][8], aleatorio[2][9], aleatorio[2][10], aleatorio[2][11], aleatorio[2][12], aleatorio[2][13], aleatorio[2][13]);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[3][0], aleatorio[3][1], aleatorio[3][2], aleatorio[3][3], aleatorio[3][4], aleatorio[3][5], aleatorio[3][6], aleatorio[3][7], aleatorio[3][8], aleatorio[3][9], aleatorio[3][10], aleatorio[3][11], aleatorio[3][12], aleatorio[3][13], aleatorio[3][13]);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[4][0], aleatorio[4][1], aleatorio[4][2], aleatorio[4][3], aleatorio[4][4], aleatorio[4][5], aleatorio[4][6], aleatorio[4][7], aleatorio[4][8], aleatorio[4][9], aleatorio[4][10], aleatorio[4][11], aleatorio[4][12], aleatorio[4][13], aleatorio[4][13]);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[5][0], aleatorio[5][1], aleatorio[5][2], aleatorio[5][3], aleatorio[5][4], aleatorio[5][5], aleatorio[5][6], aleatorio[5][7], aleatorio[5][8], aleatorio[5][9], aleatorio[5][10], aleatorio[5][11], aleatorio[5][12], aleatorio[5][13]), aleatorio[5][13];
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[6][0], aleatorio[6][1], aleatorio[6][2], aleatorio[6][3], aleatorio[6][4], aleatorio[6][5], aleatorio[6][6], aleatorio[6][7], aleatorio[6][8], aleatorio[6][9], aleatorio[6][10], aleatorio[6][11], aleatorio[6][12], aleatorio[6][13], aleatorio[6][13]);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[7][0], aleatorio[7][1], aleatorio[7][2], aleatorio[7][3], aleatorio[7][4], aleatorio[7][5], aleatorio[7][6], aleatorio[7][7], aleatorio[7][8], aleatorio[7][9], aleatorio[7][10], aleatorio[7][11], aleatorio[7][12], aleatorio[7][13], aleatorio[7][13]);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[8][0], aleatorio[8][1], aleatorio[8][2], aleatorio[8][3], aleatorio[8][4], aleatorio[8][5], aleatorio[8][6], aleatorio[8][7], aleatorio[8][8], aleatorio[8][9], aleatorio[8][10], aleatorio[8][11], aleatorio[8][12], aleatorio[8][13], aleatorio[8][13]);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n", aleatorio[9][0], aleatorio[9][1], aleatorio[9][2], aleatorio[9][3], aleatorio[9][4], aleatorio[9][5], aleatorio[9][6], aleatorio[9][7], aleatorio[9][8], aleatorio[9][9], aleatorio[9][10], aleatorio[9][11], aleatorio[9][12], aleatorio[9][13], aleatorio[9][13]);

	
	system("pause");
	
}
