#include<stdio.h>

void write_csv(int tick, int population, FILE* f)
{
	char stick[10];
	sprintf(stick, "%d", tick);

	char spop[10];
	sprintf(spop, "%d", population);

	fputs(stick, f);
	fputc(',', f);
	fputs(spop, f);
	fputc('\n', f);



}
