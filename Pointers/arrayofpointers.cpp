#include <iostream>
using namespace std;

int main() {

  //array of pointers
  int* arr[10];
  int a = 1;
  arr[0] = &a;

  cout << arr[0] << endl;
  cout << *arr[0] << endl;

  return 0;
}


