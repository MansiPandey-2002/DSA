//CIRCULAR LINKED LIST INTERNAL IMPLEMENTATIONS
#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int info;
    struct node *next;
}node;

//1=> INSERTION

//1.1-->Insertion in a Circular Linked List from rear side
node* insert_last(node *tail,int elem)
{
    node *p=(node*)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info=elem;
        p->next=p;
        if(tail==NULL)
            tail=p;
        else
        {
            p->next=tail->next;
            tail->next=p;
            tail=tail->next;
        }
    }
    return tail;
}

//1.2-->Insertion in a Circular Linked List from front side
node* insert_first(node *tail,int elem)
{
    node *p=(node*)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info=elem;
        p->next=p;
        if(tail==NULL)
            tail=p;
        else
        {
            p->next=tail->next;
            tail->next=p;
        }
    }
    return tail;
}

//2=> DELETION

//2.1-->Deletion in a Circular Linked List from front side
node* del_first(node *tail)
{
    node *p=tail->next;
    if(p->next==p)
    {
        free(tail);
        tail=NULL;
    }
    else
    {
        tail->next=p->next;
        free(p);
        p=NULL;
    }
    return tail;
}

//2.2-->Deletion in a Circular Linked List from rear side [Method 1]
node* delete_last(node *tail)
{
    node *p=tail->next;
    node *p2=NULL;
    if(p->next==p)
    {
        free(tail);
        tail=NULL;
    }
    else
    {
        while(p->next!=tail)
        {
            p=p->next;
        }
        p2=p->next;
        p->next=p2->next;
        tail=p;
        free(p2);
        p2=NULL;
    }
    return tail;
}

//2.3-->Deletion in a Circular Linked List from rear side [Method 2]
node* del_last(node *tail)
{
    node *temp=tail->next;
    if(temp->next=temp)
    {
        free(tail);
        tail=NULL;
    }
    else
    {
        node *t1=tail;
        while(temp->next!=tail)
            temp=temp->next;
        temp->next=tail->next;
        tail=temp;
        free(t1);
        t1=NULL;
    }
    return tail;
}

//2.4-->Deletion in a Circular Linked List at a particular node given by user
node* search_del(node *tail,int key)
{
    node *temp=tail->next;
    do
    {
        if(temp->info==key)
        {
            if(tail->next=tail)
            {
                free(tail);
                tail=NULL;
                break; //else loop continues for segmentaion fault
            }
            else
            {
                node *t1=tail->next;
                node *t2=temp;
                while(t1->next!=temp)
                    t1=t1->next;
                t1->next=temp->next;
                temp=temp->next;
                free(t2);
                t2=NULL;
                break;
            }
        }
        temp=temp->next;
    }while(temp!=tail->next);
    return tail;
}


node* ran_insert(node *tail,int key,int pos)
{
    node *temp=tail->next;
    node *p=(node*)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info=key;
        p->next=p;
        if(pos==1)
        {
            p->next=tail->next;
            tail->next=p;
        }
        else
        {
            while(pos>2)
            {
                temp=temp->next;
                pos--;
            }
            if(temp->next==NULL)
            {
                p->next=tail->next;
                temp->next=p;
                tail=p;
            }
            else
            {
                node *t1=temp->next;
                p->next=temp->next;
                temp->next=p;
            }
        }
    } 
    return tail;
}



void display(node *tail)
{
    node *p=tail->next;
    do
    {
        printf("%d ",p->info);
        p=p->next;
    } while (p!=tail->next);
}
 
 //count nodes
int count(node *tail)
{
    int c=0;
    node *p=tail->next;
    do
    {
        c++;
        p=p->next;
    } while (p!=tail->next);
    return c;
}


int main()
{
    int elem,pos,ch,c;
    node *tail=NULL;
    while(1)
    {
        printf("Enter  element");
        scanf("%d",&elem);
        tail=insert_last(tail,elem);
        printf("\npress 1 to continue");
        scanf("%d",&ch);
        if(ch!=1)
            break;
    }
   //other functions can be added
}
    
