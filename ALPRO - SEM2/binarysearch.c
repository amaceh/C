#include <stdio.h>

// void binarysearch(int x, int tabInt[x], int i, int j, int search){
// 	while(done==0 && i<=j){
// 		k=(int)(i+j)/2;//casting
// 		if (tabInt[k]==search)
// 		{
// 			ketemu=1;
// 		}else{
// 			if (tabInt[k]<bil_cari)
// 			{
// 				j=k-1;
// 			}else{
// 				i=k+1;
// 			}
// 		}
// 	}
// 	if (ketemu==1)
// 	{
// 		printf("ada\n");
// 	}else{
// 		printf("ndak ada\n");
// 	}
// }

int main()
{
	int tabInt[10]={15,18,23,28,28,34,67,67,89,98};
	//int tabInt[10]={98,89,67,67,34,28,28,23,18,15};
	int i=0, j=9, bil_cari, k, ketemu=0;
	bil_cari=67;
	while(ketemu==0 && i<=j){
		k=(int)(i+j)/2;//casting
		printf("hasil casting %d\n", k);
		if (tabInt[k]==bil_cari)
		{
			ketemu=1;
		}else{
			if (tabInt[k]>bil_cari)
			{
				j=k-1;
			}else{
				i=k+1;
			}
		}
	}
	if (ketemu==1)
	{
		printf("ada\n");
	}else{
		printf("ndak ada\n");
	}
	return 0;
}