#include<stdio.h>
#include<stdlib.h>
int *a=NULL;
int cap;
void create(){
    printf("Enter the capacity:-");
    scanf("%d",&cap);
    a=(int *)malloc(sizeof(int));
}
int front=-1;
int rear=-1;
void push_front(int data){
    if(front==-1){
        front=0;
        rear=0;
        a[front]=data;
        rear++;
    }
    else if(rear==cap){
        printf("Overflow");
        return;
    }
    else{
        for(int i=rear;i>=0;i--){
            a[i+1]=a[i];
        }
        a[front]=data;
        rear++;
    }
    return;
}
void push_rear(int data){
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(rear==cap){
        printf("Overflow");
        return;
    }
    else{
        a[rear]=data;
        rear++;
    }
    return;
}
void display(){
    for(int i=front;i<rear;i++)
        printf("%d ",a[i]);
}
int main(){
    create();
    push_front(10);
    push_front(20);
    push_front(30);
    push_rear(40);
    push_rear(50);
    display();
    return 0;
}
