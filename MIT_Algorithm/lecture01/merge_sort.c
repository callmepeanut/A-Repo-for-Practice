#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* When N > 1000, it becomes wrong, not clear why */
#define N 100

void init_num(int* num);
void merge_sort(int *num, int n, int *res);
int retn[N];
int main(void)
{
	int i;
	int inum[N];
	init_num(inum);
	/* int inum[N]={5,9,7,6,4,3,1,0,0,0}; */
	int retn[N];
	merge_sort(inum, N, retn);
	for(i=0;i<N;i++)
		printf("%d ",*(retn+i));
	printf("\n");
	return 0;
}

void init_num(int* num)
{
	int i;
	srand((int)time(0));
	for(i=0;i<N;i++)
		*(num+i)=rand()%100;
}

void merge_sort(int *num, int n, int *res)
{
	int i;
	int a1[n],b1[n];
	int *a, *b;
	char len_a=0, end_a=0;
	char len_b=0, end_b=0;
	int n1,n2;
	if(n%2){
		n1=n/2+1;
		n2=n/2;
	} else {
		n1=n2=n/2;
	}	

	if((n == 3) || (n == 2)){
		*a1=*num;
		if(n == 3)
			*(a1+1)=*(num+1);
		*b1=*(num+n1);
	} else {
		merge_sort(num,n1,a1);
		merge_sort((num+n1),n2,b1);
	}
	a=a1;
	b=b1;
	for(i=0;i<n;i++){
		if((*a<*b || end_b==1) && end_a==0){
			*(res+i)=*a;
			len_a++;
			if(len_a==n1)
				end_a=1;
			else
				a++;
		} else {
			*(res+i)=*b;
			len_b++;
			if(len_b==n2)
				end_b=1;
			else
				b++;
		}
	/*	printf("%d ", *(res+i)); */
	}
	/* printf("\n"); */
}
			
		
				
