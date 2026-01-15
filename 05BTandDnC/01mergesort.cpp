#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

void mergeTwoSortedArrays(int arr1[], int size1, int arr2[], int size2, vector<int>&output) {
  //step1: i and j
  int i=0;
  int j=0;

  //step2: comparison
  while(i<size1 && j<size2) {
    if(arr1[i] < arr2[j]) {
      output.push_back(arr1[i]);
      i++;
    }
    else {
      output.push_back(arr2[j]);
      j++;
    }
  }

  //step3: Copying
  while(i< size1) {
    output.push_back(arr1[i]);
    i++;
  }
  while(j<size2) {
    output.push_back(arr2[j]);
    j++;
  }

}

int main() {
  int arr1[] = {10, 20, 30, 40};
  int size1 = 4;
  int arr2[] = {15, 25};
  int size2 = 2;

  vector<int> output;
  mergeTwoSortedArrays(arr1, size1, arr2, size2, output);

  cout << "Printing output:" << endl;
  for(int i=0; i<6; i++) {
    cout << output[i] << " ";
  }

  return 0;
}