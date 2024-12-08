#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
} Node;
//tao node moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
//them node vao dau danh sach
void insertToHead(Node** head,int n){
	Node* newNode=createNode(n);
	if(*head!=NULL){
		(*head)->prev=newNode;
	}
	newNode->next=*head;
	*head=newNode;
}
//them node vao cuoi danh sach
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
	tmp->next=newNode;
	newNode->prev=tmp;
}

int main(){
	
}
