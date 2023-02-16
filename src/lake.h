#ifndef LAKE_H
#define LAKE_H
#include<stdbool.h>

#define WIDTH 80
#define HEIGHT 40

int gen(int i, int c, bool dead);
void copy_lake(int new[HEIGHT][WIDTH]);
void clear_all(int new[HEIGHT][WIDTH]);
void display();
void display_debug();
int population();
void zero_lake();
extern int lake[HEIGHT][WIDTH];

#endif
