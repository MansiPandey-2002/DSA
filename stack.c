#include<stdio.h>
#define max 10

int push(int stack[],int top)
{
    int elem;
    top++;
    printf("enter element");
    scanf("%d",&elem);
    stack[top]=elem;
    return top;
}

int pop(int stack[],int top)
{
    printf("Element popped is %d",stack[top]);
     top--;
    return top;
}

void display(int stack[],int top)    //in poiners store top in x
{
    while(top>=0)
    {
        printf("%d  ",stack[top]);
        top--;
    }
}

void peek(int stack[],int top)
{
    printf("Peek element is %d",stack[top]);
}
int isfull(int top)
{
    if(top==(max-1))
        return 1;
    else
        return 0;
}
int isempty(int top)
{
    if(top==-1)
        return 1;
    else 
        return 0;
}


int main()
{
    int stack[max],top=-1,ch,x;
    char c;
    do
    {
        printf("\nPress 1 to push\nPress 2 to pop\nPress 3 to peek\nPress 4 to Display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:x=isfull(top);
                    if(x==1)
                        printf("stack is full\n");
                    else
                        top=push(stack,top);
                    break;
            case 2:x=isempty(top);
                    if(x==1)
                        printf("stack is empty\n");
                    else
                        top=pop(stack,top);
                    break;
            case 3:x=isempty(top);
                    if(x==1)
                        printf("stack is empty\n");
                    else
                        peek(stack,top);
                    break;
            case 4: x=isempty(top);
                    if(x==1)
                        printf("stack is empty\n");
                    else
                        display(stack,top);
                    break;
            default:printf("invalid choice");
                    break;
        }
        getchar();
        printf("do you want to continue?press y");
        scanf("%c",&c);
    }
    while(c=='y'|| c=='Y');
}