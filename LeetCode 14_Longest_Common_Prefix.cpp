/*
    LeetCode 14 - Longest Common Prefix

    Approach:
    1. Sort the array of strings.
    2. Compare the first and last strings after sorting.
    3. The common prefix between them is the answer.

    Time Complexity: O(N log N * M)
    Space Complexity: O(1)

    Author: Bhavesh
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: empty array
        if (strs.empty()) {
            return "";
        }

        // Sort the strings
        sort(strs.begin(), strs.end());

        // First and last strings after sorting
        string first = strs[0];
        string last = strs[strs.size() - 1];

        string prefix = "";

        // Compare characters of first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                break;
            }
            prefix += first[i];
        }

        return prefix;
    }
};

int main() {
    Solution solution;

    vector<string> strs = {
        "flower",
        "flow",
        "flight"
    };

    string result = solution.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
