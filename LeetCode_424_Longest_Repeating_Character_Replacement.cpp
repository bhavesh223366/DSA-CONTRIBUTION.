class Solution {
public:

    // Brute Force Approach
    int characterReplacementBruteForce(string s, int k) {

        int n = s.size();
        int maxLength = 0;

        for (int i = 0; i < n; i++) {

            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {

                freq[s[j] - 'A']++;

                int maxFreq = 0;

                for (int x = 0; x < 26; x++) {
                    maxFreq = max(maxFreq, freq[x]);
                }

                int windowSize = j - i + 1;

                if (windowSize - maxFreq <= k) {
                    maxLength = max(maxLength, windowSize);
                }
            }
        }

        return maxLength;
    }

    // Optimal Sliding Window Approach
    int characterReplacementOptimal(string s, int k) {

        unordered_map<char, int> mp;

        int left = 0;
        int maxFrequency = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            maxFrequency = max(maxFrequency, mp[s[right]]);

            int windowSize = right - left + 1;

            if (windowSize - maxFrequency > k) {
                mp[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    int characterReplacement(string s, int k) {

        // return characterReplacementBruteForce(s, k);
        return characterReplacementOptimal(s, k);
    }
};
