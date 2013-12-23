/*
 * insertSort.c
 * writed by hrq
 * Date:2013-12-08
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int num[N];
void initRand(int *num);
void sort(int *num);

int main(void)
{
	initRand(num);
	sort(num);
	return 0;
}

void initRand(int *num)
{
	int i;
	srand((int)time(0));
	for(i=0;i<N;i++)
		*(num+i)=rand()%100;
}

/* insert sort */
void sort(int *num)
{
	int i,j;
	int key;
	for(i=1;i<N;i++){
		key=*(num+i);
		j=i-1;
		while(j>=0 && *(num+j)>key){
			*(num+j+1)=*(num+j);
			j-=1;
		}
		*(num+j+1)=key;
	}
	for(i=0;i<N;i++)
		printf("%d ",*(num+i));
	printf("\n");
}
