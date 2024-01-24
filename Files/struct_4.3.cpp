#include<stdio.h>
struct student{
	int xuehao = 101;
	double score;
}students[10];
void avg(student students[]){
	double sum = 0;
	for(int i=0;i<10;i++){
		sum+=students[i].score;
	}
	printf("%.2lf ",sum/10.0);
}
int main(){
	double sum = 0;
	for(int i=0;i<10;i++){
		students[i].xuehao +=i;
		scanf("%lf",&students[i].score);
		sum += students[i].score;
	}
	avg(students);
}
