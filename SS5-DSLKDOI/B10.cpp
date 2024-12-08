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
//chuyen 2 danh sach chan va le
void divideLink(Node** head,Node** odd,Node** even){
	Node* tmp=*head;
	while(tmp!=NULL){
		if(tmp->data%2==0){
			insertToTail(even,tmp->data);
		}else{
			insertToTail(odd,tmp->data);
		}
		tmp=tmp->next;
	}
}
int main(){
	int n,x;
	scanf("%d",&n);
	Node* a=NULL;
	Node* odd=NULL;
	Node* even=NULL;
	printf("Nhap phan tu cua danh sach lien ket \n");
	for(int i=0;i<n;i++ ){
		scanf("%d",&x);
		insertToTail(&a,x);
	}
	divideLink(&a,&odd,&even);
	printList(&odd);
	printf("\n");
	printList(&even);
}
