#include<stdio.h>

int main(){
	FILE *fp = fopen("programming.txt","a");
	char str[100];
	scanf("%s",str);
	fputs(str,fp);
	fclose(fp);
	fp = fopen("programming.txt","r");
	fgets(str,100,fp);
	puts(str);
}
