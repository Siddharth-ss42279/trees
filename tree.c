#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node *root=NULL;

struct node* put(struct node* x,int data)
{
    if(x==NULL)
    {
        x=malloc(sizeof(node));
        x->left=NULL;
        x->right=NULL;
        x->data=data;
        return x;
    }
    else if(x->data > data)   x->left=put(x->left,data);
    else if(x->data < data)  x->right=put(x->right,data);
    return x;
}
struct node* min(struct node *root)
{ 
    if(root->left==NULL)
        return root;
    else
        root=min(root->left);
    
    
    
}
struct node* max(struct node* root)
{
    if(root->right==NULL)
        return root;
    else
        root=max(root->right);
    
}
int height(struct node *root)
{
    
    if(root==NULL) return 0;
    else {
        int l=height(root->left);
        int r=height(root->right);
        
        if(l>r)
            return (l+1);
        else
            return (r+1);
        
        
    }
}
struct node* deletemin(struct node *x)
{
    
    if(x == NULL){
       return x;
    }
    
    if(x->left == NULL)
        return x->right;
    
    x-> left = deletemin(x->left);
    
    return x;
    
    /*if(x == NULL) free(x);
    
    while(x!=NULL) {
        if(x->left == NULL) {
            if(x->left->right!= NULL)
                x->left = x->left->right; 
               else if(x->right==NULL) {
                  x->left = NULL;              
               }
        }    
        x=x->left;
        }
      */     
}

//struct node* floor(struct node *x)
//{
//}
int main()
{
    
    root=put(root,5);
    put(root,4);
    put(root,6);
    put(root,34);
    put(root,2);
    printf("min in tree = %d\n",min(root)->data);
    printf("max in tree =%d\n",max(root)->data);
    printf("height =%d\n",height(root));
    deletemin(root);
    printf("updated minimum value after deleting minimum is =%d\n",min(root)->data);
    return 0;
}
