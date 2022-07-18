#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
struct node{
    int data;
    struct node* next;
};
struct node* insertatbeg(struct node* head,int newdata){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=newdata;
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
        return head;
    }
}
struct node* insertatend(struct node* head,int newdata){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=newdata;
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
struct node* insertatpos(struct node* head,int newdata,int position){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        struct node* temp=head;
        int i=1;
        while(i!=position-1){
            temp=temp->next;
            i++;
        }
        if(temp==NULL){
            printf("Position Out of Bound");
        }
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return head;
}
void display(struct node* head){
    struct node* temp;
    temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
int main(){
    struct node* head=NULL;
    head=insertatbeg(head,10);
    head=insertatbeg(head,20);
    head=insertatpos(head,200,200);
    head=insertatend(head,30);
    display(head);
    return 0;
}
