#ifndef LAKE_H
#define LAKE_H
#include<stdbool.h>
#define WIDTH 80
#define HEIGHT 40

int gen(int i, int c, bool dead);
void display();
void display_debug();
int population();
void zerolake();
extern int lake[HEIGHT][WIDTH];

#endif
