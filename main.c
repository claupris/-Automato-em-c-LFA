//**************************************
// Name: NFA to DFA Conversion
// Description:It is a program for NFA ( Non-deterministic Finite Automata) to DFA (Deterministic Finite Auctomata ) Conversion using the Subset Construction Algorithm.
// By: Ritin (from psc cd)
//
// Inputs:NFA states, inputs, transitions
//
// Returns:DFA transition table
//**************************************

//NFA to DFA conversion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STATES 50

struct Dstate
{
	char name; // nome
	char StateString[STATES+1];  //Estado da string
	char trans[10];
	int is_final; //verifica se � o estado final
}Dstates[50];
struct tran
{
	char sym;
	int tostates[50];
	int notran;
};
struct state
{
	int no;
	struct tran tranlist[50];
};
int stackA[100],stackB[100],C[100],Cptr=-1,Aptr=-1,Bptr=-1;
struct state States[STATES];
char temp[STATES+1],inp[10];
int nos,noi,nof,j,k,nods=-1;
void pushA(int z)
{
	stackA[++Aptr]=z;
}
void pushB(int z)
{
	stackB[++Bptr]=z;
}
int popA()
{
	return stackA[Aptr--];
}
void copy(int i)
{
	char temp[STATES+1]=" ";
	int k=0;
	Bptr=-1;
	strcpy(temp,Dstates[i].StateString);
	while(temp[k]!='\0')
	{
		pushB(temp[k]-'0');
		k++;
	}
}
int popB()
{
	return stackB[Bptr--];
}
int peekB()
{
	return stackA[Bptr];
}
int peekA()
{
	return stackA[Aptr];
}
int seek(int arr[],int ptr,int s)
{
	int i;
	for(i=0;i<=ptr;i++)
	{
		if(s==arr[i])
			return 1;
	}
	return 0;
}
void sort()
{
	int i,j,temp;
	for(i=0;i<Bptr;i++)
	{
		for(j=0;j<(Bptr-i);j++)
		{
			if(stackB[j]>stackB[j+1])
			{
				temp=stackB[j];
				stackB[j]=stackB[j+1];
				stackB[j+1]=temp;
			}
		}
	}
}
void tostring()
{
	int i=0;
	sort();
	for(i=0;i<=Bptr;i++)
	{
		temp[i]=stackB[i]+'0';
	}
	temp[i]='\0';
}
void display_DTran()
{
	int i,j;
	printf("\nTabela de Transicoes AFD");
	printf("\n");
	printf("\nEstados\tEntradas\n ");
	for(i=0;i<noi;i++)
	{
		printf("\t%c",inp[i]);
	}
	printf("\n \t----------");
	for(i=0;i<nods;i++)
	{

		if(Dstates[i].is_final==0)
			printf("\n%c",Dstates[i].name);
		else
			printf("\n*%c",Dstates[i].name);

		//printf("\t%s",Dstates[i].StateString);
		for(j=0;j<noi;j++)
		{
			printf("\t%c",Dstates[i].trans[j]);
		}
        printf("\n");
	}
	printf("\n");
}
void move(int st,int j)
{
	int ctr=0;
	while(ctr<States[st].tranlist[j].notran)
	{
		pushA(States[st].tranlist[j].tostates[ctr++]);
	}
}
void lambda_closure(int st)
{
	int ctr=0,in_state=st,curst=st,chk;
	while(Aptr!=-1)
	{
		curst=popA();
		ctr=0;
		in_state=curst;
		while(ctr<=States[curst].tranlist[noi].notran)
		{
			chk=seek(stackB,Bptr,in_state);
			if(chk==0)
				pushB(in_state);
			in_state=States[curst].tranlist[noi].tostates[ctr++];
			chk=seek(stackA,Aptr,in_state);
			if(chk==0 && ctr<=States[curst].tranlist[noi].notran)
				pushA(in_state);
		}
	}
}
main()
{
	int final[20],start,fin=0,i;
	char c,ans,st[20];
	printf("\nDigite o numero de estados para o AFN : ");
	scanf("%d",&nos);
	for(i=0;i<nos;i++)
	{
		States[i].no=i;
	}
	printf("\nDigite o estado inicial : ");
	scanf("%d",&start);
	printf("\nDigite o numero de estados finais : ");
	scanf("%d",&nof);
	printf("\nDigite os estados finais : \n");
	for(i=0;i<nof;i++)
		scanf("%d",&final[i]);
	printf("\nDigite o numero de simbolos de entrada : ");
	scanf("%d",&noi);
	c=getchar();
	printf("\nDigite os simbolos de entrada : \n ");
	for(i=0;i<noi;i++)
	{
		scanf("%c",&inp[i]);
		c=getchar();
	}
	inp[i]='e';
	printf("\nDigite as transicoes : (-1 para sair)\n");
	for(i=0;i<nos;i++)
	{
		for(j=0;j<=noi;j++)
		{
			States[i].tranlist[j].sym=inp[j];
			k=0;
			ans='y';
			while(ans=='y')
			{
				printf("mover(%d,%c) : ",i,inp[j]);
				scanf("%d",&States[i].tranlist[j].tostates[k++]);
				if(States[i].tranlist[j].tostates[k-1]==-1)
				{
					k--;ans='n';
					break;
				}
			}
			States[i].tranlist[j].notran=k;
		}
	}
 //Conversoes
	i=0;nods=0;fin=0;
	pushA(start);
	lambda_closure(peekA());
	tostring();
	Dstates[nods].name='A';
	nods++;
	strcpy(Dstates[0].StateString,temp);
	while(i<nods)
	{
		for(j=0;j<noi;j++)
		{
			fin=0;
			copy(i);
			while(Bptr!=-1)
			{
				move(popB(),j);
			}
			while(Aptr!=-1)
				lambda_closure(peekA());
			tostring();
			for(k=0;k<nods;k++)
			{
				if((strcmp(temp,Dstates[k].StateString)==0))
				{
					Dstates[i].trans[j]=Dstates[k].name;
					break;
				}
			}
			if(k==nods)
			{
				nods++;
				for(k=0;k<nof;k++)
				{
					fin=seek(stackB,Bptr,final[k]);
					if(fin==1)
					{
						Dstates[nods-1].is_final=1;
						break;
					}									}
				strcpy(Dstates[nods-1].StateString,temp);
				Dstates[nods-1].name='A'+nods-1;
				Dstates[i].trans[j]=Dstates[nods-1].name;
			}
		}
		i++;
	}
	display_DTran();
	system("pause");
}
