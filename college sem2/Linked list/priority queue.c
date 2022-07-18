#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* next;
    int priority;
};
struct node* insert(struct node* head,int x,int p){
    struct node* temp=head;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->value=x;
    newnode->priority=p;
    if(head==NULL)
        head=newnode;
    else{
        if(p<head->priority){
            newnode->next=head;
            head=newnode;
        }
        else{
            while(temp->next!=NULL&&p>(temp->next->priority))
                temp=temp->next;
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return head;
}
void display(struct node* head){
    while(head!=NULL){
        printf("%d %d\n",head->value,head->priority);
        head=head->next;
    }
}
int main(){
    struct node* head=NULL;
    head=insert(head,10,3);
    head=insert(head,20,2);
    head=insert(head,50,8);
    head=insert(head,100,1);
    display(head);
    return 0;
}
