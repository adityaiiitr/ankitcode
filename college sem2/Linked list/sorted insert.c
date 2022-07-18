#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* sort_insert(struct node* head,int x);
void display(struct node* head);
int main(){
    struct node* head=NULL;
    head=sort_insert(head,50);
    head=sort_insert(head,30);
    head=sort_insert(head,10);
    head=sort_insert(head,255);
    head=sort_insert(head,55);
    head=sort_insert(head,65);

    display(head);

    return 0;
}
struct node* sort_insert(struct node* head,int x){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else if(x<head->data){
        newnode->next=head;
        head=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL&&x>temp->next->data){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
void display(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
