#include<stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>
#include<time.h>
#include "lake.h"
#include "seed.h"


//int lake[HEIGHT][WIDTH];
//int lake[HEIGHT][WIDTH] =
//{
//{0,0,1,0,0},
//{1,1,0,1,1},
//{0,1,0,1,0},
//{0,0,1,0,0},
//};

//int lake[HEIGHT][WIDTH] =
//{
//{0,0,0,1,0,0,0},
//{0,1,1,0,1,1,0},
//{0,0,1,0,1,0,0},
//{0,0,0,1,0,0,0}
//};
int main(int argc, char* argv[]) {

	zerolake();
	printf("%d\n", lake[0][2]);
	printf("%d\n", gen(12, 11, true));
	
	//FILE *f = NULL;
	//printf("%d\n", argc);
	//if (argc > 1) {
	//	FILE* f = fopen(argv[1], "r");
	//} else {
	//	FILE* f = fopen("test.txt", "r");
	//}

	FILE* f = NULL;
	int speed = 100;
	bool random = false;
	if (argc > 1) {
		if (!strcmp(argv[1], "random")) {
			random = true;
		} else {
			f = fopen(argv[1], "r");
			speed = atoi(argv[2]);
		}
	} else {
		random = true;
	}

	if (random) {
		seed();
	} else {
		load_seed(f);
	}

	int z = 0;
	int i, c;
	int new[HEIGHT][WIDTH];
	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			new[i][c] = lake[i][c];
		}
	}

	while (z <= 1000) {
		system("clear");
		display();
		printf("Population: %d\n", population());
		usleep(speed * 1000);
		for (i = 0; i < HEIGHT; i++) {
			for (c = 0; c < WIDTH; c++) {
				if (lake[i][c] == 1) {
					if (!gen(i, c, false)) {
					//	printf("dies\n");
						new[i][c] = 0;
					}
				} else {
					if(gen(i, c, true)) {
					//	printf("revive\n");
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
		z++;
	}

	if (f != NULL) {
		fclose(f);
	} 


}
