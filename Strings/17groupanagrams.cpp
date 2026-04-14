#include <iostream>        
#include <vector>         
#include <string>         
#include <unordered_map>   
#include <algorithm>     
using namespace std;

//  Group Anagrams (LeetCode 49)
// Approach 1: Sorting Based

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for(int i = 0; i < strs.size(); i++) {
        string temp = strs[i];

        sort(temp.begin(), temp.end()); // O(k log k)

        mp[temp].push_back(strs[i]);
    }

    vector<vector<string>> result;

    for(auto it : mp) {
        result.push_back(it.second);
    }

    return result;
}

//Time Complexity: O(n * k log k)
// Space Complexity: O(n * k)

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto group : ans) {
        for(auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}