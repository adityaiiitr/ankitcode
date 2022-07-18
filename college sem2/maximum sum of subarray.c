#include<stdio.h>
int max_subarray(int a[],int n){
    int max;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+a[k];
                if(sum>max){
                    max=sum;
                }
            }
        }
    }
    return max;
}
int main(){
    int a[]={1,-6,2,4,5,-8,10};
    printf("%d",max_subarray(a,7));
    return 0;
}
