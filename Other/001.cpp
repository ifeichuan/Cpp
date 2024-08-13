#include<stdio.h>
  #define N 5
  int main()
  { 
    long long n,s,sum=0;
    scanf("%ld",&n);
	while(n!=0)
	{
		s=n/5;
		sum+=s;
		n=s;
	}
	printf("%d",sum);
	return 0;
}
