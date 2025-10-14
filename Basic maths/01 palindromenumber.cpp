#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;

    long rev = 0;
    int temp = x;

    while (x != 0) {
        int digit = x % 10;
        rev = rev * 10 + digit;
        x /= 10;
    }

    return rev == temp;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}
