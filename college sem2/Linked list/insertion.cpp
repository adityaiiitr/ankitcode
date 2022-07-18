#include<iostream>
using namespace std;
class node{
public:
    int value;
node *next;
};
node *atend(node *head){
    node *traverse,*newnode;
    traverse=head;
    int data;
    cout<<"Enter the data:-";
    cin>>data;
    newnode=new node();
    newnode->value=data;
    while(traverse->next!=NULL)
        traverse=traverse->next;
    traverse->next=newnode;
    newnode->next=NULL;
    return head;
}
int main(){
    node *head;
    node *first=new node();
    int n;
    cout<<"Enter the data:-";
    cin>>n;
    first->value=n;
    head=first;
    for(int i=0;i<2;i++)
        head=atend(head);
    node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->value<<endl;
        temp=temp->next;
    }
    return 0;
}
