#include<stdio.h>

int main(){
    int a[5];
    int largest_sum=0;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<5;i++){
        if(a[i]<0){
            continue;
        }
        else{
            largest_sum=largest_sum+a[i];
        }
    }
    printf("%d",largest_sum);
    return 0;
}
