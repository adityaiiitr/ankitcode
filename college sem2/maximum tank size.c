#include<stdio.h>
int minimum(int x,int y){
    if(x<y)
        return x;
    else
        return y;
}
int main(){
    int a[10];
    for(int i=0;i<10;i++)
        scanf("%d ",&a[i]);
    int max_area;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            int breadth=-1,height=0,area=0;
            for(int k=i;k<=j;k++){
                breadth++;
            }
            height=minimum(a[i],a[j]);
            area=height*breadth;
            if(area>max_area){
                max_area=area;
            }
        }
    }
    printf("The maximum amount of water that can be stored is %d",max_area);
    return 0;
}
