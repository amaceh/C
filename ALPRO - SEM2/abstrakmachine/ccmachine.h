

int idx;
char cc;

void START(char str[]){
	idx=0;
	cc=str[idx];
}

void INC(char str[]){
	idx+=1;
	cc=str[idx];
}

void ADV(char str[]){
	idx+=1;
	cc=str[idx];
	while(cc==' ' && EOP()!=0)
		{
			idx+=1;
			cc=str[idx];
		}	
}

int EOP(){
	if (cc=='.')
	{
		return 0;
	}else{
		return 1;
	}
}

char GETCC(){
	return cc;
}

