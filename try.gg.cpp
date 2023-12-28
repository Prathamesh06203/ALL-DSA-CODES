#include<iostream>
using namespace std;
int partition(int arr[],int start,int end)
{
    int count;
    int pivot=arr[start];
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=pivot)
        count++;
    }
    int pivotindex=start+count;
    swap(arr[pivotindex],arr[start]);
    int i = start;
    int j = end;
    while(i<pivotindex&&j>pivotindex)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<pivotindex&&j>pivotindex)
        {
            swap(arr[i],arr[j]);
        }
    }
    return j;
}
void quicksort(int arr[],int start,int end)
{
    int p;
    if(start<end)
    {
        p = partition(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }
}
 main()
 {
    int arr[10];
    int t,n;
    cout<<"Enter number of number " << endl;
    cin>>n;
    cout << "Enter Numbers " << endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"Sorted Arrary is " <<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << endl;
    }
    return 0;
 }