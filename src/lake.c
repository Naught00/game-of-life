#include<stdio.h>
#include "lake.h"

int lake[HEIGHT][WIDTH];

int gen(int i, int c, bool dead)
{
	int arr[8];
	int x;

	for (x = 0; x < 8; x++) {
		arr[x] = 0;
	}

	if (lake[i+1][c] == 1 && i != HEIGHT - 1) {
		arr[0] = 1;
	} 
	if (lake[i-1][c] == 1 && i != 0) {
		arr[1] = 1;
	} 
	if (lake[i][c+1] == 1 && c != WIDTH - 1) {
		arr[2] = 1;
	} 
	if (lake[i][c-1] == 1 && c != 0) {
		arr[3] = 1;
	} 
	if (lake[i+1][c+1] == 1 && i != HEIGHT - 1 && c != HEIGHT - 1) {
		arr[4] = 1;
	} 
	if (lake[i+1][c-1] == 1 && i != HEIGHT - 1 && c != 0) {
		arr[5] = 1;
	} 
	if (lake[i-1][c+1] == 1 && i != 0 && c != HEIGHT - 1) {
		arr[6] = 1;
	} 
	if (lake[i-1][c-1] == 1 && i != 0 && c != 0) {
		arr[7] = 1;
	} 

	int total = 0;
	for (x = 0; x < 8; x++) {
		total += arr[x];
	}

	if ((total == 2 || total == 3) && !dead) {
		return 1;
	} else if (total < 2) {
		return 0;
	} else if (total > 3) {
		return 0;
	} else if (dead && total == 3) {
		return 1;
	}

	return 0;
}

void display() {
	int i, c;
	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			 if (lake[i][c] == 1) {
				 printf("██");
			 } else {
				 printf("  ");
			 }
			 if (c == WIDTH-1) {
				 printf("\n");
			 }
		}
	}
}
void display_debug() {
	int i, c;
	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			 if (lake[i][c] == 1) {
				 printf("**");
			 } else {
				 printf("  ");
			 }
			 if (c == WIDTH-1) {
				 printf("\n");
			 }
		}
	}
}

int population()
{
	int i, c;
	int pop = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			 if (lake[i][c] == 1) {
				 pop += 1;
			 }
		}
	}
	return pop;
}

void zero_lake()
{
	int i, c;
	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			lake[i][c] = 0;
		}
	}
}
