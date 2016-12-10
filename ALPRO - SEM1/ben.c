#include <stdio.h>
#include <string.h>

int main() {
  char word[16];
  char excluse[16];


  strcpy(word, "1a2a3a4a5a6a7a8b9b");
  strcpy(excluse, "a");

  int wordlen = strlen(word);
  int exlen = strlen(excluse);
  int worditer;
  int exiter;
  int match = 0;

  for (worditer = 0; worditer < wordlen; worditer++) {
    // printf("now at word[%d]\n", worditer);
    for (exiter = 0; word[worditer + exlen * match + exiter] == excluse[exiter]; exiter++) {
      // printf("now at excluse[%d]\n", exiter);
      if (exiter == exlen -1) {
        match++;
        // printf("%d\n", matchindex);
      }
    }

    /* Might use conditional if here,
      so if worditer == worditer + exlen * matchindex
      no char array assignment needed.

      BUT! MUH PRECIOUS BYTES! */
    // if (match)
    word[worditer] = word[worditer + exlen * match ];
  }

  printf("%s, %d\n", word, strlen(word));



  return 0;
}