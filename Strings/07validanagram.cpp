#include <iostream>
using namespace std;

// 1. BRUTEFORCE      TC = O(N logN)   SC = O(1)
// bool isAnagram(string s, string t) {
//     if (s.length() != t.length()) return false;

//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());

//     return s == t;
// }


// 2. OPTIMAL    TC = o(N), SC = O(1)
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}


int main() {
    string s, t;
    cin >> s >> t;

    cout << isAnagram(s, t);

    return 0;
}