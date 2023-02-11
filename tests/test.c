
#include<stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "lake.h"
#include "seed.h"
#define WIDTH 80
#define HEIGHT 40


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

	FILE *f = fopen("test.txt", "r");
	load_seed(f);
	display();

}
