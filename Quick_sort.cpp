/*//1.pivot element as the first element of the array
#include<iostream>
using namespace std;
int Partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    int temp;
    while(i<j)
    {
        do
        {
            i++;
        }
        while(pivot>=arr[i]);
        do
        {
            j--;
        }
        while(pivot<arr[j]);
        if(i<j)
        {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    arr[low]=arr[j];
    arr[j]=pivot;

    return j;
}

void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pivot=Partition(arr,low,high);
        quickSort(arr,low,pivot);
        quickSort(arr,pivot+1,high);
    }
}

int main()
{
    int arr[]= {1,10,3,99,23,12,67,87,34,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"original array:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    quickSort(arr,0,size);

    cout<<"sorted array:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

*/



//2.pivot element as the last element of the array
#include<iostream>
using namespace std;
int Partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low;
    int j=high;
    int temp;
    while(i<j)
    {
        do
        {
            i++;
        }
        while(pivot>arr[i]);
        do
        {
            j--;
        }
        while(pivot<=arr[j]);
        if(i<j)
        {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    arr[high]=arr[i];
    arr[i]=pivot;

    return i;
}

void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pivot=Partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot,high);
    }
}

int main()
{
    int arr[]= {1,10,3,99,23,12,67,87,34,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"original array:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    quickSort(arr,0,size-1);

    cout<<"sorted array:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}



