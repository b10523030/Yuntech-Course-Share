#include<stdio.h>
#include<iostream>
#include<time.h>
#include<math.h>
#include<conio.h>
int main(){
	int x=2,num,i;
	double end;
	while((clock()/CLOCKS_PER_SEC)<10.0){
		for(i=2;i<sqrt(x);i++){
			if(x%i==0){
				break;
			}
		}
		if(i>=sqrt(x)){
			num=x;
			
			
		}
		x++;
	}
	end=clock()/CLOCKS_PER_SEC;
	printf("��ƬO%d\n",num);
	printf("��F%.2f��",end);
	
}
