/*
LeetCode 1903 - Largest Odd Number in String

Given a numeric string num, return the largest-valued odd
integer (as a string) that is a non-empty substring of num.

If no odd integer exists, return an empty string.

Example:
Input  : "35427"
Output : "35427"

Input  : "35420"
Output : "35"
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public {

    // ---------------- BRUTE FORCE ----------------
    string largestOddNumberBrute(string num) {

        int n = num.size();
        string ans = "";

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                string temp = num.substr(i, j - i + 1);

                int lastDigit = temp.back() - '0';

                if(lastDigit % 2 != 0) {

                    if(temp.size() > ans.size())
                        ans = temp;
                }
            }
        }

        return ans;
    }

    // ---------------- OPTIMAL ----------------
    string largestOddNumberOptimal(string num) {

        int n = num.size();

        for(int i = n - 1; i >= 0; i--) {

            if((num[i] - '0') % 2 != 0) {

                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};

int main() {

    Solution obj;

    string num = "35420";

    cout << "Input: " << num << endl;

    cout << "Brute Force Output : "
         << obj.largestOddNumberBrute(num) << endl;

    cout << "Optimal Output     : "
         << obj.largestOddNumberOptimal(num) << endl;

    return 0;
}

/*
---------------- Complexity Analysis ----------------

Brute Force:
Time Complexity  : O(n^3)
Space Complexity : O(n)

Reason:
- O(n^2) substrings
- O(n) for substring creation

Optimal:
Time Complexity  : O(n)
Space Complexity : O(1)

-----------------------------------------------------

Dry Run:

num = "35420"

i = 4 -> '0' (even)
i = 3 -> '2' (even)
i = 2 -> '4' (even)
i = 1 -> '5' (odd)

return num.substr(0, 2)

Answer = "35"

-----------------------------------------------------
*/
