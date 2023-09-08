#include<stdio.h>
#define max 10
int isfull(int);
int isempty(int,int);
int enqueue(int[],int,int);
int dequeue(int[],int);
void peek(int [],int);
void display(int [],int,int);

int main()
{
    int q[max],f=-1,r=-1,elem,temp,ch,x;
    char c;
    do
    {
        printf("\nPress 1 to enqueue\nPress 2 to dequeue\nPress 3 to peek\nPress 4 to Display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:x=isfull(r);
                if(x==1)
                    printf("queue is full");
                else
                {
                    printf("enter element");
                    scanf("%d",&elem);
                    if(f==-1 && r==-1)    //we cant return f and r both in function wo ptr. so did in main
                    {
                        f=r=0;
                        q[r]=elem;
                    }
                    else
                        r=enqueue(q,r,elem);
                }
                break;
            case 2:x=isempty(f,r);
                    if(x==1)
                        printf("queue is empty");
                   if(f!=-1 && f==r)   //if one element 
                    {
                        temp=q[f];
                        f=r=-1;
                    }
                    else
                        f=dequeue(q,f);
                    break;
            case 3:x=isempty(f,r);
                    if(x==1)
                        printf("queue is empty"); 
                    else
                        peek(q,f);
                    break;
            case 4:x=isempty(f,r);
                    if(x==1)
                        printf("queue is empty");
                    else
                        display(q,f,r);
                    
                   break;
            default:printf("wrong input");    
                    break;
        }
        getchar();
        printf("\nydo u want to continue..enter y");
        scanf("%c",&c);
    }
    while(c=='y');
}

int isfull(int r)
{
    if(r==(max-1))
        return 1;
    else
        return 0;
}

int isempty(int f,int r)
{
    if(f==-1 && r==-1)
        return 1;
    else
        return 0;
}
int enqueue(int q[],int r,int elem)   
{
    r++;
    q[r]=elem;
    return r;
}

int dequeue(int q[],int f)
{
    printf("deleted element is %d",q[f]);
    f++;
    return f;
}

void peek(int q[],int f)
{
    printf("peek: %d ",q[f]);
}

void display(int q[],int f,int r)
{
    while(f<=r)
    {
        printf("%d",q[f]);
        f++;
    }
}





