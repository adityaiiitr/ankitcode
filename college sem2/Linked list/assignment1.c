#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
struct node{
    int data;
    struct node *next;
};
struct node* insertatend(struct node* head, int newdata){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    struct node* temp=head;
    if(head==NULL){
        head=newnode;
        return head;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        return head;
    }
}
struct node* insertatbeg(struct node* head,int newdata){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    struct node* temp=head;
    if(head==NULL){
        head=newnode;
        return head;
    }
    else{
        newnode->next=temp;
        head=newnode;
        return head;
    }
}
struct node* insertatindex(struct node* head,int pos,int newdata){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    struct node* temp;
    temp=head;
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
                if(temp==NULL)
                    break;
                i++;
            }
            if(temp==NULL){
                printf("Position Out of Bound\n");
                return head;
            }
            else{
                newnode->next=temp->next;
                temp->next=newnode;
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
    printf("1:-Insertion:\n\t1:At Beginning\n\t2:At a Specific Position\n\t3:At End\n2:-Display\n3:-exit\n");
    while(1){
        int choice=0,n=0,pos=0,choice2=0;
        printf("Enter the choice:-");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter choice of insertion:-");
            scanf("%d",&choice2);
            switch(choice2){
            case 1:
                    printf("Enter the data:-");
                    scanf("%d",&n);
                    head=insertatbeg(head,n);
                    break;
            case 2:
                    printf("Enter the data:-");
                    scanf("%d",&n);
                    printf("Enter the position:-");
                    scanf("%d",&pos);
                    head=insertatindex(head,pos,n);
                    break;
            case 3:
                    printf("Enter the data:-");
                    scanf("%d",&n);
                    head=insertatend(head,n);
                    break;
            }
            break;
        case 2:
            print(head);
            break;
        case 3:
            exit(0);
            }
        }

    return 0;
}
