#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
int longest_sorted_subarray(int a[],int n){
    int maxlength=0;
    int length=1;
    int s_index=0;
    int f_index=0;
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]){
            length++;
            f_index=i;
        }
        else
            s_index=i;
            length=1;
        maxlength=max(maxlength,length);
    }
    printf("%d %d ",s_index,f_index);
    return maxlength;
}
int main(){
    int a[]={1,2,3,-1,-1,4,4,5,6,7};
    printf("%d ",longest_sorted_subarray(a,10));
    return 0;
}
