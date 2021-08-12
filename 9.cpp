#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void FIFO(char s[],char F[],int l,int f)
{

	int i,j=0,k,flag=0,ph=0,pf=0;
	printf("\nPAGE\tFRAMES\tFAULTS");
	for(i=0;i<l;i++)
	{
		for(k=0;k<f;k++)
			if(F[k]==s[i])
				flag=1;
		printf("\n%c\t",s[i]);
		if(flag==0)
		{
			F[j++]=s[i];
			printf("%s",F);
			printf("\tMiss");
			pf++;
		}
		else
		{
			flag=0;
			printf("%s",F);
			printf("\tHit");
			ph++;
		}
		if(j==f)
			j=0;

	}
	printf("\ntotal number of hits %d\n", ph);
	printf("total number of miss %d\n", pf);
}
int findLRU(int lru[],int f)
{
	int i,min=lru[0],pos=0;
	for(i=0;i<f;i++)
	{
		if(lru[i]<min)
		{
			min=lru[i];
			pos=i;
		}
	}
	return pos;
}
void lru(char s[],char F[],int l,int f)
{
	int i,c=0,k,flag1=0,flag2=0,faults=0,lru[10],pos,ph=0,pf=0;
	printf("\nPAGE\t FRAMES\t FAULTS");
	for(i=0;i<l;i++)
	{
		flag1=flag2=0;
		printf("\n%c\t",s[i]);
		for(k=0;k<f;k++)
		{
			if(F[k]==s[i])
			{
				c++;
				lru[k]=c;
				flag1=flag2=1;
				break;
			}
		}
		
		if(flag1==0)
		{
			for(k=0;k<f;k++)
			{
				if(F[k]==-1)
				{
					c++;
					faults++;
					F[k]=s[i];
					lru[k]=c;
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			pos=findLRU(lru,f);
			c++;
			faults++;
			F[pos]=s[i];
			lru[pos]=c;
		}
		for(k=0;k<f;k++)
			printf("%c",F[k]);
		if(flag1==0||flag2==0){
			printf("\tPageFault: %d",faults);
			pf++;
		}
		else{
			printf("\tNo page fault");
			ph++;
		}
	}
	printf("\ntotal number of hits %d\n", ph);
	printf("total number of miss %d\n", pf);

}
int main()
{

	int ch,i,l,f;
	char F[10],s[25];
	while(1)
	{
		printf("\nEnter:\n1:FIFO\n2:LRU\n3:EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the no. of frames: ");
				scanf("%d",&f);
				F[f]='\0';
				printf("Enter the string: ");
				scanf("%s",s);
				l = strlen(s);
				for(i=0;i<f;i++)
					F[i]=-1;
				FIFO(s,F,l,f);
				break;
				
			case 2: printf("Enter the no. of frames: ");
				scanf("%d",&f);
				F[f]='\0';
				printf("Enter the string: ");
				scanf("%s",s);
				l = strlen(s);
				for(i=0;i<f;i++)
					F[i]=-1;
				lru(s,F,l,f);
				break;
				
			case 3: exit(0);
		}
	}

}