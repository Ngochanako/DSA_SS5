#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;
//them node moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
//them node moi vao dau mang
void insertToHead(Node** head,int n){
	Node* newNode=createNode(n);
	if(*head!=NULL){
		(*head)->prev=newNode;
	}
	newNode->next=*head;
	*head=newNode;
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
//duyet node theo chieu nguoc
void printListReverse(Node** head){
	Node* tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	while(tmp!=NULL){
		printf("%d<->",tmp->data);
		tmp=tmp->prev;
	}
	printf("NULL");
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
	printListReverse(&head);
}
