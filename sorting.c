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



//3-->INSERTION Sort
void insertion(int *a,int n) 
{
    int i,j,temp;
    for(i=0;i<n;i++)   
    {
        for(j=i;j>0;j--)  
        {
            if(a[j-1]>a[j])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}

//4--> QUICK Sort
void QuickSort(int arr[], int first, int last)
{
 int p,q,pivot,temp;
 if(first<last)
 {
   pivot=first;
   p=first;
   q=last;
   while(p<q)
   {
        while(arr[p]<=arr[pivot] && p<last)   // Move left while i(first) < pivot 
            p++;
        while(arr[q]>arr[pivot])               // Move right while j(last) > pivot 
            q--;
        if(p<q)
        {
            temp=arr[p];
            arr[p]=arr[q];
            arr[p]=temp; 
        }
   }
   temp=arr[pivot];
   arr[pivot]=arr[q];
   arr[q]=temp;
   QuickSort(arr,first,q-1);
   QuickSort(arr,q+1,last);
 }
}


//DISPLAY
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf(" %d ",a[i]);
}

int main()
{
    int n,*a,elem;
    printf("enter number of elements");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("enter elem");
        scanf("%d",&a[i]);

    }
    printf("\nBefore");
    display(a,n);   //Before
    //APPLY ANY SORTING TECHNIQUE HERE
    printf("\nAfter");
    display(a,n);   //After
}
