#include<stdio.h>
int main(){
    int a[]={1,2,3,4,5};
    int n=5;
    int d;
    scanf("%d",&d);
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=a[i];
    }
    for(int i=d;i<n;i++){
        a[i-d]=a[i];
    }
    for(int i=0;i<d;i++){
        a[n-d+i]=temp[i];
    }
    for(int k=0;k<n;k++)
        printf("%d ",a[k]);
    return 0;
}
