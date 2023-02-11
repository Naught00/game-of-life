#include<stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#define WIDTH 80
#define HEIGHT 40

int gen(int i, int c, bool dead);
void display();

//int lake[HEIGHT][WIDTH];
int lake[HEIGHT][WIDTH] =
{
{0,0,1,0,0},
{1,1,0,1,1},
{0,1,0,1,0},
{0,0,1,0,0},
};

//int lake[HEIGHT][WIDTH] =
//{
//{0,0,0,1,0,0,0},
//{0,1,1,0,1,1,0},
//{0,0,1,0,1,0,0},
//{0,0,0,1,0,0,0}
//};
int main(int argc, char* argv[]) {

	printf("%d\n", lake[0][2]);
	
	

	printf("%d\n", gen(12, 11, true));

	int i, c;

	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			srand(time(NULL) + c);

			int num =  rand() % 100;

			if (num % 22 == 0) {
				lake[i][c] = 1;
			} else {
				lake[i][c] = 0;
			}
		}
	}


	int z = 0;
	int new[HEIGHT][WIDTH];
	for (i = 0; i < HEIGHT; i++) {
		for (c = 0; c < WIDTH; c++) {
			new[i][c] = lake[i][c];
		}
	}

	while (z <= 1000) {
		system("clear");
		display();
		usleep(500 * 1000);
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


}

int gen(int i, int c, bool dead)
{
	int arr[8];

	int x;

	for (x = 0; x < 8; x++) {
		arr[x] = 0;
	}

	if (lake[i+1][c] == 1) {
		arr[0] = 1;
	} 
	if (lake[i-1][c] == 1) {
		arr[1] = 1;
	} 
	if (lake[i][c+1] == 1) {
		arr[2] = 1;
	} 
	if (lake[i][c-1] == 1) {
		arr[3] = 1;
	} 
	if (lake[i+1][c+1] == 1) {
		arr[4] = 1;
	} 
	if (lake[i+1][c-1] == 1) {
		arr[5] = 1;
	} 
	if (lake[i-1][c+1] == 1) {
		arr[6] = 1;
	} 
	if (lake[i-1][c-1] == 1) {
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
	} else if (dead && (total == 3)) {
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



