// LEETCODE 451 - Sort Characters by Frequency

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// approach - using frequency array + sorting
//only for lowercase letters 
// TC = O(n + 26 log 26)=  O(n)     //Sc = O(1)
// vector<char> frequencySort(string s) {

//     // Step 1: freq array (a-z)
//     vector<pair<int,char>> freq(26);

//     // initialize
//     for(int i = 0; i < 26; i++) {
//         freq[i] = {0, char(i + 'a')};
//     }

//     // Step 2: count frequency
//     for(char ch : s) {
//         freq[ch - 'a'].first++;
//     }

//     // Step 3: sort
//     sort(freq.begin(), freq.end(), [](auto &a, auto &b){
//         if(a.first != b.first)
//             return a.first > b.first;   // higher freq first
//         return a.second < b.second;     // alphabetical
//     });

//     // Step 4: store result
//     vector<char> ans;

//     for(auto p : freq) {
//         if(p.first > 0) {
//             ans.push_back(p.second);
//         }
//     }

//     return ans;
// }



// APPROACH 1: HashMap + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(n)
string approach1(string s) {
    
    unordered_map<char,int> freq;

    // Step 1: Count frequency of each character
    for(char c : s) {
        freq[c]++;
    }

    // Step 2: Store (char, frequency) in vector
    vector<pair<char,int>> v(freq.begin(), freq.end());

    // Step 3: Sort by frequency (descending)
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });

    // Step 4: Build result string
    string ans = "";
    for(auto p : v) {
        ans += string(p.second, p.first);  // repeat char
    }

    return ans;
}


// APPROACH 2: Priority Queue (Max Heap)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
string approach2(string s) {

    unordered_map<char,int> freq;

    // Step 1: Count frequency
    for(char c : s) {
        freq[c]++;
    }

    // Step 2: Max Heap (store freq, char)
    priority_queue<pair<int,char>> pq;

    for(auto p : freq) {
        pq.push({p.second, p.first});
    }

    string ans = "";

    // Step 3: Extract highest frequency first
    while(!pq.empty()) {
        int count = pq.top().first;
        char ch = pq.top().second;
        pq.pop();

        // Step 4: Add character 'count' times
        while(count--) {
            ans += ch;
        }
    }

    return ans;
}


// APPROACH 3: Bucket Sort (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(n)
string approach3(string s) {

    unordered_map<char,int> freq;

    // Step 1: Count frequency
    for(char c : s) {
        freq[c]++;
    }

    int n = s.size();

    // Step 2: Create buckets (index = frequency)
    vector<string> bucket(n + 1);

    for(auto p : freq) {
        bucket[p.second] += string(p.second, p.first);
    }

    string ans = "";

    // Step 3: Traverse from high freq to low
    for(int i = n; i >= 1; i--) {
        ans += bucket[i];
    }

    return ans;
}


// MAIN FUNCTION

int main() {
    string s = "tree";

    cout << "Approach 1: " << approach1(s) << endl;
    cout << "Approach 2: " << approach2(s) << endl;
    cout << "Approach 3: " << approach3(s) << endl;

    return 0;
}