#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct node* prev;
    int data;
    struct node* next;
}node;
void insertatbeg(node** head,int newdata){
    node* newnode;
    newnode=(node* )malloc(sizeof(node));
    newnode->data=newdata;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    node* temp;
    temp=*head;
    while(temp->next=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}
void print(node* t){
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
}
int main(){
    node* head;
    insertatbeg(&head,10);
    print(head);
    return 0;
}
