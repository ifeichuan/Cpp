#include<stdio.h>

struct info{
	char name[100];
	int age;
	
};

typedef struct info info;
int main(){
	int max = 0;
	info infos[3];
	printf("请输入三组数据:\n");
	for(int i =0;i<3;i++){
		scanf("%s %d",&infos[i].name,&infos[i].age);
		if(infos[i].age>max) max = infos[i].age;
	}
	printf("Max age is %d",max);
}
