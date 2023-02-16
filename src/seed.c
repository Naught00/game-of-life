#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "lake.h"

void seed(int factor) {

	int i, c;
	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			srand(time(NULL) + c);
			int num =  rand() % 100;

			if (num % factor == 0) {
				lake[i][c] = 1;
			} else {
				lake[i][c] = 0;
			}
		}
	}
}

void load_seed(FILE* f) 
{
	char c;
	int x, y;

	for (y = 0, x = 0; (c = getc(f)) != EOF;) {
		if (c == '.' || c == '.') {
			lake[y][x] = 0;
			x++;
		} 
		if (c == 'O' || c == '0') {
			lake[y][x] = 1;
			x++;
		} 

		if (c == '\n') {
			y++;
			x = 0;
		}
	}

	rewind(f);

}
