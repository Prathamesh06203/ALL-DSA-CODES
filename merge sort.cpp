#include<iostream>
#include<algorithm>
using namespace std;

int merge(int arr[],int beg,int mid,int end)
{   
    int  n1=mid-beg+1;
    int  n2=end-mid;
    int left[n1],right[n2];

    for(int i=0 ; i<n1 ; i++)
        left[i]=arr[i+beg];

    for(int j=0 ; j<n2 ; j++)
        right[j]=arr[mid+j+1];

    int i=0,j=0,k=beg;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
            k++;
    }

    while(i<n1)
    {
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        k++;
        j++;
    }
}

void merge_sort(int arr[],int beg,int end)
{   
    if(beg<end)
    {
        int mid=beg + (end - beg)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

int main()
{
    int n;
    cout<<"Enter number for elements:";
    cin>>n;
    int arr[n],start=0,end;
    cout<<"Enter elements:\n";
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    end=n-1;
    merge_sort(arr,start,end);
    cout<<"Sorted array is:\n";
     for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}
