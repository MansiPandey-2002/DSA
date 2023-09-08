//DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    struct node *prev;
    int info;
    struct node *next;
}nodetype;



//1=>INSERTION

//1.1--> Insertion in a empty Doubly Linked List
nodetype* addtoempty(nodetype *head, int elem)
{
    nodetype *p=(nodetype *)malloc(sizeof(nodetype));
    if(p!=NULL)
    {
        p->info=elem;
        p->prev=NULL;
        p->next=NULL;
        head=p; //without *--return value
    }
    return head; 
}

//1.2--> Insertion in a Doubly Linked List from rear side
nodetype* add_right(nodetype *head, int elem)
{
    nodetype *p=(nodetype *)malloc(sizeof(nodetype));
    nodetype *temp=head;
    if(p!=NULL)
    {
        p->info=elem;
        p->prev=NULL;
        p->next=NULL;
        //to add this,reach the end of the list ->TRAVERSE
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
        p->prev=temp;
    }
    return head;
}

//1.3--> Insertion in a Doubly Linked List from front side
nodetype* add_left(nodetype *head, int elem)
{
    nodetype *p=(nodetype *)malloc(sizeof(nodetype));
    if(p!=NULL)
    {
        p->info=elem;
        p->prev=NULL;
        p->next=head;
        head->prev=p;
        head=p;
    }
    return head;
}

//1.4--> Insertion in a Doubly Linked List at a random position
nodetype* in_random(nodetype *head,int elem,int pos)
{
    nodetype *p=(nodetype *)malloc(sizeof(nodetype));
    nodetype *t=head,*t2=NULL;
    if(p!=NULL)
    {
        p->info=elem;
        p->prev=NULL;
        p->next=NULL;
        while(pos>2)
        {
            t=t->next;
            pos--;
        }
        if(t->next==NULL)
        {
            t->next=p;
            p->prev=t;
        }
        else
        {
            t2=t->next;
            t->next=p;
            t2->prev=p;
            p->prev=t;
            p->next=t2;
        }
    }
    return head;
}


//2=>DELETION

//2.1--> Deletion in a Doubly Linked List from rear side
nodetype* del_last(nodetype *head)
{
    nodetype *p=head,*p2=NULL;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p2=p->prev;
    p2->next=NULL;
    free(p);
    p=NULL;
    return head; 
}

//2.2--> Deletion in a Doubly Linked List from front side
nodetype* del_first(nodetype *head)
{
    nodetype *p=head;
    head=head->next;
    free(p);
    p=NULL;
    head->prev=NULL;
    return head;
}

//2.3--> Deletion in a Doubly Linked List from a random position given by user
nodetype* del_random(nodetype *head,int pos)
{
    nodetype *p=head,*p2=NULL;
    if(pos==1)
    {
        head=del_first(head);
        return head;
    }
    while(pos!=1)
    {
        p=p->next;
        pos--;
    }
    p2=p->prev;
    p2->next=p->next;
    p->next->prev=p2;
    free(p);
    p=NULL;
    return head;
}

//3=>DISPLAY
void display(nodetype *p)
{
    while(p!=NULL)
    {
        printf(" %d ",p->info);
        p=p->next;
    }
}

//4=> EXTRA FUNCTIONS

//4.1--> Reversing of a Doubly Linked List
nodetype* reverse(nodetype *head)
{
    nodetype *p=head;
    nodetype *p2=p->next;
    p->next=NULL;
    p->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p;
        p=p2;
        p2=p2->prev;
    }
    head=p;
    return head;
}


int main()
{
    nodetype *head=NULL,*last=NULL;
    int elem,ch,choice=1;
    while(1)
    {
        printf("\nEnter 1 to insert element\nEnter 2 to delete\nEnter 3 to display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter element");
            scanf("%d",&elem);
            if(head==NULL)
                head=addtoempty(head,elem);
            else
                head=add_right(head,elem);
            break;
            case 2:if(head==NULL)
                        printf("dll empty");
                    else
                        head=del_last(head);
            case 3:display(head);
                    break;
            default:exit(1);
        }
        printf("\n1 for continue");
        scanf("%d",&choice);
        if(choice!=1)
            break;
    }
    //can add more functions in main
}




