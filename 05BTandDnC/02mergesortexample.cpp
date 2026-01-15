#include <iostream>
3include <limits.h>
using namespace std;

void merge(int arr[], int s, int e, int mid) {
  //create copy of left and right sorted array
  int leftArrayLength = mid-s+1;
  int rightArrayLength = e-mid;

  int* arr1 = new int[leftArrayLength];
  int* arr2 = new int[rightArrayLength];

  int mainArrayIndex = s;
  for(int i=0; i<leftArrayLength; i++) {
    arr1[i] = arr[mainArrayIndex];
    mainArrayIndex++;
  }
  mainArrayIndex = mid+1;
  for(int i=0; i<rightArrayLength;i++) {
    arr2[i] = arr[mainArrayIndex];
    mainArrayIndex++;
  }


  //merge sorted array logic into the original array
  int i=0; //arr1
  int j=0; //arr2
  mainArrayIndex = s; //arr
  while(i < leftArrayLength && j < rightArrayLength) {
    if(arr1[i] < arr2[j]) {
      arr[mainArrayIndex] = arr1[i];
      i++;
      mainArrayIndex++;
    }
    else {
      arr[mainArrayIndex] = arr2[j];
      j++;
      mainArrayIndex++;
    }
  }
  //copying logic
  while(i < leftArrayLength) {
    arr[mainArrayIndex] = arr1[i];
      i++;
      mainArrayIndex++;
  }
  while(j < rightArrayLength) {
    arr[mainArrayIndex] = arr2[j];
      j++;
      mainArrayIndex++;
  }
  delete[] arr1;
  delete[] arr2;
}

void mergeSort(int arr[], int s, int start, int end) {
  //base case
  if(s>=e) {
    return;
  }

  //ek bade array ko 2 parts me divide krte the
  int mid = (s+e)/2;
  //left part ko recursion se solve krwate the
  mergeSort(arr, s, mid);
  //right part ko recursion se solve krwate the
  mergeSort(arr, mid+1, e);
  //recursion ne jo sorted arrays dia he unko merge krte the
  merge(arr, s, e, mid);

}

int main() {
  int arr[] = {7,2,4,3,1,5};
  int size = 6;
  int start = 0;
  int end = size - 1;

  mergeSort(arr, start, end);

  cout << "Printing the sorted array: " << endl;
  for(int i=0; i<size; i++) {
    cout << arr[i] << " ";
  }
}
