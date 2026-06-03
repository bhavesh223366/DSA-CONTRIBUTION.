/*
LeetCode 387. First Unique Character in a String

Approach:
1. Count the frequency of each character using an array of size 26.
2. Traverse the string again and find the first character whose frequency is 1.
3. Return its index.
4. If no such character exists, return -1.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Find first unique character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    string s1 = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";

    cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.firstUniqChar(s1) << endl;

    cout << "\nInput: " << s2 << endl;
    cout << "Output: " << obj.firstUniqChar(s2) << endl;

    cout << "\nInput: " << s3 << endl;
    cout << "Output: " << obj.firstUniqChar(s3) << endl;

    return 0;
}
