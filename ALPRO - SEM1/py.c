#include <string.h>
#include <stdio.h>
#include <math.h>

main() {
	char w[16];

	strcpy(w, "akudandiap");

	int l = sqrt(strlen(w));

	printf("%d\n", l);

	/*
   t
  his
 ispyr
amid
	*/

	int whitespace;
	int height;
	int wordindexer = 0;
	int worditerator;

	for (height = 0; height < l; height++) {
		for (whitespace = 0; whitespace < l - height; whitespace++) {
			printf(" ");
		}
		for (worditerator = 0; worditerator < height * 2 + 1; worditerator++) {
			printf("%c", w[wordindexer + worditerator]);
		}
		wordindexer += worditerator;
		printf("\n");
	}


}