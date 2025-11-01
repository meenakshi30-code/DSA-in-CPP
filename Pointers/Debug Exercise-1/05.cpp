#include <iostream>
using namespace std;

int main(){
    int p = 5;
    int const *q = &p;
    p++;
    cout << p << endl;
    cout << q << endl;
    cout << *q << endl;
  
  return 0;
}