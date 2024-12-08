#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;
//tao node moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
//them node vao cuoi mang
void insertToTail(Node** head,int n){
	Node* newNode=createNode(n);
	if(*head==NULL){
		*head=newNode;
		return;
	}
	Node* tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	newNode->prev=tmp;
	tmp->next=newNode;
}
//duyet node theo chieu xuoi
void printList(Node** head){
	Node* tmp=*head;
	while(tmp!=NULL){
		printf("%d<->",tmp->data);
		tmp=tmp->next;
	}
	printf("NULL");
}
//tìm phan tu trong danh sach
void find(Node** head,int x,int n){
    Node* tmp=*head;
    while(tmp!=NULL){
    	if(tmp->data==x){
    		 tmp->data=n;
    		 printList(head);
    		 return;
		}
		tmp=tmp->next;
	}
	printf("Khong tim thay %d",x);
}
int main(){
	int n,x;
	scanf("%d",&n);
	Node* head=NULL;
	printf("Nhap phan tu cua danh sach lien ket\n");
	for(int i=0;i<n;i++ ){
		scanf("%d",&x);
		insertToTail(&head,x);
	}
	printList(&head);
    printf("Nhap gia tri can tim va thay the:\n");
    scanf("%d %d",&n,&x);
    find(&head,n,x);
}
