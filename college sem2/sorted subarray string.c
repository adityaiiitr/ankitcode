#include<stdio.h>
#include<math.h>
#include<string.h>
int repetition(char s[],int start,int end){
    int check_repeat=0;//0 for false means no repetition
    for(int i=start;i<=end;i++){
        for(int j=i+1;j<=end;j++){
            if(s[i]==s[j]){
                check_repeat=1;
                break;
            }
        }
    }
    return check_repeat;
}
int max(int x,int y){
    if(x>y)
        return x;
    else
        return y;
}
int longestsubstring(char s[],int n){
    int maxlength=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(repetition(s,i,j)==0)
                maxlength=max(maxlength,j-i+1);
        }
    }
    return maxlength;
}
int main(){
    char s[]="bb";
    int n=strlen(s);
    int max=longestsubstring(s,n);
    printf("%d",max);
    return 0;
}
