#include<stdio.h>
#include<windows.h>
#include<string.h>
int main(){
	FILE *fp;
	int m,xuehao,f1,f2,s;
	char str[100];
	while(1){
	
	printf("\t\t选择模式\n\t(1) 录入\t(2) 读取\n\t(0) 退出\n请输入:");
	scanf("%d",&m);
	if(m==1){
	if(fp=fopen("xuansou.txt","r")==NULL){
		exit(0);
	}
	char ch;
	ch = fgetc(fp);
	fclose(fp);
	if(ch==EOF){
		fp = fopen("xuansou.txt","a");
		printf("请依次输入 学号 姓名 评委打分 选手得分 排名:\n");
		scanf("%d %s %d %d %d",&xuehao,str,&f1,&f2,&s);
		fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",xuehao,str,f1,f2,s);
	}
		fclose(fp);
			system("cls");
	}

	
	
	else if(m==2){
		fp = fopen("xuansou.txt","r+");
		fgets(str,1000,fp);
		printf("%s",str);
		while(fscanf(fp,"%d %s %d %d %d",&xuehao,str,&f1,&f2,&s)!=EOF)
		printf("%d\t%s\t%d\t\t%d\t\t%d\n",xuehao,str,f1,f2,s);
	//	system("cls");
		
		
	}
	else if(m == 0){
		exit(0);
	}
	else{
		printf("输入错误,请重新输入");
		}
	}
	
}
