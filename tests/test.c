#include<stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "../src/lake.h"
#include "../src/seed.h"
#define WIDTH 80
#define HEIGHT 40

int main(int argc, char* argv[]) {

	FILE *f = fopen("seeds/super.cell", "r");
	load_seed(f);
	display();

	printf("%d\n", gen(0,0,false));

}
