// LEETCODE 13 - Roman to Integer

#include <iostream>
#include <unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

int romanToInt(string s) {

    // Roman values map
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100},
        {'D', 500}, {'M', 1000}
    };

    int res = 0;

    // Traverse till second last character
    for(int i = 0; i < s.size() - 1; i++) {

        // If next value is bigger → subtract
        if(roman[s[i]] < roman[s[i + 1]]) {
            res -= roman[s[i]];
        }
        else {
            res += roman[s[i]];
        }
    }

    // Add last character value
    res += roman[s.back()];

    return res;
}

int main() {
    string s = "MCMXCIV";

    cout << "Integer value: " << romanToInt(s) << endl;

    return 0;
}