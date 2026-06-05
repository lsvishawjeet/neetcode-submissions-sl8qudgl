class Solution {
   public:
    int calculateMaxFreqIsOf(vector<int>& vec) {
        int maxFreqIsOf = 0;
        for (int i = 1; i < 26; i++) {
            if (vec[i] > vec[maxFreqIsOf]) {
                maxFreqIsOf = i;
            }
        }
        return maxFreqIsOf;
    }
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = i;
        int n = s.length();
        int maxi = 0;
        vector<int> vec(26, 0);

        while (i < n && j<n) {
            char c = s[j];
            vec[c-'A']++;
            int maxFreqIsOf = calculateMaxFreqIsOf(vec);
            if ((j - i+1) - (vec[maxFreqIsOf]) <= k) {
                int maxLen = vec[maxFreqIsOf] + ((j - i+1) - vec[maxFreqIsOf]);
                maxi = max(maxi, maxLen);
                j++;
            } else {
                while ((j - i+1) - (vec[calculateMaxFreqIsOf(vec)]) > k) {
                    vec[s[i] - 'A']--;
                    i++;
                }
                j++;
            }
        }

        return maxi;
    }
};
