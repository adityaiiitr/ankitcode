#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
struct node{
    int data;
    struct node *next;
};
void insertend(struct node** head, int newdata){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;
    newnode->data=newdata;
    newnode->next=NULL;
    if(*head==NULL){
        *head= newnode;
        return;
    }
    while (temp->next != NULL) temp=temp->next;
    temp->next = newnode;
    return;
}
void insertatbeg(struct node** head,int newdata){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        return;
    }

    newnode->next=(*head);
    *head=newnode;
    return;
}
void insertatindex(struct node** head,int index,int newdata){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    struct node* temp;
    temp=*head;
    for(int i=1;i<index;i++){
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}
void deleteatbeg(struct node **head){
    struct node *temp;
    temp=*head;
    *head=(*head)->next;
    free(temp);
}
void deleteatend(struct node **head){
    struct node *temp;
    struct node *prev;
    temp=(*head)->next;
    prev=*head;
    while(temp->next!=NULL){
        temp=temp->next;
        prev=prev->next;
    }
    prev->next=NULL;
    free(temp);
}
void deleteatindex(struct node** head,int index){
    struct node *temp;
    struct node *prev;
    temp=(*head)->next;
    prev=*head;
    int i=1;
    while(i!=index){
        temp=temp->next;
        prev=prev->next;
        i++;
    }
    prev->next=temp->next;
    free(temp);
}
void print(struct node* t){
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
}
int main(){
    struct node* head=NULL;
    while(1){
        int choice=0,n=0;
        printf("Enter the choice:-");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter the data:-");
            scanf("%d",&n);
            insertend(&head,n);
        case 2:
            struct node* t;
            t=head;
            print(t);
            break;
        case 3:
            exit(0);
            }
        }
    }

    return 0;
}
