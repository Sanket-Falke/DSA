#include <stdio.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
        printf("\n");
    }
}
void bubblesort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        
    }
}
void insertionsort(int *a, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] >= key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int partition(int *a,int l,int h){
    int pivot=a[l];
    int i=l+1;
    int j=h;
    int temp;
    do
    {
        while (a[i]<=pivot)
        {
            i++;
        }
        while (a[j]>pivot)
        {
            j--;
        }
        if (i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        
        
        
    } while (i<j);
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
    
}
void quicksort(int *a,int l,int h){
    int partitionindex;
    if (l<h)
    {
        partitionindex=partition(a,l,h);
        quicksort(a,l,partitionindex-1);
        quicksort(a,partitionindex+1,h);
    }
    
}
void merge(int *a,int l,int h,int mid){
    int i=l;
    int j=mid+1;
    int k=l;
    int b[100];
    while (i<=mid && j<=h)
    {
        if (a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }k++;

        
        
    }
    while (i<=mid)
    {
        b[k]=a[i];
        k++;i++;
    }
    while (j<=h)
    {
        b[k]=a[j];
        k++;j++;
    }
    for (int i = 0; i <=h; i++)
    {
        a[i]=b[i];
    }
}
void mergeSort(int *a,int l,int h){
    if (l<h)
    {
        int mid=(l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,h,mid);
    }
    
}

int main()
{
    int n = 5;
    int a[] = {12, 98, 8, 7, 5};
    printf("before sorting\n");
    printArray(a, n);
    // bubblesort(a, n);
    // insertionsort(a, n);
    // quicksort(a,0,n-1);
    mergeSort(a,0,n-1);
    printf("after sorting\n");
    printArray(a, n);
    return 0;
}








