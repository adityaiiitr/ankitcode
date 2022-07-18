#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void enque(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
int deque(){
    //delete the front pointer and shift the front to next location
    struct node* temp=front;
    front=front->next;
    int d=temp->data;
    free(temp);
    return d;
}
int getFront(){
    if(front==NULL)
        return -1;
    return front->data;
}
int getRear(){
    if(front==NULL)
        return -1;
    return rear->data;
}
int isEmpty(){
    //1 for true
    //and 0 for false
    if(front==NULL)
        return 1;
    else
        return 0;
}
int main(){
    enque(5);
    enque(6);
    enque(7);
    printf("%d ",deque());
    printf("%d ",deque());
    return 0;
}
