#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* insertatbeg(struct node* head,int newdata){
    struct node* newnode;
    newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        return head;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    return head;
}
struct node* insertatend(struct node* head,int newdata){
    struct node* newnode;
    newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return head;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        return head;
    }
}
struct node* insertatpos(struct node* head,int pos,int newdata){
    struct node* newnode;
    newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->prev=NULL;
    newnode->next=NULL;
    struct node* temp=head;
    if(head==NULL){
        head=newnode;
        return head;
    }
    else{
        if(pos==1){
            newnode->next=head;
            head=newnode;
            return head;
        }
        else{
            int i=1;
            while(i!=pos-1){
                temp=temp->next;
                i++;
            }
            if(temp==NULL)
                printf("Position Out of Bound");
            else{
                newnode->next=temp->next;
                temp->next->prev=newnode;
                temp->next=newnode;
                newnode->prev=temp;
                return head;
            }
        }
    }
}
void print(struct node* t){
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
int main(){
    struct node* head=NULL;
    printf("1:-Insertion at beginning\n2:-Insertion at end\n3:-Insertion at position\n4:-Display the list\n5:-exit\n");
    while(1){
        int choice=0,n=0,pos=0;
        printf("Enter the choice:-");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter the data:-");
            scanf("%d",&n);
            head=insertatbeg(head,n);
            break;
        case 2:
            printf("Enter the data:-");
            scanf("%d",&n);
            head=insertatend(head,n);
            break;
        case 3:
            printf("Enter the data:-");
            scanf("%d",&n);
            printf("Enter the position:-");
            scanf("%d",&pos);
            head=insertatend(head,n);
            break;
        case 4:
            print(head);
            break;
        case 5:
            exit(0);
            }
        }
    return 0;
}
