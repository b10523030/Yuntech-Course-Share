#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{    //�ŧistruct���c�A�]�tid�Blink 
		char id;
		struct node *link;
	};
int main(void){
    //�ŧifront(�쵲�}��) new_node(�s���쵲) rear(�쵲����)�ϥ�node���c 
	struct node *front, *new_node,*rear,*temp_node,*this_node;
	front =(struct node *) malloc(sizeof(struct node));
	rear =(struct node *) malloc(sizeof(struct node));
	temp_node =(struct node *) malloc(sizeof(struct node));
	this_node =(struct node *) malloc(sizeof(struct node));
	//�ŧi�ƻs�Ϊ��쵲 
	struct node *front_c, *new_node_c,*rear_c,*temp_node_c,*this_node_c;
	front_c =(struct node *) malloc(sizeof(struct node));
	rear_c =(struct node *) malloc(sizeof(struct node));
	this_node_c =(struct node *) malloc(sizeof(struct node));
	temp_node_c =(struct node *) malloc(sizeof(struct node));
	//��l��front rear��link���� 
	front->link = NULL;
	rear->link = NULL;
	char input='\0';
	int count =0;   //�`�I�Ӽ� 
	int countO =0;  //�n�U�����H�� 
	//�@����J�@�ӡAS=Stop �A�ҥH���J��S�N�����J�A�ö}�l�p�⯫�_�Ʀr 
	printf("�гv�@��J�n�ƤJ���H(O��X)(��JS�����J)�G\n");
	scanf(" %c",&input); //�e���n�O�o�[�ťաA���M�|scanf��h�l�� 
	printf("%c\n",input);
	while(input!='S'){
		//�p�G�OO/X�~��L�[���쵲���A��l��ܿ��~�A�ýШϥΪ̭��s��J 
		if((input =='O')||(input=='X')){ 
			if(input =='O'){
				countO ++;
			}
			//�H�U���W�[�s�쵲�{���X 
			new_node =(struct node *) malloc(sizeof(struct node));
			new_node->id=input;
			new_node->link = NULL;
			if(front->link == NULL){
				front->link =new_node;
				rear->link =new_node;
			}else{
				temp_node=rear->link ;
				temp_node->link =new_node;
				rear->link =new_node;
			}
			//�H�W���W�[�s�쵲�{���X  
			count++;	
			printf("�гv�@��J�n�ƤJ���H(O��X)(��JS�����J)�G\n");
			scanf(" %c",&input);
			printf("%c\n",input);
		}else if(input !='\0'){
			printf("��J���~�A�гv�@��J�n�ƤJ���H(O��X)(��JS�����J)�G\n");
			scanf(" %c",&input);
			printf("%c\n",input);
		}
		
	}
	new_node->link =front->link ;
	//�H�U��copy
	front_c ->link =NULL;
	rear_c ->link =NULL;
	this_node_c = front->link ;
	int i;
	for( i=0;i<count;i++){
		new_node_c =(struct node *) malloc(sizeof(struct node));
		new_node_c->id=this_node_c->id ;
		new_node_c->link = NULL;
		if(front_c->link == NULL){
			front_c->link =new_node_c;
			rear_c->link =new_node_c;
		}else{
			temp_node_c=rear_c->link ;
			temp_node_c->link =new_node_c;
			rear_c->link =new_node_c;
		}
		this_node_c = this_node_c->link ;
	}
	new_node_c->link =front_c->link;
	//�H�W��copy
	//�L�X�ثe�쵲 
	this_node_c =front_c->link ;
	for(i=0;i<count;i++){
		printf("%c\n",this_node_c->id );
		this_node_c=this_node_c->link ;
	}
	//�L�X�ثe�쵲 
	//�H�U���⯫�_�Ʀr 
	int num =1 ;             //���_�Ʀr 
	this_node_c = front_c->link ;
	int countO_c = countO;   //�n�U�����H�� 
	int count_c = count;     //�`�I�Ӽ� 
		printf("%d�ثe�ٶ���%d�Ӥ���U��\n",num,countO);
	while(countO_c >0){
		for( i =1;i<num;i++){;
			this_node_c = this_node_c->link ;
		}
		if(this_node_c->link ->id =='O'){  //�p�G�OO�N�������`�I�A�N�n�U�����H�ƴ�@ 
			printf("���O\n");
			countO_c--;
			printf("%d�ثe�ٶ���%d�Ӥ���U��\n\n",num,countO_c);
			//�p�G�n�������`�I�O�Y�Χ����ܡA�n��s�A�H�K�X�{front/rear->link=NULL������ 
			if(this_node_c->link ==front_c->link ){     
				front_c->link =this_node_c->link ->link;
			}
			if(this_node_c->link ==rear_c->link ){
				rear_c->link = this_node_c;
			}
			//�������쵲 
			this_node_c->link =this_node_c->link ->link;
			//�������쵲 
			count_c--;
			//�L�X�ثe�쵲 
			printf("���ۥΤU���쵲��O\n");
			this_node =front_c->link ;
			for(i=0;i<count_c;i++){
				printf("%c\n",this_node->id );
				this_node=this_node->link ;
			}
			//�L�X�ثe�쵲 
	
		//
		}else{
			//���_�Ʀr���W�[�@�A��l�ƭȪ�l�� 
			num++;
			countO_c=countO;
			count_c=count;
			printf("�i���n����\n\n");
			printf("%d�ثe�ٶ���%d�Ӥ���U��\n",num,countO_c);
			//�H�U��copy
			front_c ->link =NULL;
			rear_c ->link =NULL;
			this_node_c = front->link ;
			
			for( i=0;i<count;i++){
				new_node_c =(struct node *) malloc(sizeof(struct node));
				new_node_c->id=this_node_c->id ;
				new_node_c->link = NULL;
				if(front_c->link == NULL){
					front_c->link =new_node_c;
					rear_c->link =new_node_c;
				}else{
					temp_node_c=rear_c->link ;
					temp_node_c->link =new_node_c;
					rear_c->link =new_node_c;
				}
				this_node_c = this_node_c->link ;
			}
			new_node_c->link =front_c->link;
			//�H�W��copy
			//�L�X�ثe�쵲 
			printf("���ۥΤU���쵲��O\n");
			this_node =front_c->link ;
			for(i=0;i<count_c;i++){
				printf("%c\n",this_node->id );
				this_node=this_node->link ;
			}
			//�L�X�ثe�쵲 
			this_node_c = front_c->link ; //��this_node_c���^�̫e��(front_c) 
		}

	}
	//�H�W���⯫�_�Ʀr 
	printf("\n���_�Ʀr���G%d\n",num);
	
	system("pause");

}
