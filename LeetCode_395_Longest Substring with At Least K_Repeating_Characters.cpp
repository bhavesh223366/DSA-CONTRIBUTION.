class Solution {
public:

    // Brute Force Approach
    int longestSubstringBruteForce(string s, int k) {

        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {

                freq[s[j]]++;

                bool valid = true;

                for (auto &it : freq) {
                    if (it.second < k) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

    // Optimal Sliding Window Approach
    int longestSubstringOptimal(string s, int k) {

        int n = s.size();
        int maxLength = 0;

        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {

            unordered_map<char, int> mp;

            int left = 0;
            int right = 0;

            int unique = 0;
            int countAtLeastK = 0;

            while (right < n) {

                if (mp[s[right]] == 0)
                    unique++;

                mp[s[right]]++;

                if (mp[s[right]] == k)
                    countAtLeastK++;

                while (unique > targetUnique) {

                    if (mp[s[left]] == k)
                        countAtLeastK--;

                    mp[s[left]]--;

                    if (mp[s[left]] == 0)
                        unique--;

                    left++;
                }

                if (unique == targetUnique &&
                    unique == countAtLeastK) {

                    maxLength = max(maxLength,
                                    right - left + 1);
                }

                right++;
            }
        }

        return maxLength;
    }

    int longestSubstring(string s, int k) {

        // return longestSubstringBruteForce(s, k);
        return longestSubstringOptimal(s, k);
    }
};
