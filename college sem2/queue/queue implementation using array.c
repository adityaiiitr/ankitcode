#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
int front=-1;
int rear=-1;
int *arr;
int capacity;
void create_queue(int cap){
    capacity=cap;
    arr=(int *)malloc(capacity*sizeof(int));
}
void enque(int x){
    if(rear==capacity-1){
        printf("Queue is Full\n");
        return;
    }
    if(front==-1){
        front++;
        rear++;
        arr[rear]=x;
    }
    else{
        rear++;
        arr[rear]=x;
    }
}
int deque(){
    if(front==-1||front==rear){
        printf("Queue is Empty");
        return -1;
    }
    int t=arr[front];
    front++;
    return t;
}
int getFront(){
   return arr[front];
}
int getRear(){
    return arr[rear];
}
void display(){
    for(int i=front;i<=rear;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int isEmpty(){
    if(front==-1)
        return 1;
    else
        return 0;
}
int main(){
    int choice,data,cap;
    printf("1:-Create Queue\n2:-Enqueue\n3:-Dequeue\n4:-Print Front Element\n5:-Print Rear Element\n6:-Display\n7:-isEmpty\n8:Exit\n");
    while(1){
        printf("Enter the choice:-");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter the capacity of Queue:-");
            scanf("%d",&cap);
            create_queue(cap);
            break;
        case 2:
            printf("Enter the data:-");
            scanf("%d",&cap);
            enque(cap);
            break;
        case 3:
            printf("The deleted element is:-%d\n",deque());
            break;
        case 4:
            printf("The top element is:-%d\n",getFront());
            break;
        case 5:
            printf("The rear element is:-%d\n",getRear());
            break;
        case 6:
            display();
            break;
        case 7:
            if(isEmpty()==1)
                printf("The queue is empty\n");
            else
                printf("The queue is not empty\n");
            break;
        case 8:
            exit(0);
            break;
        }
    }
    return 0;
}
