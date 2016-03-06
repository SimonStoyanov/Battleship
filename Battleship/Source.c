#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int x, y;
	printf("Welcome to Battleship. The instructons are easy, give a coord X and coord Y \nrespectively to shoot on them and sink a ship.\nThere are 4 ships of 1, 2, 3 and 4 blocks.\n");
	printf("Which will be the size of the map(x, y)? ");
	scanf_s("%i %i", &x, &y);

	grid **table = create_table(x, y);

	attack(table, x, y);

	free(table);
	system("pause");
	return 0;
}