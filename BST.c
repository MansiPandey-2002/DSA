//binary search tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    struct node *left;
    int info;
    struct node *right;
}treetype;

//Creating a Binary Search Tree
treetype* create(int data)
{
    treetype *p=(treetype*)malloc(sizeof(treetype));
    if(p!=NULL)
    {
        p->info=data;
        p->left=NULL;
        p->right=NULL;
    }
    return p;
}

//1=> INSERTION
void insert(treetype **r,treetype *p) //for recursion  pass p 
{
    if(*r==NULL)
        *r=p;
    else
    {
        if((p->info)<(*r)->info)
            insert((&(*r)->left),p);
        else    
            insert((&(*r)->right),p);
    }
}

//2=>DISPLAY

//2.1-> Inorder Display
void inorder(treetype *root)  //ascending
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n",root->info);
        inorder(root->right);
    }
}
//2.2-> Preorder Display
void preorder(treetype *root) //nlr
{
    if(root!=NULL)
    {
        printf("%d\n",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

//2.3-> Postorder Display
void postorder(treetype *root)//lrn
{
    if(root!=NULL)
    {
        postrder(root->left);
        postorder(root->right);
        printf("%d\n",root->info);
    }
}

//3=> Extra Funtions

//3.1--> Printing Leaf Nodes
void leaf(treetype *root,int *c)
{
    if(root==NULL)
        return;
    else
    {
        if(root->left==NULL && root->right==NULL)
            (*c)++;
        count(root->left,c);
        count(root->right,c);
    }
}

//3.2--> Printing Single Parent Nodes
void single(treetype *r,int *c)
{
    if(r==NULL)
        return;
    else
    {
        if((r->left==NULL && r->right!=NULL) || (r->left!=NULL && r->right==NULL ))
            (*c)++;
        single(r->left,c);
        single(r->right,c);
    }
}

//3.3--> Searching a key in BST
void search(treetype *root,int key)
{
    if(root==NULL)
        return;
    if(root->info==key)
        printf("key found");
    if(key<(root->info))
        search((root->left),key); 
    if(key>(root->info))
        search((root->right),key);
}

//3.4--> Printing Height of a BST
int height(treetype *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lh=(height(root->left));
        int rh=(height(root->right));
    if(lh>rh)
        return lh+1;
    else
        return rh+1;
    }
}

//3.5--> Printing Maximum valued node
void maximum(treetype *r,int *max)
{
    if(r==NULL)
        return;
    else if(r->right==NULL)
        (*max)=r->info;
    else
        maximum(r->right,max);
}

//3.6--> Printing Minimum valued node
void minimum(treetype *r,int *min)
{
    if(r==NULL)
        return;
    else if(r->left==NULL)
        (*min)=r->info;
    else
        minimum(r->left,min);
}


int main()
{
    treetype *root=NULL,*p=NULL;
    int elem;
    char choice;
    while(1)
    {
        treetype *p=(treetype*)malloc(sizeof(treetype));
        if(p!=NULL)
        {
            printf("enter element");
            scanf("%d",&elem);
            p->info=elem;
            p->left=NULL;
            p->right=NULL;
            insert(&root,p);
        }
        getchar();
        printf("press y to continue");
        scanf("%c",&choice);
        if(choice!='y')
            break;
    }
    //add any function you want
}


