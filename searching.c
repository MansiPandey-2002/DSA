//1--> LINEAR  Search
int linear(int a[],int n,int elem)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==elem)
        {
            return i+1;
        }
    }
    return 0;
}


//2--> BINARY ITERATIVE Search
int Binary_iter(int a[],int n,int elem)
{
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==elem)
            return mid+1;
        else if(elem<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}

//3--> BINARY RECURSION Search
int Binary_recursion(int a[],int l,int h,int elem)
{
    int mid;
    if(l==h)
    {
        if(a[l]==elem)
            return l+1;
    }
    else
    {
        mid=(l+h)/2;
        if(a[mid]==elem)
            return mid+1;
        else if(elem<a[mid])
            return Binary_recursion(a,l,mid-1,elem);
        else
            return Binary_recursion(a,mid+1,h,elem);
    }
    return 0;
}

//4--> JUMP Search
int jump_search(int a[],int n,int elem)
{
    int i;
    int low=0;
    int high=sqrt(n);
    while(a[high]<=elem && high<n)
    {
        low=high;
        high+=sqrt(n);
        if(high>n-1)
            high=n;
    }
    for(i=low;i<high;i++)
    {
        if(a[i]==elem)
            return i+1;
    }
    return 0;
}
