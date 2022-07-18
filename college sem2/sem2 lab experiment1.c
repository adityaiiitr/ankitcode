#include<stdio.h>
int main(){
    int max1,max2,index;
    int a[5];
    //taking input
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    max1=-999;
    max2=-999;
    for(int i=0;i<5;i++){
        if(a[i]>max1)
            max1=a[i];
    }
    for(int i=0;i<5;i++){
        if(a[i]>max2&&a[i]!=max1){
            max2=a[i];
            index=i;
        }
    }
    int temp[5];
    int length=0;
    for(int i=0;i<5;i++){
        if(a[i]!=max2)
            temp[length++]=a[i];
    }
    for(int i=0;i<length;i++){
        a[i]=temp[i];
    }
    for(int i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
