#include <stdio.h>
#include <string.h>

typedef struct
{
	char str[50];
	int conso;
}tab1;
typedef struct
{
	char str[50];
	int conso;
}tab2;
typedef struct
{
	char str[50];
	int conso;
}tab3;

void consocounter1(int n, tab1 a[n]);
void consocounter2(int n, tab2 b[n]);
void consocounter3(int n, tab3 c[n]);

void bublesort1(int x, tab1 a[x]);
void insertionsort1(int x, tab1 a[x]);
void selectionsort1(int x, tab1 a[x]);
void quicksortpinggir1(int x, tab1 a[x], int l, int r);

void bublesort2(int x, tab2 b[x]);
void insertionsort2(int x, tab2 b[x]);
void selectionsort2(int x, tab2 b[x]);
void quicksortpinggir2(int x, tab2 b[x], int l, int r);

void bublesort3(int x, tab3 c[x]);
void insertionsort3(int x, tab3 c[x]);
void selectionsort3(int x, tab3 c[x]);
void quicksortpinggir3(int x, tab3 c[x], int l, int r);

