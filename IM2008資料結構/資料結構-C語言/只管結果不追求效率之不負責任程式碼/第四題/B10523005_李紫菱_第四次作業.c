#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct node{    //�ŧistruct���c�A�]�tid�Blink 
		char id;
		struct node *link;
struct node *link_back;
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
	front->link_back =NULL;
	rear->link = NULL;
	rear->link_back =NULL;
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
			new_node->link_back =NULL;
			if(front->link == NULL){
				front->link =new_node;
				rear->link =new_node;
			}else{
				rear->link->link =new_node;
				new_node->link_back =rear->link ;
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
	front->link->link_back =new_node;
	//�H�U��copy
	front_c ->link =NULL;
	rear_c ->link =NULL;
	this_node_c = front->link ;
	int i;
	for( i=0;i<count;i++){
		new_node_c =(struct node *) malloc(sizeof(struct node));
		new_node_c->id=this_node_c->id ;
		new_node_c->link = NULL;
		new_node_c->link_back =NULL;
		if(front_c->link == NULL){
			front_c->link =new_node_c;
			rear_c->link =new_node_c;
		}else{
			rear_c->link->link =new_node_c;
			new_node_c->link_back =rear_c->link ;
			rear_c->link =new_node_c;
		}
		this_node_c = this_node_c->link ;
	}
	new_node_c->link =front_c->link;
	front_c->link->link_back =new_node_c;
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
	bool dir =true;  //�ŧidir(�@���P�_���f���̾� 
	while(countO_c >0){
		//�H�U�M�w�O���ɰw�٬O�f�ɰw  
		if(dir){
			printf("next��\n");
			for( i =0;i<num;i++){;
				this_node_c = this_node_c->link ;
			}	
		}else{
			printf("next�f\n");
			for( i =0;i<num;i++){
				this_node_c = this_node_c->link_back  ;
			}
		}
		//�H�W�M�w�O���ɰw�٬O�f�ɰw 
		if(this_node_c ->id =='O'){  //�p�G�OO�N�������`�I�A�N�n�U�����H�ƴ�@ 
			printf("���O\n");
			countO_c--;
			printf("%d�ثe�ٶ���%d�Ӥ���U��\n\n",num,countO_c);
			//�p�G�n�������`�I�O�Y�Χ����ܡA�n��s�A�H�K�X�{front/rear->link=NULL������ 
			if(this_node_c ==front_c->link ){    
				front_c->link =this_node_c ->link;
			}
			if(this_node_c ==rear_c->link ){
				rear_c->link = this_node_c->link_back ;
			}
			//�������쵲 
			this_node_c->link_back->link = this_node_c->link ;
			this_node_c->link->link_back =this_node_c->link_back ;
			if(dir){
				this_node_c = this_node_c->link ; 
				dir = false;
			}else{
				this_node_c = this_node_c->link_back ;
				dir = true;
			}
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
		}else{
			//���_�Ʀr���W�[�@�A��l�ƭȪ�l�� 
			num++;
			countO_c=countO;
			count_c=count;
			printf("�i���n����\n\n");
			printf("%d�ثe�ٶ���%d�Ӥ���U��\n",num,countO_c);
			dir =true;
			//�H�U��copy
			front_c ->link =NULL;
			rear_c ->link =NULL;
			this_node_c = front->link ;
			int i;
			for( i=0;i<count;i++){
				new_node_c =(struct node *) malloc(sizeof(struct node));
				new_node_c->id=this_node_c->id ;
				new_node_c->link = NULL;
				new_node_c->link_back =NULL;
				if(front_c->link == NULL){
					front_c->link =new_node_c;
					rear_c->link =new_node_c;
				}else{
					rear_c->link->link =new_node_c;
					new_node_c->link_back =rear_c->link ;
					rear_c->link =new_node_c;
				}
				this_node_c = this_node_c->link ;
			}
			new_node_c->link =front_c->link;
			front_c->link->link_back =new_node_c;
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
