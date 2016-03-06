#include <stdio.h>
#include "Header.h"

grid **create_table(int x, int y){
	grid **table;
	int aux1, aux2;

	table = (grid **)malloc(x * sizeof(grid *));
	if (table == 0){
		printf("There is no free memory\n");
		return 0;
	}
	for (aux1 = 0; aux1 < x; aux1++){
		table[aux1] = (grid *)malloc(sizeof(grid)*y);
	}

	maping(table, x, y);

}
void maping(grid **table, int x, int y){
	int aux1, aux2, direction;
	
	for (aux1 = 0; aux1 < x; aux1++){
		for (aux2 = 0; aux2 < y; aux2++){
			table[aux1][aux2].content = '~';
			table[aux1][aux2].hit = 0;
		}
	}

	srand(time(NULL));
	aux1 = rand() % x;
	aux2 = rand() % y;
	direction = rand() % 4;				// 0 -> East, 1 -> West, 2 -> North, 3 -> South
	//D
	if ((aux1 + 4 < x && direction == 0) || (aux1 - 4 >= 0 && direction == 1) || (aux2 + 4 < y && direction == 3) || (aux2 - 4 >= 0 && direction == 2)){
		if (aux1 + 4 < x){
			direction = 0;
		}
		else if (aux1 - 4 >= 0){
			direction = 1;
		}
		else if (aux2 + 4 < y){
			direction = 3;
		}
		else{
			direction = 2;
		}
	}
	int i;
	for (i = 0; i < 4; i++){
		if (direction = 0){
			table[aux1 + i][aux2].content = 'D';
		}
		else if (direction = 1){
			table[aux1 - i][aux2].content = 'D';
		}
		else if (direction = 2){
			table[aux1][aux2 - i].content = 'D';
		}
		else{
			table[aux1 + i][aux2 + i].content = 'D';
		}
	}
	//C
	Viri:
	aux1 = rand() % x;
	aux2 = rand() % y;
	direction = rand() % 4;
	while (table[aux1][aux2].content != '~' && ((aux1 + 3 < x && direction == 0) || (aux1 - 3 >= 0 && direction == 1) || (aux2 + 3 < y && direction == 3) || (aux2 - 3 >= 0 && direction == 2))){
		if (aux1 + 3 < x){
			direction = 0;
		}
		else if (aux1 - 3 >= 0){
			direction = 1;
		}
		else if (aux2 + 3 < y){
			direction = 3;
		}
		else if(aux2 - 3 >= 0){
			direction = 2;
		}
		else{
			goto Viri;
		}
	}
	for (i = 0; i < 3; i++){
		if (direction = 0){
			table[aux1 + i][aux2].content = 'C';
		}
		else if (direction = 1){
			table[aux1 - i][aux2].content = 'C';
		}
		else if (direction = 2){
			table[aux1][aux2 - i].content = 'C';
		}
		else{
			table[aux1 + i][aux2 + i].content = 'C';
		}
	}
	//B
	Ato:
	aux1 = rand() % x;
	aux2 = rand() % y;
	direction = rand() % 4;
	while (table[aux1][aux2].content != '~' && ((aux1 + 2 < x && direction == 0) || (aux1 - 2 >= 0 && direction == 1) || (aux2 + 2 < y && direction == 3) || (aux2 - 2 >= 0 && direction == 2))){
		if (aux1 + 2 < x){
			direction = 0;
		}
		else if (aux1 - 2 >= 0){
			direction = 1;
		}
		else if (aux2 + 2 < y){
			direction = 3;
		}
		else if (aux2 - 2 >= 0){
			direction = 2;
		}
		else{
			goto Ato;
		}
	}
	for (int i = 0; i < 2; i++){
		if (direction = 0){
			table[aux1 + i][aux2].content = 'B';
		}
		else if (direction = 1){
			table[aux1 - i][aux2].content = 'B';
		}
		else if (direction = 2){
			table[aux1][aux2 - i].content = 'B';
		}
		else{
			table[aux1 + i][aux2 + i].content = 'B';
		}
	}
	aux1 = rand() % x;
	aux2 = rand() % y;
	while (table[aux1][aux2].content != '~'){
		aux1 = rand() % x;
		aux2 = rand() % y;
	}
	table[aux1][aux2].content = 'A';
}
void Sunk_log(grid **table, int x, int y, int aux1, int aux2){
	int aux = 0;
	if (table[aux1][aux2].content == "~"){
		printf("Chof!\n");
	}
	else{
		printf("Hit!");
		char ship = table[aux1][aux2].content;
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				if (table[i][j].content == ship && table[i][j].hit == 1){
					aux++;
				}
			}
		}
		switch (ship)
		{
		case 'A':
			printf(" & Sunk");
			break;
		case 'B':
			if (aux == 2){
				printf(" & Sunk");
			}
			break;
		case 'C':
			if (aux == 3){
				printf(" & Sunk");
			}
			break;
		default:
			if (aux == 4){
				printf(" & Sunk");
			}
		}
		printf("\n");
	}
}
void print_map(grid **table, int x, int y){
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			if (table[i][j].hit == 1){
				printf("%c|", table[i][j].content);
			}
			else{
				printf(" |");
			}
		}
		printf("\n");
	}
}
void attack(grid **table, int x, int y){
	int aux1, aux2;
	printf("Apprentice, where shall we attack(x, y)? ");
	scanf_s("%d %d", &aux1, &aux2);
	if (aux1 >= 0 && aux1 < x && aux2 >= 0 && aux2 < y){
		if (table[aux1][aux2].hit == 0){
			table[aux1][aux2].hit = 1;
			Sunk_log(table, x, y, aux1, aux2);
		}
		else{
			printf("You fool! We have alreaday hit that target!\n");
		}
	}
	else{
		printf("You missed! How could you miss that?\n");
	}
}