
int count1=0, count2=0;
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

int EOP(){
	if (cc=='.')
	{
		return 0;
	}else{
		return 1;
	}
}

void CTBS(char str[]){
	if (cc==' ' && EOP()!=0)
	{
		count1+=1;
	}else if(EOP()!=0){
		count1=0;
	}
}

void DBS(){
	if (count1==2)
	{
		count2+=1;
		count1=0;
	}
}



int GC(){
	return count2;
}