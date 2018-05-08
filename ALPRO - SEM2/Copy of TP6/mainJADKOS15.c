#include "JADKOS15.h"

int main()
{
	int i, x;
	schedule tab[128];
	int sparetime[5][11];
	def(sparetime);
	scanf("%d", &x);
	for (i = 0; i < x; i+=1)
	{
		scanf("%d", &tab[i].days);//input hari
		scanf("%d", &tab[i].start);//input jam mulai sibuk
		scanf("%d", &tab[i].end);//input akhir jam sibuk
	}
	writethetime(x, tab, sparetime);
	scanf("%d", &x);
	for (i = 0; i < x; i+=1)
	{
		scanf("%d", &tab[i].days);//input hari
		scanf("%d", &tab[i].start);//input jam mulai sibuk
		scanf("%d", &tab[i].end);//input akhir jam sibuk
	}
	writethetime(x, tab, sparetime);
	scanf("%d", &x);
	for (i = 0; i < x; i+=1)
	{
		scanf("%d", &tab[i].days);//input hari
		scanf("%d", &tab[i].start);//input jam mulai sibuk
		scanf("%d", &tab[i].end);//input akhir jam sibuk
	}
	writethetime(x, tab, sparetime);
	finalsearch(sparetime);
	return 0;
}