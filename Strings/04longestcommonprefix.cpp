#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& str) {
    sort(str.begin(), str.end());
    string first = str[0];
    string last = str.back();

    string ans = "";

    for(int i = 0; i < min(first.size(), last.size()); i++) {
        if(first[i] != last[i]) break;
        ans += first[i];
    }

    return ans;
}

int main() {
    vector<string> str = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(str);

    return 0;
}