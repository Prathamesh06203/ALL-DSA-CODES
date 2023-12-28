#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
  int pivot = arr[start];
  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot)
      count++;
  }

  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);
  int i = start, j = end;

  while (i < pivotIndex && j > pivotIndex) {
    while (arr[i] <= pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i < pivotIndex && j > pivotIndex) {
      swap(arr[i], arr[j]);
    }
  }
  return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
  if (start >= end)
    return;
  int p = partition(arr, start, end);
  quickSort(arr, start, p - 1);
  quickSort(arr, p + 1, end);
}

int main() {
  int arr[10];
  int n,t;
  do{
  cout << "Enter number of elements: ";
  cin >> n;
  cout << "Enter the elements: " << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  quickSort(arr, 0, n - 1);

  cout << "Sorted order" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\nWnat to Perform the Next(1.YES/2.NO) : " << endl;
  cin>>t;
  
  }while(t==1);
  return 0;
}