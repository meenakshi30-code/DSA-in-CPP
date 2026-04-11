#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {

    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    int n = s.length();

    for(int i = 0; i < n; i++) {
        char ch1 = s[i];
        char ch2 = t[i];

        if( (mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) ||
            (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1) ) {
            return false;
        }

        mp1[ch1] = ch2;
        mp2[ch2] = ch1;
    }

    return true;
}

int main() {
    string s, t;
    cin >> s >> t;

    bool ans = isIsomorphic(s, t);

    cout << ans << endl;   // 1 = true, 0 = false

    return 0;
}