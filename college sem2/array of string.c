#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void stringcopy(char *s1,char *s2){
    int i=0;
    while(s2[i]!='\0'){
        s1[i]=s2[i];
        i++;
    }
}
void stringcat(char *s1,char *s2){
    int len=strlen(s1);
    int i=0;
    while(s2[i]!='\0'){
        s1[len++]=s2[i++];
    }
    s1[i]='\0';
}
int stringlen(char s[]){
    int length=0;
    while(s[length]!=0){
        length++;
    }
    return length;
}
int stringequal(char s1[],char s2[]){
    int len1=stringlen(s1);
    int len2=stringlen(s2);
    int i=0;
    int j=len2-1;
    if(len1!=len2)
        return 0;
    else{
        while(s1[i]!='\0'){
            if(s1[i]!=s2[j])
                return 0;
            i++;
            j--;
        }
    }
    return 1;
}
int main(){
    //creating a character array for storing the names
    char s[5][20]={"ramm","shyam","ar","mayhs","soham"};
    int length=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            char *s_cpy1=calloc(20,sizeof(char));
            char *s_cpy2=calloc(20,sizeof(char));
            strcpy(s_cpy1,s[i]);
            strcpy(s_cpy2,s[j]);
            strcat(s_cpy1,s_cpy2);
            char s3[10];
            strcpy(s3,s_cpy1);
            strrev(s3);
            printf("%s %s\n",s_cpy1,s3);
            if(strcmp(s_cpy1,s3)==0)
                length++;
            free(s_cpy1);
            free(s_cpy2);
        }
    }
    printf("%d",length);

    return 0;
}
