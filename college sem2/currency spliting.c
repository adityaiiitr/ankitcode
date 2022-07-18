#include<stdio.h>
int main(){
    int currency_array[]={1,2,5,10,20,50,100,200,500,2000};
    int total_money;
    printf("Enter the amount:-");
    scanf("%d",&total_money);
    int i=9,steps=0;
    while(i>0&&total_money>=0){
        if(currency_array[i]>total_money)
            i--;
        else{
            while(1){
                if(total_money-currency_array[i]<0)
                    break;
                else{
                    total_money=total_money-currency_array[i];
                    steps++;
                }
            }
        }
    }
    printf("The minimum number of notes required:-%d",steps);
    return 0;
}
