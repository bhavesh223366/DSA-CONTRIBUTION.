/*
LeetCode 1021 - Remove Outermost Parentheses

Given a valid parentheses string s, remove the outermost
parentheses of every primitive string.

Example:
Input  : "(()())(())"
Output : "()()()"
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    // ---------------- BRUTE FORCE ----------------
    string removeOuterParenthesesBrute(string s) {

        string ans = "";
        int start = 0;
        int balance = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(')
                balance++;
            else
                balance--;

            // Primitive string found
            if(balance == 0) {

                // Remove first and last bracket
                ans += s.substr(start + 1, i - start - 1);

                start = i + 1;
            }
        }

        return ans;
    }

    // ---------------- OPTIMAL ----------------
    string removeOuterParenthesesOptimal(string s) {

        int count = 0;
        string ans = "";

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == ')')
                count--;

            if(count != 0)
                ans.push_back(s[i]);

            if(s[i] == '(')
                count++;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "(()())(())";

    cout << "Input: " << s << endl;

    cout << "Brute Force Output : "
         << obj.removeOuterParenthesesBrute(s) << endl;

    cout << "Optimal Output     : "
         << obj.removeOuterParenthesesOptimal(s) << endl;

    return 0;
}

/*
---------------- Complexity Analysis ----------------

Brute Force:
Time Complexity  : O(n)
Space Complexity : O(n)

Optimal:
Time Complexity  : O(n)
Space Complexity : O(n)

-----------------------------------------------------

Dry Run:

Input:
s = "(()())(())"

Primitive Strings:
(()())
(())

Remove outermost parentheses:

(()()) -> ()()
(())   -> ()

Final Answer:
()()()

-----------------------------------------------------
*/
