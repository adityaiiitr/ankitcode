#include<stdio.h>
#include<stdlib.h>
struct node{
    int coefficient;
    int power;
    struct node* next;

};
struct node* insert(struct node* head){
    int coeff,pow;
    printf("Enter the coefficient:-");
    scanf("%d",&coeff);
    printf("Enter the power:-");
    scanf("%d",&pow);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coefficient=coeff;
    newnode->power=pow;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
void add(struct node* head1,struct node* head2){
    struct node* temp1=head1;
    struct node* temp2=head2;
    while(temp1!=NULL){
        while(temp2!=NULL){
            if(temp1->power==temp2->power){
                printf("x^%d:-%d\n",temp2->power,temp1->coefficient+temp2->coefficient);
            }
            temp2=temp2->next;
        }
        temp2=head2;
        temp1=temp1->next;
    }
}
int main(){
    struct node* head1;
    struct node* head2;
    head1=insert(head1);
    head1=insert(head1);
    head2=insert(head2);
    head2=insert(head2);
    add(head1,head2);
    return 0;
}
