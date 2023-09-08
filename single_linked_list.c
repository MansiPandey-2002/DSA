#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}nodetype;


//1=>INSERTION

//1.1--> Insertion in an empty Linked List
nodetype* add_empty(nodetype *head,int elem)
{
    nodetype *p=(nodetype*)malloc(sizeof(nodetype));
    if(p!=NULL)
    {
        p->info=elem;
        p->next=NULL;
        head=p;
    }
    return head;
}

//1.2--> Insertion in a Linked List from right end
nodetype* add_last(nodetype *head,int elem)
{
    nodetype *p=(nodetype*)malloc(sizeof(nodetype));
    nodetype *temp=head;
    //temp=head;
    if(p!=NULL)
    {
        p->info=elem;
        p->next=NULL;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=p;
    }
    return head;
}


//1.3-->searching and adding node after that
nodetype* search(nodetype *head)
{
    int n,flag=0,elem;
    printf("\nenter num");
    scanf("%d",&n);
    nodetype *temp=head,*t2=head;
    while(temp!=NULL)
    {
        if(temp->info==n)
        {
            nodetype *p=(nodetype*)malloc(sizeof(nodetype));
            printf("\nKey found\nenter elem for node");
            scanf("%d",&elem);
            p->info=elem;
            p->next=temp->next;
            temp->next=p;
        }
        temp=temp->next;
    }
    return head;
}

//1.4--> Inserting at random position given by user
nodetype* insert_random(nodetype *head,int elem,int pos)
{
    nodetype *p1=head;
    nodetype *p=(nodetype*)malloc(sizeof(nodetype));
    if(p!=NULL)
    {
        p->info=elem;
        p->next=NULL;
        while(pos>2)
        {
            p1=p1->next;
            pos--;
        }
        p->next=p1->next;
        p1->next=p;
    }
    return head;
}

//2=>DELETION

//2.1->Deletion from right end of Linked list
nodetype* delete_end(nodetype *head)
{
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("deleted");
    }//p2 represents second last node
    else
    {
        nodetype *p2=NULL,*p=head;
        while(p->next!=NULL)
        {
            p2=p;
            p=p->next;
        }
        p2->next=NULL;
        free(p);
        p=NULL;
    }
    return head;
}

//2.2->Deletion from left end of Linked list
nodetype* del_left(nodetype *head)
{
    nodetype *temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    return head;
}

//2.3->Deletion at random by position given by user
nodetype* del_random(nodetype *head,int pos)
{
    if(head==NULL)
        printf("empty");
    nodetype *p=head,*p2=NULL;
    while(pos!=1)
    {
        p2=p;
        p=p->next;
        pos--;
    }
    p2->next=p->next;
    free(p);
    p=NULL;
    return head;
}

//2.4->Deletion at random by element if found
nodetype* deletion_random(nodetype *head,int key)
{
    nodetype *t=head;
    while(t!=NULL)
    {
        if(t->info==key)
        {
            if(head->next==NULL)
            {
                free(head);
                head=NULL;
                break;
            }
            else
            {
                nodetype *t2=head;
                while(t2->next!=t)
                    t2=t2->next;
                nodetype *temp=t;
                t2->next=t->next;
                free(temp);
                temp=NULL;
                break;
            }
        }
        t=t->next;
    }
    return head;
}

//2.5->Deletion of Duplicate elements in Linked List
nodetype* del_dup(nodetype *head)
{
    nodetype *p1=head;
    nodetype *p2=NULL;
    while(p1!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p1->info==p2->info)
            {
                nodetype *temp=p2;
                nodetype *x=head;
                while(x->next!=p2)
                    x=x->next;
                x->next=p2->next;
                free(temp);
                temp=NULL;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    return head;
} 

//3=>DISPLAY Linked List
void display(nodetype *p)
{
    while(p)
    {
        printf("%d  ",p->info);
        p=p->next;
    }
}

//4=>Extra functions

//4.1->Insert 2 linked lists,find common elements ,put in linked list 3(head3)
void separate(nodetype *h1,nodetype *h2,nodetype **h3)
{
    nodetype *temp=NULL;
    while(h1!=NULL)
    {
        temp=h2;
        while(temp!=NULL)
        {
            if((temp->info)==(h1->info))
                (*h3)=add_last((*h3),(h1->info));  //using a previously defined function
            temp=temp->next;
        }
        h1=h1->next;
    }
}

//4.2-> Print similar nodes
void similar(nodetype *p,nodetype *q)  
{
    nodetype *p1=NULL,*p2=NULL;
    p1=p;
    while(p1!=NULL)
    {
        p2=q; //imp
        while(p2!=NULL)
        {
            if(p1->info==p2->info)
                printf(" %d",p1->info);
            p2=p2->next;
        }
        p1=p1->next;
    }
}
//4.3-> Print palindrome nodes
void palindrome(nodetype *head)
{
    int n,rev;
    nodetype *p=head;
    while(p!=NULL)
    {
        rev=0;
        n=p->info;
        while(n>0)
        {
            rev=(rev*10)+(n%10);
            n=n/10;
        }
        if(rev==(p->info))
            printf("\npalindrome");
        else
            printf("\nnot palindrome");
        p=p->next;
    }
}

//4.4-> Reversing the Linked List
void reverse (nodetype **head)
{
    nodetype *prev,*next;
    while(*head!=NULL)
    {
        next=(*head)->next;
        (*head)->next=prev;
        prev=*head;
        *head=next;
    }
    *head=prev;
}




int main()
{
    int elem,res,c;
    char choice;
    nodetype *head=NULL;
    while(1)
    {
            printf("Enter 1 to insert element\nEnter 2 to delete\nEnter 3 to display");
            scanf("%d",&c);
            switch(c)
            {
                case 1: printf("enter element");
                        scanf("%d",&elem);
                        if(head==NULL)
                            head=add_empty(head,elem);
                        else
                            head=add_last(head,elem);
                        break;
                case 2:if(head==NULL)
                            printf("empty");
                        else
                            head=delete_end(head);
                        break;
                case 3:display(head);
                        break;
                default: break;
            }
        getchar();
        printf("press y to continue");
        scanf("%c",&choice);
        if(choice!='y')
            break;
    }
    return 0;
    
}





