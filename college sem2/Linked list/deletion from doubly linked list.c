#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* deletefrombeg(struct node* head){
    if(head==NULL){
        printf("The list is empty");
        return head;
    }
    else{
        struct node* del=head;
        head=head->next;
        free(del);
        return head;
    }
}
struct node* deletefromend(struct node* head){
    struct node* temp;
    temp=head;
    if(head==NULL){
        printf("The list is already empty");
        return head;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;
}
struct node* deletefrompos(struct node* head,int position){
    int i=1;
    struct node* temp;
    temp=head;
    while(i!=position-1){
        temp=temp->next;
        i++;
    }
    if(temp->next->next==NULL)
        head=deletefromend(head);
    else{
        struct node* s=temp->next->next;
        struct node* del=temp->next;
        temp->next=s;
        s->prev=temp;
        free(del);
    }
    return head;
}

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
void display(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    struct node* head=NULL;
    head=insertatbeg(head,10);
    head=insertatbeg(head,20);
    head=insertatbeg(head,40);
    head=insertatbeg(head,50);
    head=insertatbeg(head,60);
    printf("The given Linked List is:-");
    display(head);
    printf("1:-Deletion:\n\t1:From Beginning\n\t2:From End\n\t3:From a position\n2:-print\n3:-exit\n");
    while(1){
        int choice=0,choice2=0,pos=0;
        printf("Enter the choice:-");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter choice of deletion:-");
            scanf("%d",&choice2);
            switch(choice2){
            case 1:
                    head=deletefrombeg(head);
                    break;
            case 2:
                    head=deletefromend(head);
                    break;
            case 3:
                    printf("Enter the position:-");
                    scanf("%d",&pos);
                    head=deletefrompos(head,pos);
                    break;
            }
            break;
        case 2:
            display(head);
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}
