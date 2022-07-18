#include<stdio.h>
int main(){
    int a[10];
    for(int i=0;i<10;i++)
        scanf("%d",&a[i]);
    int max_length=0,sub_length=0;
    for(int i=1;i<10;i++){
        if(a[i]>a[i-1])
            sub_length++;
        else{
            if(max_length<sub_length){
                max_length=sub_length;
                sub_length=1;
            }
        }
    }
    //for the last iteration
    if(max_length<sub_length)
        max_length=sub_length;
    printf("%d ",max_length);
    return 0;
}
