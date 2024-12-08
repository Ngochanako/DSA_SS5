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
//dem so node cua danh sach
int countNode(Node** head){
	if(*head==NULL){
		return 0;
	}
	int cnt=0;
	Node* tmp=*head;
	while(tmp!=NULL){
		cnt++;
		tmp=tmp->next;
	}
    return cnt;
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
	printf("So node cua danh sach:%d\n",countNode(&head));
}
