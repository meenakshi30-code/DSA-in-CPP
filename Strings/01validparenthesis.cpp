#include <iostream>
using namespace std;

string removeOuterParentheses(string s) {
    int count = 0;
    string ans = "";

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ')') count--;

        if(count != 0) ans.push_back(s[i]);

        if(s[i] == '(') count++;
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << removeOuterParentheses(s);

    return 0;
}