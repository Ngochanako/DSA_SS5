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
//chuyen danh sach vong
void convertToCircular(Node** head){
	Node* tmp=*head;
	Node* current=*head;
	while(current->next!=NULL){
		current=current->next;
	}
	tmp->prev=current;
	current->next=tmp;
}
int main(){
	int n,x;
	scanf("%d",&n);
	Node* a=NULL;
	printf("Nhap phan tu cua danh sach lien ket \n");
	for(int i=0;i<n;i++ ){
		scanf("%d",&x);
		insertToTail(&a,x);
	}
	convertToCircular(&a);
	printList(&a);
}
