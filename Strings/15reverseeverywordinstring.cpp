#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s) {

    // Step 1: reverse whole string
    reverse(s.begin(), s.end());

    int n = s.length();

    // Step 2: reverse each word
    for(int j = 0; j < n; j++) {
        if(s[j] != ' ') {
            int start = j;

            while(j < n && s[j] != ' ') j++;

            reverse(s.begin() + start, s.begin() + j);
        }
    }

    // Step 3: remove extra spaces
    string result = "";

    for(int i = 0; i < n; i++) {
        if(s[i] != ' ') {
            result += s[i];
        } else {
            if(!result.empty() && result.back() != ' ') {
                result += ' ';
            }
        }
    }

    // remove trailing space
    if(!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int main() {
    string s;

    getline(cin, s);

    string ans = reverseWords(s);

    cout << ans << endl;

    return 0;
}