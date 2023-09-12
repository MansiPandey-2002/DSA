//1-->BUBBLE Sort
void bubble(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<(n-1);i++)   
    {
        for(j=0;j<(n-1-i);j++)  
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

//2-->SELECTION SORT
void selection(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)   
    {
        for(j=i+1;j<n;j++)  
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
