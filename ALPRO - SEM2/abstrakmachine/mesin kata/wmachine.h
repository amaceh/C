
int idx, wordlen;
char cword[50];

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

void RESETKATA(){
	wordlen=0; cword[wordlen]='\0';
}

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

char* GETCKATA(){
	return cword;
}

int GETPANJANGKATA(){
	return wordlen;
}

int EOPKATA(char pita[]){
	if(pita[idx]=='.')
	{
		return 1;
	}else{
		return 0;
	}
}