// LEETCODE 1614 - Maximum Nesting Depth of the Parentheses

#include <iostream>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

int maxDepth(string s) {
    
    int curr = 0;  // current depth
    int res = 0;   // maximum depth

    // Traverse the string
    for(char c : s) {
        
        if(c == '(') {
            curr++;                // increase depth
            res = max(res, curr);  // update max depth
        }
        else if(c == ')') {
            curr--;                // decrease depth
        }
    }

    return res;
}

int main() {
    string s = "(1+(2*3)+((8)/4))+1";

    cout << "Maximum Depth: " << maxDepth(s) << endl;

    return 0;
}