/*
LeetCode 647 - Palindromic Substrings

Approaches:
1. Brute Force           -> O(n^3), O(1)
2. Dynamic Programming   -> O(n^2), O(n^2)
3. Expand Around Center  -> O(n^2), O(1)  [Interview Optimal]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =====================================================
    // Approach 1 : Brute Force
    // Time  : O(n^3)
    // Space : O(1)
    // =====================================================

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    int countSubstringsBruteForce(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j))
                    count++;
            }
        }

        return count;
    }

    // =====================================================
    // Approach 2 : Dynamic Programming
    // Time  : O(n^2)
    // Space : O(n^2)
    // =====================================================

    int countSubstringsDP(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int count = 0;

        for (int len = 1; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (len == 1) {
                    dp[i][j] = true;
                }
                else if (len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] =
                        (s[i] == s[j] && dp[i + 1][j - 1]);
                }

                if (dp[i][j])
                    count++;
            }
        }

        return count;
    }

    // =====================================================
    // Approach 3 : Expand Around Center (Optimal)
    // Time  : O(n^2)
    // Space : O(1)
    // =====================================================

    int expand(string &s, int left, int right) {

        int count = 0;

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {

        int count = 0;

        for (int i = 0; i < s.size(); i++) {

            // Odd Length Palindrome
            count += expand(s, i, i);

            // Even Length Palindrome
            count += expand(s, i, i + 1);
        }

        return count;
    }
};
