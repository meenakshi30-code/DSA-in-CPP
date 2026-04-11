#include <iostream>
using namespace std;

//1. BRUTEFORCE ->    TC = O(n^2),    SC = O(n)
// bool rotateString(string s, string goal) {
//     if (s.length() != goal.length()) return false;

//     for (int i = 0; i < s.length(); i++) {
//         string rotated = s.substr(i) + s.substr(0, i);
//         if (rotated == goal) return true;
//     }

//     return false;
// }


//2. OPTIMAL ->      
//   TC = O(n), SC = O(n)
bool rotateString(string s, string goal) {

    if (s.length() != goal.length()) return false;

    string temp = s + s;

    return temp.find(goal) != string::npos;
}


int main() {
    string s, goal;
    cin >> s >> goal;

    cout << rotateString(s, goal);

    return 0;
}