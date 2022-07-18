#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;

};
stack* create(struct stack* st,int size){
    st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=size;
    st->arr=(char*)calloc(size,sizeof(char));
    return st;
}
int isFull(struct stack *st){
    if(st->top==st->size-1)
    return 1;
    else
    return 0;
}
int isEmpty(struct stack *st){
    if(st->top==-1){
        return 1;
    }
    else
    return 0;
}

void push(struct stack *st,char val){
    if(isFull(st)){
        printf("stack overflow");
    }
    else{
        st->top++;
        st->arr[st->top]=val;
    }

}

char pop(struct stack *st){
    if(isEmpty){
        printf("stack is underflow");
        return -1;
    }
    else{
        char val=st->arr[st->top];
        st->top--;
        return val;
    }
}



int isbalance(struct stack *st,char exp[]){
    printf("%s ",exp);
    for(int i=0;exp[i]!='\0';i++){
        //printf("%c ",exp[i]);
        if(exp[i]=='('){
            push(st,'(');
        }
        else if(exp[i]=')'){
            if(isEmpty)
                return 0;
            else
                pop(st);
        }
        else{
            continue;
        }
    }
    if(isEmpty(st))
        return 1;
    else
        return 0;
}
int main(){
    char exp[10];
    struct stack *s=NULL;
    s=create(s,10);

    printf("enter the expression ");
    fgets(exp,sizeof(exp),stdin);
    if(isbalance(s,exp)){
        printf("balanced paranthesis\n");
    }
    else{
        printf("not balanced");
    }
    return 0;

}
