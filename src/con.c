#include<stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>
#include<time.h>
#include "lake.h"
#include "csv.h"
#include "seed.h"

void simulate(int speed);

int main(int argc, char* argv[])
{
	zero_lake();
	
	FILE* cell = NULL;

	int speed = 100;
	int factor = 2;
	bool random = false;
	if (argc > 2) {
		if (!strcmp(argv[1], "random")) {
			random = true;
			factor = atoi(argv[2]);
		} else {
			cell = fopen(argv[1], "r");
			speed = atoi(argv[2]);
		}
	} else {
		random = true;
	}

	if (random) {
		seed(factor);
	} else {
		load_seed(cell);
	}

	simulate(speed);

	if (cell != NULL) {
		fclose(cell);
	} 

}

void simulate(int speed)
{
	FILE* csv = fopen("out.csv", "w");

	int tick = 0;
	int i, c;
	int new[HEIGHT][WIDTH];
	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			new[i][c] = lake[i][c];
		}
	}

	while (tick <= 1000) {
		system("clear");
		display();
		printf("Population: %d\n", population());
		write_csv(tick, population(), csv);
		usleep(speed * 1000);
		for (i = 0; i < HEIGHT; i++) {
			for (c = 0; c < WIDTH; c++) {
				if (lake[i][c] == 1) {
					if (!gen(i, c, false)) {
						new[i][c] = 0;
					}
				} else {
					if(gen(i, c, true)) {
						new[i][c] = 1;
					}
				}
			}
		}
		for (i = 0; i < HEIGHT; i++) {
			for (c = 0; c < WIDTH; c++) {
				lake[i][c] = new[i][c];
			}
		}
		tick++;
	}
	fclose(csv);
}
