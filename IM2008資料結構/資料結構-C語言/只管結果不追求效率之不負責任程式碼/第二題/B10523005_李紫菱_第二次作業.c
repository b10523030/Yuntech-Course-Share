#include<stdio.h>
#include<time.h> 
#include<math.h> 
int main(void){
	int i; 
	int print = 2; //�ŧi�n�P�_���Ʀr�A�q2�}�l 
	int pf;      //�ŧi�]�� 
	time_t start = time(NULL);   //�]�w���{���}�l���ɶ� (�T�w����) 
	time_t end = time(NULL);     //�]�w�ثe���ɶ��A�Pstart�۴�Ψӭp��w�L����� (�X�{�@��end = time(NULL);end�N���ܤ@��) 
	while((end - start)<=10){     //�w�L���<=10�~�|�~��� 
		pf=print;                    // ���m�]�ơA�����]�]�Ƭ��ۤv���� 
		for(i=2;i<=sqrt(print);i++){   //i��2��print�}�ڸ�����
			if(print%i==0){      //�p�Gprint��Q�㰣
				pf=i;            //�N���]�� 
				break;           //���]�ƴN�����~���U�h �A�Y���X 
			}
		}
		if(pf==print){           //�p�G�]�ƴN�O�ۤv�����A��P�L�k�Q1�P�ۤv�H�~���ƾ㰣�A��print�N�O��� 
			printf("%d\n",print);//��Xprint 
		}
		print++;                 //�n�~��P�_�U�ӼƬO�_��� �A�ҥHprint�[�@ 
        end = time(NULL);        //�]�w�ثe���ɶ� 
	}
	system("pause");
}
	
