#include<stdio.h>
#include<math.h> 
int main(void){
	double x;  
	printf("x=");
	scanf("%lf",&x); 
	int n=1;
	double sum=0;
	while(fabs((pow(x,n)/n))>0.000001){  //�p�G���n�[��������Ȥp��0.000001�N����A��U�h 
		sum+=pow(-1,n+1)/n*pow(x,n);     //sum�[�W�Ӷ����� 
		n++;                             //N+1 
	}
	if(n=1){                             //ln(1)=0
		sum=0;
	}
	printf("ans=%f\n",sum);                //��X����
	system("pause");
}
