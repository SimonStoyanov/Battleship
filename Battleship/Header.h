#ifndef _ABC_
#define _ABC_


typedef struct{
	int hit;
	char content;
} grid;

grid **create_table(int x, int y);
void maping(grid **table, int x, int y);
void Sunk_log(grid **table, int x, int y, int aux1, int aux2);
void print_map(grid **table, int x, int y);
void attack(grid **table, int x, int y);

#endif