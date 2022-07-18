#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void push(int d){
    //inserting the node at the beginning
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
int pop(){
    //deleting the head node;
    if(isEmpty())
        return -1;
    struct node* del=head;
    int data=head->data;
    head=head->next;
    free(del);
    return data;
}
int isEmpty(){
    if(head==NULL)
        return 1;
    else
        return 0;
}
int peek(){
    if(isEmpty())
        return -1;
    return head->data;
}

int main(){
    int n,choice,data;
    printf("Stack Operations:\n1.Push\n2.Pop\n3.isEmpty\n4.Peek\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            printf("Enter The Data to be Added: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("The deleted element is:-%d",pop());
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            printf("%d",peek());
            break;
        default:
            printf("Invalid Choice!");
        }
        printf("\nStack Operations:\n1.Push\n2.Pop\n3.isEmpty\n4.Peek\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }
    return 0;
}
