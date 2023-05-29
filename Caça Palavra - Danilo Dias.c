#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define SIZE 10
#define WORDS 5
#define MAX_WORD_LENGTH 10

void initializeGrid(char grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = '-';
        }
    }
}

void printGrid(char grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void insertWord(char grid[SIZE][SIZE], char word[MAX_WORD_LENGTH]) {
    int length = strlen(word);
    int i, j;
    int startX, startY;
    int direction;

    do {
        startX = rand() % SIZE;
        startY = rand() % SIZE;
        direction = rand() % 8;
    } while (!isValidPosition(grid, startX, startY, direction, length));

    for (i = 0; i < length; i++) {
        switch (direction) {
            case 0: 
                grid[startX][startY + i] = word[i];
                break;
            case 1:
                grid[startX + i][startY] = word[i];
                break;
            case 2:
                grid[startX + i][startY + i] = word[i];
                break;
            case 3:
                grid[startX + i][startY - i] = word[i];
                break;
            case 4:
                grid[startX][startY - i] = word[i];
                break;
            case 5:
                grid[startX - i][startY] = word[i];
                break;
            case 6:
                grid[startX - i][startY - i] = word[i];
                break;
            case 7:
                grid[startX - i][startY + i] = word[i];
                break;
        }
    }
}

int isValidPosition(char grid[SIZE][SIZE], int startX, int startY, int direction, int length) {
    int i;
    switch (direction) {
        case 0:
            if (startY + length > SIZE) {
                return 0;
            }
            for (i = 0; i < length; i++) {
                if (grid[startX][startY + i] != '-') {
                    return 0;
                }
            }
            break;
        case 1:
            if (startX + length > SIZE) {
                return 0;
            }
            for (i = 0; i < length; i++) {
                if (grid[startX + i][startY] != '-') {
                    return 0;
                }
            }
            break;
        case 2:
            if (startX + length > SIZE || startY + length > SIZE) {
                return 0;
            }
            for (i = 0; i < length; i++) {
                if (grid[startX + i][startY + i] != '-') {
                    return 0;
                }
            }
            break;
        case 3:
            if (startX + length > SIZE || startY - length < 0) {
                return 0;
            }
            for (i = 0; i < length; i++) {
                if (grid[startX + i][startY - i] != '-') {
                    return 0;
                }
            }
            break;
        case 4:
            if (startY - length < 0) {
                return 0;
            }
            for (i = 0; i < length; i++) {
                if (grid[startX][startY - i] != '-') {
                    return 0;
                }
            }
            break;
        case 5:
            if (startX - length < 0) {
                return 0;
            }
            for (i = 0; i < length; i++) {
                if (grid[startX - i][startY] != '-') {
                    return 0;
                }
            }
            break;
        case 6:
            if (startX - length < 0 || startY - length < 0) {
                return 0;
            }
            for (i = 0; i < length; i++) {
                if (grid[startX - i][startY - i] != '-') {
                    return 0;
                }
            }
            break;
        case 7:
            if (startX - length < 0 || startY + length > SIZE) {
                return 0;
            }
            for (i = 0; i < length; i++) {
                if (grid[startX - i][startY + i] != '-') {
                    return 0;
                }
            }
            break;
    }
    return 1;
}

int checkWord(char grid[SIZE][SIZE], char word[MAX_WORD_LENGTH]) {
    int length = strlen(word);
    int i, j;

  
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j <= SIZE - length; j++) {
            if (strncmp(&grid[i][j], word, length) == 0) {
                return 1;
            }
        }
    }

    
    for (i = 0; i <= SIZE - length; i++) {
        for (j = 0; j < SIZE; j++) {
            char temp[MAX_WORD_LENGTH];
            int k;
            for (k = 0; k < length; k++) {
                temp[k] = grid[i + k][j];
            }
            temp[k] = '\0';
            if (strcmp(temp, word) == 0) {
                return 1;
            }
        }
    }

    
    for (i = 0; i <= SIZE - length; i++) {
        for (j = 0; j <= SIZE - length; j++) {
            char temp[MAX_WORD_LENGTH];
            int k;
            for (k = 0; k < length; k++) {
                temp[k] = grid[i + k][j + k];
            }
            temp[k] = '\0';
            if (strcmp(temp, word) == 0) {
                return 1;
            }
        }
    }

    
    for (i = 0; i <= SIZE - length; i++) {
        for (j = length - 1; j < SIZE; j++) {
            char temp[MAX_WORD_LENGTH];
            int k;
            for (k = 0; k < length; k++) {
                temp[k] = grid[i + k][j - k];
            }
            temp[k] = '\0';
            if (strcmp(temp, word) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int start(){
    char grid[SIZE][SIZE];
    char words[WORDS][MAX_WORD_LENGTH] = {"Jogo", "VIDA", "MOD", "LINGUAGEM", "PROGRAMA"};
    int i;

    srand(time(NULL));

    initializeGrid(grid);

    for (i = 0; i < WORDS; i++) {
        insertWord(grid, words[i]);
    }

    printf("Caça-Palavras\n\n");
    printf("Encontre as seguintes palavras:\n");
    for (i = 0; i < WORDS; i++) {
        printf("%s\n", words[i]);
    }
    printf("\n");

    printGrid(grid);

    printf("\n");

    char guess[MAX_WORD_LENGTH];
    for (i = 0; i < WORDS; i++) {
        printf("Digite uma palavra: ");
        scanf("%s", guess);

        if (checkWord(grid, guess)) {
            printf("Parabéns! Você encontrou a palavra!\n");
        } else {
            printf("Palavra não encontrada. Tente novamente.\n");
        }
    }

    return 0;
}

void menu(){
	int op;

  do {
    
  printf("##################################");
  printf("\n    -> Caça Palavra - Menu <-      ");
  printf("\n##################################");


  printf("\t\t\t\t\t\t\tVersão: 1.0");
  printf("\n\nAviso: Jogo ainda em desevolvimento v1.0!");
	printf("\nAviso: Recomendamos ver 'Como Jogar' antes de iniciar o Jogo!");

  printf("\n\n1 - Inicia Jogo");
  printf("\n2 - Como Jogar");
  printf("\n3 - Creditos");
  printf("\n4 - Update(Novo)");
  printf("\n0 - Sair");

  printf("\n\nEscolha uma das opções: ");
  scanf("%d", &op);

  system("cls");

  switch(op) {
    case 1:
      start();
      break;
    case 2:
      //comojogar();
      break;
    case 3:
	  	creditos();
      break;
    case 4:
      //update();
      break;
    default:
      printf("Informação inserida esta invalida");
      break;
  }
        
  system("cls");

  getch();

  system("cls");

  } while (op != 0);
}

void comojogar() {
	
	printf ( " #### #################################### " );
  printf ( " \n     -> Caça Palavra - Como Jogar <-       " );
  printf ( " \n #################################### #### \n\n " );

	printf ( " Teste " );
	printf ( " \n 1 - Escolhas as cordenadas de acordo quer é mostrado como exemplo (1 a 3)! " );
	printf ( " \n 2 - No Inicio do jogo sempre começa com o jogador um! " );
	//printf ( " \n 3 - Jogador Um 'X', Jogador Dois 'O'! " );

	printf ( " \n\n Aperte 'enter' para voltar. " );
	
	getch();
}

void creditos() {
	
  printf("######################################");
  printf("\n    -> Caça Palavra - Créditos <-      ");
  printf("\n######################################\n\n"); 

	printf("Autor: Danilo Dias");
	printf("\nGithub: TDaniloJ");
	printf("\nDireitos: Todos os direitos reservado ©");
	
	
	printf("\n\nAperte 'enter' para voltar.");
	getch();
}

int main() {
	setlocale(LC_ALL, "Portguese");

	menu();
}
