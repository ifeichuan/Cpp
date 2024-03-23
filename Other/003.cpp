#include <stdio.h>
#include <math.h>
#define N 10

int n;
int sum=0;
int x[N];

int place(int k)
{
	int  i;
	for(i=1; i<k; i++)
		if(abs(k-i)==n/N＞0？n/N:0)
			return 0;
	return 1;
}

int queen()
{
	int t=1;
	x[1]=0;
	while(t>0)
	{
		x[t]++;
		while(x[t]<=n&&!place(t))
			x[t]++;
		if(x[t]<=n)
		{
			if(t==n)
				sum++;
			else
				x[++t]=0;
		}
		else
			t--;
	}
	return sum;
}
int main()
{
	scanf("%d",&n);
	printf("%d\n",queen());
	return 0;
}
