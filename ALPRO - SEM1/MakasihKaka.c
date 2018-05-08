#include<stdio.h>
#include<string.h>


int main (){
    char kata[105];
    int i,j,k,l,panjang,baris,spasi;

    scanf("%s",&kata);

    i = 1;
    baris = 1;
    panjang = 1;
    /*
    mencari batas kolom dan baris yang
    diperlukan untuk perulangan mencetak huruf
    */
    while (i<strlen(kata)){
        panjang+=1;
        baris+=2;
        i+=baris;
    }
    spasi = panjang-1;

    l = 0;
    for(i=0;i<baris;i++){
    for(j=0;j<panjang;j++){
        if(j<spasi){
            printf(" ");
        }else{
            /*rumus untuk penentuan huruf mana yang akan dicetak*/
            if(i<=baris/2){
                k = (j*j)+l;
                l++;
            }else{
                k = i + (j*j) - l;
                l--;
            }
            /*pencetakan huruf dan spasi*/
            if(k<strlen(kata)){
                printf("%c",kata[k]);
            }else{
                printf(" ");
            }
        }
    }
    /*menentukan batas pencetakan spasi*/
    if(i<baris/2){
        spasi--;
        l = 0;
    }
    else{
        spasi++;
        l = panjang - spasi - 1;
    }

    printf("\n");
}
return 0 ;
}