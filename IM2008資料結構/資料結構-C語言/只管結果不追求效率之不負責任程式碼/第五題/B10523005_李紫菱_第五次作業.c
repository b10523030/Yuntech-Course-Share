#include<stdio.h>
#include<stdlib.h> 
struct Node{
//�ŧi���c�A�]�t���l��B�k�l��B�ȡB���ץ��Ŧ]�l 
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a, int b);
int height(struct Node *N){
	//�p��}������ 
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b){
	//��̤j�Ȧ^�� 
    return (a > b)? a : b;
}
struct Node* newNode(int key){
	//�s�W�ӥ��s���`�I�B���ץ��Ŧ]�l��1 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}
struct Node *rightRotate(struct Node *y){
	//�k���� 
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    
    //�H�U���p�⥭�Ŧ]�l
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
	//�H�W���p�⥭�Ŧ]�l 
    return x;
}
struct Node *leftRotate(struct Node *x){
	//������ 
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
 
    //�H�U���p�⥭�Ŧ]�l
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
	//�H�W���p�⥭�Ŧ]�l 
    return y;
}
int getBalance(struct Node *N){
    if (N == NULL){ //�p�G=NULL�N�N��S���l��A�ҥH���Ŧ]�l�N=0 
        return 0;
    } 
    return height(N->left) - height(N->right);//���Ŧ]�l=���}���״�k�}���� 
} 
struct Node* insert(struct Node* node, int key){
    //�H�U���s�W�`�I 
    if (node == NULL){ 
    //�p�G���𬰪ž�A�N�����s�W�`�I 
        return(newNode(key));
	} 
    if (key < node->key){ 
    //�p�G�n�s�W���Ȥ�ثe�����٤p
		//�N������ 
        node->left  = insert(node->left, key);
    }else if (key > node->key){ 
    //�p�G�n�s�W���Ȥ�ثe�a���٤j
		//�N���k�� 
        node->right = insert(node->right, key);
    }else{
    	//������A�X�}�A�N���J 
        return node;
	} 
	//�H�W���s�W�`�I 
	//�H�U������AVL tree 
    node->height = 1 + max(height(node->left),height(node->right));//�p�⥪�k�}���� 
    int balance = getBalance(node);//�i�JgetBalance�p�⥭�Ŧ]�l 
    if (balance > 1 && key < node->left->key){ 
    //�p�G���䪺���}������A�N�������k���� 
        return rightRotate(node);
	} 
    if (balance < -1 && key > node->right->key){ 
    //�p�G�k�䪺�k�}������A�N������������ 
        return leftRotate(node);
	} 
    // Left Right Case
    if (balance > 1 && key > node->left->key){
    //�p�G�O���䪺�k�}������A�N���L�����ন���䪺���}����`�� 
        node->left =  leftRotate(node->left);
        //�M��A����k���� 
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key){
    //�p�G�O�k�䪺���}������A�N�L�����ন�k�䪺�k�}�����  
        node->right = rightRotate(node->right);
        //�M��A���楪���� 
        return leftRotate(node);
    }
    //�H�W������AVL tree 
    return node;
}
struct Node * minValueNode(struct Node* node){
	//�^�ǳ̤p��(�̥��䪺�� 
    struct Node* current = node;
    while (current->left != NULL){
	//�@��������A����̥��䬰�� 
        current = current->left;
	} 
    return current;
}
struct Node* deleteNode(struct Node* root, int key){
	//�H�U���R���`�I 
    if (root == NULL){
		printf("�d�L����\n"); 
        return root;
	} 
    if ( key < root->key ){ 
		//�p�G�n�R�����Ʀr��ثe���Ʀr�p�A�N�~�򩹥��� 
        root->left = deleteNode(root->left, key); 
    }else if( key > root->key ){ 
		//�p�G�n�R�����Ʀr��ثe���Ʀr�j�A�N�~�򩹥k��
        root->right = deleteNode(root->right, key);
    }else if(key == root->key ){
    	//���n�R�����Ȯ� 
        if( (root->left == NULL) || (root->right == NULL) ){
        	//�p�G�u�����l��Υk�l��䤤�@�Ӯɪ����p 
				//�Y���l�𤣬��� �Otemp=���l��
				//�Y���l�𬰪� �Otemp=�k�l�� 
            struct Node *temp = root->left ? root->left :
                                             root->right;
            if (temp == NULL){
            //�p�Gtemp=NULL�N���k�l�𳣬O�Ū��A�N�����R�� 
                temp = root;
                root = NULL;
            }else{
            //temp�����ŴN�Τl����N�ۤv 
             *root = *temp; // Copy the contents of
                            // the non-empty child
            } 
            free(temp);
        }else{
        	//�p�G���k�l�𳣦����� 
            //��k��̤p���Ȩ��N�ۤv(��l����) 
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        printf("�R��%d",key);
    }
    if (root == NULL){ //�ثeAVL tree���ž� 
    	return root;
	} 
	//�H�W���R���`�I 
    //�H�U������AVL tree
    root->height = 1 + max(height(root->left),height(root->right));//�p�⥪�k�}���� 
    int balance = getBalance(root);//�i�JgetBalance�p�⥭�Ŧ]�l 
    if (balance > 1 && getBalance(root->left) >= 0){ 
    //�p�G�O���䪺���}������A�N�������k���� 
        return rightRotate(root); 
	} 
    if (balance < -1 && getBalance(root->right) <= 0){
    //�p�G�O�k�䪺�k�}������A�N���������� 
        return leftRotate(root);
	}
    if (balance > 1 && getBalance(root->left) < 0){
    //�p�G�O���䪺�k�}������A�N���L�����ন���䪺���}����`�� 
        root->left =  leftRotate(root->left);
        //�M��A����k���� 
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0){
    //�p�G�O�k�䪺���}������A�N�L�����ন�k�䪺�k�}����� 
        root->right = rightRotate(root->right);
        //�M��A���楪���� 
        return leftRotate(root);
    }
    //�H�W������AVL tree
    return root;
}
void preOrder(struct Node *root){
	//���j�L�X�ثe��AVL tree 
    if(root != NULL){ 
        printf("%d ", root->key);
        preOrder(root->left);//���L����L���A�L�k�� 
        preOrder(root->right);
    }
}
int main(){
	struct Node *root = NULL;
	printf("�п�J���O�A���J��i�A�R����d(ex�Gi 5,d 7)�A��JQ����G\n");
	char input='\0';
	int num ;
	scanf(" %c",&input);
	while(input!='Q'){//�u�n���OQ�N�~����� 
		if((input =='i')||(input=='d')){ 
			scanf("%d",&num);
			if(input =='i'){ //�p�G�Oi�Ninsert 
				root = insert(root,num);
				printf("���J%d",num);
			}else{//�p�G�Od�Ndelete 
				root = deleteNode(root, num);
			}
			printf("�ثeAVL tree�G");
			preOrder(root);
			printf("\n");
			printf("�п�J���O�A���J��i�A�R����d(ex�Gi 5,d 7)�A��JQ����G\n");
			scanf(" %c",&input);
		}else if(input !='\0'){//���Oi d Q�N�N���J���~ 
			printf("��J���~�A�нп�J���O�A���J��i�A�R����d�A(ex�Gi 5,d 7)�A��JQ����G\n");
			scanf(" %c",&input);
		}
	}
    return 0;
}
