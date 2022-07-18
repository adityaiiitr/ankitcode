#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    else
        return;
}
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    else
        return;
}
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    else
        return;
}
int maximum(int a,int b){
    return a>b?a:b;
}
int height(struct node* root){
    if(root==NULL)
        return 0;
    else
        return maximum(height(root->left),height(root->right))+1;
}
struct node* insert_left(struct node* root,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->data=data;
    newnode->right=NULL;
    root->left=newnode;
    return root;
}
struct node* insert_right(struct node* root,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->data=data;
    newnode->right=NULL;
    root->right=newnode;
    return root;
}
int main(){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=10;
    root=insert_left(root,20);
    root=insert_right(root,30);
    root->left=insert_left(root->left,40);
    root->left=insert_right(root->left,50);
    root->right=insert_left(root->right,60);
    root->right=insert_right(root->right,70);
    printf("Inorder Traversal:-");
    inorder(root);
    printf("\n");
    printf("Preorder Traversal:-");
    preorder(root);
    printf("\n");
    printf("Postorder Traversal:-");
    postorder(root);
    printf("\n");
    printf("The height of the tree is:-%d",height(root)-1);
    int h=height(root)-1;
    printf("\nThe no of leaf nodes is:-%.1f",pow(2,h));
    return 0;
}
