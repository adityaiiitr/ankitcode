#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* insert(struct node* head,int x);
void display(struct node* head);
struct node* reverse(struct node* head);
int main()
{
    struct node* head=NULL;
    head=insert(head,10);
    head=insert(head,20);
    head=insert(head,30);
    head=insert(head,40);
    display(head);
    head=reverse(head);
    display(head);
    return 0;
}
struct node* reverse(struct node* head){
    struct node* prev=NULL;
    struct node* curr=head;
    while(curr!=NULL){
        struct node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
struct node* insert(struct node* head,int x)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else {
        struct node* t=head;
        while(t->next!=NULL)
            t=t->next;
        t->next=newnode;
    }
    return head;
}
void display(struct node* head)
{
    while(head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
}
