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
//xoa node chan danh sach
void deleteNodeEven(Node** head){
	Node* tmp=*head;
	while(tmp!=NULL){
		if(tmp->data%2==0){
			Node* x=tmp;
			if(tmp->prev==NULL){
				tmp->next->prev=NULL;
				*head=tmp->next;
			}else if(tmp->next==NULL){
				tmp->prev->next=NULL;
			}else{
				tmp->next->prev=tmp->prev;
				tmp->prev->next=tmp->next;
			}
			tmp=tmp->next;
			free(x);
		}else{
			tmp=tmp->next;
		}
	}
}
//sap xep tang dan danh sach
void sortInc(Node** head){
    for(Node* i=*head;i->next!=NULL;i=i->next){
    	for(Node* j=i->next;j!=NULL;j=j->next){
    		if(i->data>j->data){
    			int v=i->data;
    			i->data=j->data;
    			j->data=v;
			}
		}
	}
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
    printf("Xoa node chan\n");
    deleteNodeEven(&head);
    printList(&head);
    printf("Sap xep tang dan\n");
    sortInc(&head);
    printList(&head);
}
