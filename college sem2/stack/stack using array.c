#include<stdio.h>
#include<stdlib.h>
int *arr=NULL;
int top=-1;
int size=0;
void create(int cap){
    size=cap;
    arr=(int *)calloc(size,sizeof(int));
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull(){
    if(top==size)
        return 1;
    else
        return 0;
}
void push(int x){
    if(isFull())
        return;
    top++;
    arr[top]=x;
}
int pop(){
    if(isEmpty())
        return -1;
    int t=arr[top];
    top--;
    return t;
}
void display(){
    while(isEmpty()==0)
        printf("%d ",pop());
}
int main(){
    create(5);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    display();
    return 0;
}
