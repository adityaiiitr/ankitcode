#include<stdio.h>
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void reverse(int a[],int low,int high){
    while(low<high){
        swap(&a[low],&a[high]);
        low++;
        high--;
    }
}
void lrd(int a[],int n,int d){
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
    printf("Output:-");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main(){
    int a[5];
    printf("Enter the array:-");
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    int pos=0;
    printf("Enter the position about array to be rotated:-");
    scanf("%d",&pos);
    lrd(a,5,pos);
    return 0;
}
