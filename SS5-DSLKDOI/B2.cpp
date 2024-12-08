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
//chen node moi vao giua danh sach
void insertToPosition(Node** head,int n,int p){
	Node* newNode=createNode(n);
	if(p==0){
		if(*head!=NULL){
			(*head)->prev=newNode;
		}
		newNode->next=*head;
		*head=newNode;
		return;
	}
	Node* tmp=*head;
	for(int i=0;i<p-1&&tmp!=NULL;i++){
		tmp=tmp->next;
	}
	if(tmp==NULL){
		printf("Error");
		return;
	}
	if(tmp->next==NULL){
		tmp->next=newNode;
		newNode->prev=tmp;
		return;
	}
	newNode->prev=tmp;
	newNode->next=tmp->next;
	tmp->next->prev=newNode;
	tmp->next=newNode;
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
	printf("Nhap gia tri va vi tri:\n");
	scanf("%d %d",&n,&x);
	insertToPosition(&head,n,x);
	printList(&head);
}
