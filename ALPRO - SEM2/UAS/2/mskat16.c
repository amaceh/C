/*
saya Achmad Abdul Rofiq tidak melakukan kecurangan
seperti yang telah dispesifikasikan pada mata kuliah
algoritma dan pemrograman 2 dalam mengerjakan maskat16 UAS,
jika saya melakukan kecurangan maka Allah adalah saksi
saya, dan saya menerima hukuman-Nya. aamin.
*/

/////mesin kata/////
int idx, wordlen;
char cword[50];


///star kata
void STARTKATA(char pita[]){
	idx=0; wordlen=0;
	while(pita[idx]==' '){
		idx+=1;
	}
	while(pita[idx]!=' ' && pita[idx]!='.'){
		cword[wordlen]=pita[idx];
		idx+=1; wordlen+=1;
	}
	cword[wordlen]='\0';
}
//reset kata
void RESETKATA(){
	wordlen=0; cword[wordlen]='\0';
}
//inc kata
void INCKATA(char pita[]){
	wordlen=0;
	while(pita[idx]==' '){
		idx+=1;
	}
	while(pita[idx]!=' ' && pita[idx]!='.'){
		cword[wordlen]=pita[idx];
		idx+=1; wordlen+=1;
	}
	cword[wordlen]='\0';
}
//fungsi cuurent kata
char* GETCKATA(){
	return cword;
}
//panjang kata
int GETPANJANGKATA(){
	return wordlen;
}
//end of process
int EOPKATA(char pita[]){
	if(pita[idx]=='.')
	{
		return 1;
	}else{
		return 0;
	}
}

/////////