#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void enque(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    return;
}
int deque(){
    if(front==NULL)
        return -1;
    int t;
    t=front->data;
    struct node* temp=front;
    front=front->next;
    free(temp);
    return t;
}
int isEmpty(){
    if(front==NULL)
        return 1;
    else
        return 0;
}
int getFront(){
    if(front==NULL)
        return -1;
    else
        return front->data;
}
int getRear(){
    if(front==NULL)
        return -1;
    else
        return rear->data;
}
void display(){
    struct node* temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int choice,data;
    printf("1:-Enqueue\n2:-Dequeue\n3:-Print Front Element\n4:-Print Rear Element\n5:-Display\n6:-isEmpty\n7:Exit\n");
    while(1){
        printf("Enter the choice:-");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter the data:-");
            scanf("%d",&data);
            enque(data);
            break;
        case 2:
            printf("The deleted element is:-%d\n",deque());
            break;
        case 3:
            printf("The top element is:-%d\n",getFront());
            break;
        case 4:
            printf("The rear element is:-%d\n",getRear());
            break;
        case 5:
            display();
            break;
        case 6:
            if(isEmpty()==1)
                printf("The queue is empty\n");
            else
                printf("The queue is not empty\n");
            break;
        case 7:
            exit(0);
            break;
        }
    }
    return 0;
}
