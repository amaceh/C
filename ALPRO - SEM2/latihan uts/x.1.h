#include <stdio.h>
#include <string.h>

typedef struct
{
	char str[50];
	int conso;
}tab;

void consocounter(int n, tab a[n]);
void bublesort(int x, tab a[x]);
void insertionsort(int x, tab a[x]);
void selectionsort(int x, tab a[x]);
void quicksortpinggir(int x, tab a[x], int l, int r);