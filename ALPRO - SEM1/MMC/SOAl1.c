#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str1[2][50], str2[2][50];
	scanf("%s %s", str1[0], str1[1]);
	scanf("%s %s", str2[0], str2[1]);

	int i;
	int counvoc1=0, counvoc2=0, councons1=0, councons2=0;

	for (i = 0; i < strlen(str1[0]); ++i)
	{
		if (str1[0][i]=='a' || str1[0][i]=='i' 
				|| str1[0][i]=='u' || str1[0][i]=='e'
				|| str1[0][i]=='o')
		{
			counvoc1+=1;
		}
	}
	for (i = 0; i < strlen(str2[0]); ++i)
	{
		if (str2[0][i]=='a' || str2[0][i]=='i' 
				|| str2[0][i]=='u' || str2[0][i]=='e'
				|| str2[0][i]=='o')
		{
			counvoc2+=1;
		}
	}
	for (i = 0; i < strlen(str1[1]); ++i)
	{
		if (str1[1][i]!='a' || str1[1][i]!='i' 
				|| str1[1][i]!='u' || str1[1][i]!='e'
				|| str1[1][i]!='o')
		{
			councons1+=1;
		}	
	}

	for (i = 0; i < strlen(str2[1]); ++i)
	{
		if (str2[1][i]!='a' || str2[1][i]!='i' 
				|| str2[1][i]!='u' || str2[1][i]!='e'
				|| str2[1][i]!='o')
		{
			councons2+=1;
		}	
	}

	if (counvoc1==counvoc2 && counvoc1==counvoc2)
	{
		printf("KUA yuk\n");
	}else{
		printf("dadah :)\n");
	}
	return 0;
}		

6
<div>
<div>
</div>
<div>
</div>
</div>

4
</div>
<div>
</div>
<div>

5
<div>
</div>
<div>
<div>
</div>