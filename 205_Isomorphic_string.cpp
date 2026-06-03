#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

/*
====================================================
Approach 1: Two Hash Maps (Most Intuitive)
Time Complexity: O(n)
Space Complexity: O(1) (at most 256 characters)
====================================================
*/
class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (sToT.find(c1) != sToT.end()) {
                if (sToT[c1] != c2)
                    return false;
            } else {
                sToT[c1] = c2;
            }

            if (tToS.find(c2) != tToS.end()) {
                if (tToS[c2] != c1)
                    return false;
            } else {
                tToS[c2] = c1;
            }
        }

        return true;
    }
};


/*
====================================================
Approach 2: Two Arrays (Best Interview Approach)
Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {

        vector<int> mapS(256, -1);
        vector<int> mapT(256, -1);

        for (int i = 0; i < s.size(); i++) {

            if (mapS[s[i]] != mapT[t[i]])
                return false;

            mapS[s[i]] = i;
            mapT[t[i]] = i;
        }

        return true;
    }
};


/*
====================================================
Approach 3: Single Map + Used Characters Set
Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/
class Solution3 {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp;
        vector<bool> used(256, false);

        for (int i = 0; i < s.size(); i++) {

            char c1 = s[i];
            char c2 = t[i];

            if (mp.find(c1) != mp.end()) {

                if (mp[c1] != c2)
                    return false;

            } else {

                if (used[c2])
                    return false;

                mp[c1] = c2;
                used[c2] = true;
            }
        }

        return true;
    }
};


/*
====================================================
Approach 4: First Occurrence Pattern Matching
Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/
class Solution4 {
public:
    bool isIsomorphic(string s, string t) {

        vector<int> posS(256, -1);
        vector<int> posT(256, -1);

        for (int i = 0; i < s.size(); i++) {

            if (posS[s[i]] != posT[t[i]])
                return false;

            posS[s[i]] = i;
            posT[t[i]] = i;
        }

        return true;
    }
};


/*
====================================================
Driver Code
====================================================
*/
int main() {

    string s = "egg";
    string t = "add";

    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    Solution4 sol4;

    cout << "Approach 1 (Two Maps): "
         << sol1.isIsomorphic(s, t) << endl;

    cout << "Approach 2 (Arrays): "
         << sol2.isIsomorphic(s, t) << endl;

    cout << "Approach 3 (Single Map): "
         << sol3.isIsomorphic(s, t) << endl;

    cout << "Approach 4 (Pattern Matching): "
         << sol4.isIsomorphic(s, t) << endl;

    return 0;
}
