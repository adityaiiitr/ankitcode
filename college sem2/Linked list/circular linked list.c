#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
struct node{
    int data;
    struct node* next;
};
struct node* insertatend(struct node* head,int newdata){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=newdata;
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
    }
    return head;
}
struct node* insertatbeg(struct node* head,int newdata){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
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
        int i=0;
        struct node* temp=head;
        while(i!=position-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
struct node* deleteatpos(struct node* head,int position){
    if(head==NULL)
        printf("Linked List is Already Empty");
    else{
        struct node* temp=head->next;
        struct node* prev=head;
        int i=0;
        while(i!=position-1){
            temp=temp->next;
            prev=prev->next;
            i++;
        }
        prev->next=temp->next;
        free(temp);
    }
    return head;
}
struct node* replace(struct node* head,int newdata,int position){
    struct node* temp=head;
    for(int i=1;i!=position;i++)
        temp=temp->next;
    temp->data=newdata;
    return head;
}
void display(struct node* head){
    struct node* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
int main(){
    struct node* head=NULL;
    printf("1:-Insertion:-\n\t1:Insertion at Beginning\n\t2:Insertion at End\n\t3:Insertion at Position\n2:-Deletion\n3:-Replace\n4:-Display\n5:Exit\n");
    while(1){
        int choice=0,choice2=0,pos=0,newdata=0,pos2=0;
        printf("Enter the choice:-");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter choice of Insertion:-");
            scanf("%d",&choice2);
            switch(choice2){
            case 1:
                    printf("Enter the data:-");
                    scanf("%d",&newdata);
                    head=insertatbeg(head,newdata);
                    break;
            case 2:
                    printf("Enter the data:-");
                    scanf("%d",&newdata);
                    head=insertatend(head,newdata);
                    break;
            case 3:
                    printf("Enter the data:-");
                    scanf("%d",&newdata);
                    printf("Enter the position:-");
                    scanf("%d",&pos);
                    head=insertatpos(head,pos,newdata);
                    break;
            }
            break;
        case 2:
            printf("Enter the position:-");
            scanf("%d",&pos2);
            head=deleteatpos(head,pos2);
            break;
        case 3:
            printf("Enter the position:-");
            scanf("%d",&pos);
            printf("Enter the new data:-");
            scanf("%d",&newdata);
            head=replace(head,newdata,pos);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
