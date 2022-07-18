#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* front=NULL;
struct node* rear=NULL;
void push_front(int data){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        newnode->next=front;
        front->prev=newnode;
        front=newnode;
    }
    return;
}
void push_rear(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
    return;
}
int remove_front(){
    if(front==NULL)
        return -1;
    int x;
    x=front->data;
    struct node* temp=front;
    front->prev=NULL;
    front=front->next;
    free(temp);
    return x;
}
int remove_rear(){
    if(front==NULL)
        return -1;
    int x=rear->data;
    struct node* temp=rear;
    rear=rear->prev;
    rear->next=NULL;
    free(temp);
    return x;
}
void display(){
    struct node* temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}
int main(){
    push_front(10);
    push_front(20);
    push_front(30);
    push_rear(40);
    push_rear(50);
    push_rear(60);
    display();
    remove_front();
    display();
    remove_front();
    display();
    remove_front();
    return 0;
}
