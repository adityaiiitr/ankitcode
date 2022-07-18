#include<stdio.h>
#include<stdlib.h>
int n=1;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int* heapify(int* heap,int value){
    int pos;
    pos=n;
    heap[n]=value;
    int parent=0;
    while(pos!=1){
        parent=pos/2;
        if(heap[pos]<=heap[parent])
            break;
        swap(&heap[pos],&heap[parent]);
        pos=parent;
    }
    return heap;
}
int* delete(int* heap){
    int last=heap[n];
    n=n-1;
    int ptr=1,left=2,right=3;
    heap[ptr]=last;
    while(left<=n){
        if(heap[ptr]>=heap[left]&&heap[ptr]>=heap[right])
            break;
        if(heap[right],heap[left]){
            swap(&heap[ptr],&heap[left]);
            ptr=left;
        }
        else{
            swap(&heap[ptr],&heap[right]);
            ptr=right;
        }
        left=2*ptr;
        right=left+1;
    }
    return heap;
}
void display(int* heap){
    for(int i=1;i<n;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}
int main(){
    int *heap=(int* )calloc(5,sizeof(int));
    heap[0]=-990;
    for(int i=1;i<5;i++){
        int value;
        printf("Enter the element:-");
        scanf("%d",&value);
        heap=heapify(heap,value);
        n++;
        display(heap);
    }
    //heap=heapify(heap,4,87);
    //display(heap,4);
    heap=delete(heap);
    display(heap);
    return 0;
}
