#include<stdio.h>
#include<stdlib.h> 
struct binary 
{   
  int data;    
  struct binary *lchild, *rchild; 
}; 
struct binary* create()      
{
    char ch;  
    struct binary *r=NULL; 
    r=(struct binary*)malloc(sizeof(struct binary));
    r->lchild=NULL;  
    r->rchild=NULL; 
    printf("Enter the data: ");  
    scanf("%d",&r->data);  
    printf("Does %d have left child (y/n):",r->data); 
    scanf("%c",&ch); 
    scanf("%c",&ch); 
    if(ch=='y'||ch=='Y') 
        r->lchild=create(); 
    printf("Does %d have right child (y/n):",r->data); 
    scanf("%c",&ch); 
    scanf("%c",&ch); 
    if(ch=='y'||ch=='Y') 
        r->rchild=create(); 
     return r; 
 } 
void inorder(struct binary *tree) 
{ 
if(tree!=NULL) 
    { 
        inorder(tree->lchild); 
        printf("%d\t",tree->data);   
        inorder(tree->rchild); 
    } 
} 
void preorder(struct binary *tree) 
{ 
if(tree!=NULL) 
    { 
        printf("%d\t",tree->data);      
        preorder(tree->lchild);        
        preorder(tree->rchild); 
    } 
} 
void postorder(struct binary *tree) 
{ 
if(tree!=NULL) 
    { 
        postorder(tree->lchild); 
        postorder(tree->rchild);    
        printf("%d\t",tree->data); 
    } 
} 
void main() 
{ 
    struct binary *root; 
    printf("\nEnter tree elements starting from root\n");
    root=create();  
    printf("\nPreorder Traversal......\n");
    preorder(root); 
    printf("\nInorder Traversal......\n");
    inorder(root); 
    printf("\nPostorder Traversal......\n");  
    postorder(root); 
}