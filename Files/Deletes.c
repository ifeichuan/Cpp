#include<stdio.h>
#include<string.h>
void deletes(char *str,char ch){
	char *p = str;
	while(*p){
		if(*p != ch){
			*str = *p;
			str++;
		}
		p++;
		
	}
	*str = 0;
}

int main(){
	char str[] = "I Love Program Language!",ch;
	printf("������һ���ַ�");
	scanf("%c",&ch);
	deletes(str,ch);
	printf("%s",str);
}
