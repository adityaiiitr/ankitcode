#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
int top=0;
void push(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    top++;
    if(head==NULL)
        head=newnode;
    else{
        newnode->next=head;
        head=newnode;
    }
}
int pop(){
   if(head==NULL)
            return -1;
    int res=head->data;
    struct node* del=head;
    head=head->next;
    free(del);
    top--;
    return res;
}
void display(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    push(5);
    push(6);
    push(7);
    while(head!=NULL){
        printf("%d ",pop());
    }
    return 0;
}
