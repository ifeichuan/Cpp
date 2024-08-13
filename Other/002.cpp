#include<stdio.h>
int f(int n){
	int i;
	if(n==1){
		return 0;
	}
	for(i=2;i<=n/2;i++){
		if(n%i==0){
			return n/i ;
		}
	}
	return 1;
}

int main(){	
	int n,i,s=0;
	scanf("%d",&n);
	for(i=n;i>0;i/=s){
		s+=f(i);
		printf("%d ",s);
	}
	printf("%d",s);
	return 0;
}
